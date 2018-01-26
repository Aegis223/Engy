#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace engy { namespace graphics {

	class Window
	{
	private:
		int m_Width, m_Height;
		const char* m_Title;
		GLFWwindow* m_Window;
	public:
		Window();
		Window(int width, int height, const char* title);

		~Window();

		bool closed() const;
		void clear() const;
		void update();
	private:
		bool init();
		friend void resize_callback(GLFWwindow* window, int width, int height);
	};
} }