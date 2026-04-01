#pragma once

#include "Core/Base.h"
#include "Core/Window.h"

#include <GLFW/glfw3.h>

#include <cstdint>


namespace Nut
{


	class RendererContext
	{
	public:
		RendererContext(const WindowSpecification& windowSpec);

		auto SwapBuffers() -> void;
		auto PollEvents() -> void;

		auto GetWindowHandle() -> GLFWwindow*;

	private:
		WindowSpecification m_WindowSpecification{};

		Scope<Window> m_Window{};
	};


}
