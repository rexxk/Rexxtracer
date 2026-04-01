#include "Core/Window.h"
#include "Event/EventHandler.h"
#include "Renderer/RendererContext.h"
#include "UI/UIContext.h"

#include <glad/glad.h>

#include <print>

#include <imgui.h>


using namespace Nut;


int main()
{
	std::println("Rexxtracer 2026");

	bool isRunning{ true };

	WindowSpecification windowSpec{
		.Width = 1280,
		.Height = 720,
		.Fullscreen = true,
		.VSync = false,
		.Title = "Rexxtracer 2026"
	};

	RendererContext rendererContext(windowSpec);

	UIContext uiContext{rendererContext.GetWindowHandle()};

	EventHandler::Subscribe(EventType::WindowClose, [&](Ref<Event> e)
		{
			Ref<WindowClosedEvent> event = std::dynamic_pointer_cast<WindowClosedEvent>(e);
			isRunning = false;
		});

	while (isRunning)
	{
		rendererContext.PollEvents();
		EventHandler::Poll();

		glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		uiContext.NewFrame();

		ImGui::ShowDemoWindow();

		uiContext.Render();

		rendererContext.SwapBuffers();
	}


	return 0;
}
