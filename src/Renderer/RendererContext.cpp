#include "RendererContext.h"

#include "Core/Base.h"
#include "Event/EventHandler.h"


namespace Nut
{

	RendererContext::RendererContext(const WindowSpecification& windowSpec)
		: m_WindowSpecification(windowSpec)
	{

		m_Window = Window::Create(windowSpec);
		

		EventHandler::Subscribe(EventType::WindowSize, [&](Ref<Event> e)
			{
				Ref<WindowResizedEvent> event = std::dynamic_pointer_cast<WindowResizedEvent>(e);

				m_WindowSpecification.Width = event->Width();
				m_WindowSpecification.Height = event->Height();
			});
	}


	auto RendererContext::SwapBuffers() -> void
	{
		m_Window->Swap(static_cast<int32_t>(m_WindowSpecification.VSync));
	}

	auto RendererContext::PollEvents() -> void
	{
		m_Window->PollEvents();
	}

	auto RendererContext::GetWindowHandle() -> GLFWwindow*
	{
		return m_Window->GetHandle();
	}

}
