#include "RendererContext.h"



namespace Nut
{

	RendererContext::RendererContext(const WindowSpecification& windowSpec)
		: m_WindowSpecification(windowSpec)
	{

		m_Window = Window::Create(windowSpec);
		

	}


	auto RendererContext::SwapBuffers() -> void
	{
		m_Window->Swap(static_cast<int32_t>(m_WindowSpecification.VSync));
	}

	auto RendererContext::PollEvents() -> void
	{
		m_Window->PollEvents();
	}

}
