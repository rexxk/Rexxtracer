#include "Core/Window.h"
#include "Event/EventHandler.h"
#include "Renderer/RendererContext.h"

#include <print>


using namespace Nut;


int main()
{
	std::println("Rexxtrace 2026");

	bool isRunning{ true };

	WindowSpecification windowSpec{
		.Width = 1280,
		.Height = 720,
		.Fullscreen = false,
		.VSync = false,
		.Title = "Rexxtrace 2026"
	};

	RendererContext rendererContext(windowSpec);

	EventHandler::Subscribe(EventType::WindowClose, [&](Ref<Event> e)
		{
			Ref<WindowClosedEvent> event = std::dynamic_pointer_cast<WindowClosedEvent>(e);
			isRunning = false;
		});

	while (isRunning)
	{
		rendererContext.PollEvents();
		EventHandler::Poll();
	}


	return 0;
}
