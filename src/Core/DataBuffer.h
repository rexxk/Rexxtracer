#pragma once


#include <cstdint>
#include <vector>



namespace Nut
{


	class DataBuffer
	{
	public:
		DataBuffer(void* data, std::size_t size);
		DataBuffer(DataBuffer&& other) noexcept;
		virtual ~DataBuffer();

		auto Size() -> const std::size_t { return m_Data.size(); }
		auto Data() -> auto { return m_Data; }

	private:
		std::vector<std::byte> m_Data{};

	};


}
