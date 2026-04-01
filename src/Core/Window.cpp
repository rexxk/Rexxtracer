#include "Core/Window.h"

#include "Core/Base.h"
#include "Core/Log.h"

#include "Event/EventHandler.h"


namespace Nut
{

	auto Window::Create(const WindowSpecification& windowSpec) -> Scope<Window>
	{
		return CreateScope<Window>(windowSpec);
	}


	Window::Window(const WindowSpecification& windowSpec)
	{
		LOG_CORE_TRACE("Initializing window");

		if (glfwInit() == GLFW_FALSE)
		{
			LOG_CORE_ERROR("Failed to initialize glfw");
			return;
		}

		glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
		glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_WindowPointer = glfwCreateWindow(windowSpec.Width, windowSpec.Height, windowSpec.Title.c_str(), nullptr, nullptr);

		if (windowSpec.Fullscreen)
		{
			glfwMaximizeWindow(m_WindowPointer);
		}

		glfwMakeContextCurrent(m_WindowPointer);
		glfwShowWindow(m_WindowPointer);

		gladLoadGL();

		glfwSetWindowCloseCallback(m_WindowPointer, [](GLFWwindow* window)
			{
				Ref<WindowClosedEvent> event = CreateRef<WindowClosedEvent>();
				EventHandler::AddEvent(event);
			});

		glfwSetWindowSizeCallback(m_WindowPointer, [](GLFWwindow* window, std::int32_t width, std::int32_t height)
			{
				Ref<WindowResizedEvent> event = CreateRef<WindowResizedEvent>(width, height);
				EventHandler::AddEvent(event);
			});
	}

	Window::~Window()
	{
		glfwMakeContextCurrent(nullptr);

		glfwDestroyWindow(m_WindowPointer);
	}

	auto Window::PollEvents() -> void
	{
		glfwPollEvents();
	}

	auto Window::Swap(int32_t vSync) -> void
	{
		glfwSwapInterval(vSync);
		glfwSwapBuffers(m_WindowPointer);
	}

}
