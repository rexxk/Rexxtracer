#pragma once

#include "Core/Base.h"
#include "Core/Window.h"

#include <cstdint>


namespace Nut
{


	class RendererContext
	{
	public:
		RendererContext(const WindowSpecification& windowSpec);

		auto SwapBuffers() -> void;
		auto PollEvents() -> void;

	private:
		WindowSpecification m_WindowSpecification{};

		Scope<Window> m_Window{};
	};


}
