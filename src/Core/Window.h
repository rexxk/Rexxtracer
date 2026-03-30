#pragma once

#include "Core/Base.h"

#include <GLFW/glfw3.h>

#include <cstdint>
#include <string>



namespace Nut
{

	struct WindowSpecification
	{
		std::uint16_t Width{};
		std::uint16_t Height{};
		bool Fullscreen{ false };
		bool VSync{ false };

		std::string Title{"<Title>"};
	};


	class Window
	{
	public:
		static auto Create(const WindowSpecification& windowSpec) -> Scope<Window>;

		Window(const WindowSpecification& windowSpec);
		virtual ~Window();

		auto PollEvents() -> void;
		auto Swap(int32_t vSync) -> void;

	private:
		GLFWwindow* m_WindowPointer{};
	};


}
