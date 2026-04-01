#pragma once

#include <GLFW/glfw3.h>


namespace Nut
{

	class UIContext
	{
	public:
		UIContext(GLFWwindow* window);
		virtual ~UIContext();

		auto NewFrame() -> void;
		auto Render() -> void;
	};

}
