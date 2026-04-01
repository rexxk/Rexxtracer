#include "Core/DataBuffer.h"

#include <ranges>
#include <utility>


namespace Nut
{


	DataBuffer::DataBuffer(void* data, std::size_t size)
	{
		m_Data.resize(size);

		std::memcpy(m_Data.data(), data, size);
	}

	DataBuffer::DataBuffer(DataBuffer&& other) noexcept
	{
		m_Data = std::move(other.m_Data);
	}

	DataBuffer::~DataBuffer()
	{

	}

}
