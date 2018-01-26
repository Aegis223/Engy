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
		return (1 == glfwWindowShouldClose(m_Window));
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

	void Window::getCursorPos(double &x, double &y)
	{
		x = m_X;
		y = m_Y;
	}

	bool Window::isKeyPressed(int key) const
	{
		return m_Keys[key];
	}

	bool Window::isButtonPressed(int button) const
	{
		return m_Buttons[button];
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		win->m_Keys[key] = action != GLFW_RELEASE;
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		win->m_Buttons[button] = action != GLFW_RELEASE;
	}
	void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);

		win->m_X = xpos;
		win->m_Y = ypos;
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
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_pos_callback);
		glfwMakeContextCurrent(m_Window);
		glfwSwapInterval(1);

		std::cout << "OpenGL" << glGetString(GL_VERSION) << std::endl;

		return 1;
	}
} }