#include "Window.h"

namespace engy { namespace graphics {

	Window::Window() 
	{
		m_Width = 640;
		m_Height = 480;
		m_Title = "DEFAULT";

		if (!init())
			std::cout << "ERROR: Window class failed to initialize." << std::endl;
	}

	Window::Window(int width, int height, const char* title) 
	{
		m_Width = width;
		m_Height = height;
		m_Title = title;

		if (!init())
			std::cout << "ERROR: Window class failed to initialize." << std::endl;
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window);
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void resize_callback(GLFWwindow* window, int width, int height)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		win->m_Width = width;
		win->m_Height = height;

		glViewport(0, 0, width, height);
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "ERROR: GLFW failed to initialize." << std::endl;
			return 0;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

		if (!m_Window)
		{
			std::cout << "ERROR: GLFW Window could not be constructed." << std::endl;
			return 0;
		}

		glfwSetWindowUserPointer(m_Window, this);
		glfwSetFramebufferSizeCallback(m_Window, resize_callback);
		glfwMakeContextCurrent(m_Window);
		glfwSwapInterval(1);

		std::cout << "OpenGL" << glGetString(GL_VERSION) << std::endl;

		return 1;
	}
} }