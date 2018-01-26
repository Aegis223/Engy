#include "Window.h"

namespace engy { namespace graphics {

		Window::Window() 
		{
			m_Title = "DEFAULT";
			m_Width = 640;
			m_Height = 480;

			if (!init()) 
			{
				std::cout << "Error: Failed to initialize Window class." << std::endl;
			}
		}

		Window::Window(int width, int height, const char* title) 
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;

			if (!init()) 
			{
				std::cout << "Error: Failed to initialize Window class." << std::endl;
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)			//glfwSetKeyCallback(GLFWwindow* window, @key_callback) <- function also assigns the GLFW window, key, scancode, action, and modifiers to params
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);								//Retrieves and sets a referenced pointer of a Window class so that member functions can be accessed in callback. 
																									//NOTE glfwGetWindowUserPointer is returned as void* so we must cast it into a (Window*)
			win->m_Keys[key] = action != GLFW_RELEASE;												//Access m_Keys via pointer and sets bool at index the current key equal to (bool)(action != GLFW_RELEASE)
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)			
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);

			win->m_Buttons[button] = action != GLFW_RELEASE;
		}

		void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);

			win->m_X = xpos;																		//Instead of a bool array we simply set m_X &
			win->m_Y = ypos;																		//m_Y equal to their retrieved values.
		}

		void Window::getMousePos(double &x, double &y)
		{
			x = m_X;
			y = m_Y;
		}

		bool Window::isKeyPressed(int key) const
		{
			return m_Keys[key];
		}

		bool Window::isMbuttonPressed(int button) const
		{
			return m_Buttons[button];
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

		bool Window::init() 
		{
			if (!glfwInit()) 
			{
				std::cout << "Error: GLFW failed to initialize." << std::endl;
				return 0;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

			if (!m_Window) 
			{
				std::cout << "Error: GLFW Window failed to be created." << std::endl;
				return 0;
			}

			memset(m_Keys, 0, MAX_KEYS * sizeof(bool));
			memset(m_Buttons, 0, MAX_BUTTONS * sizeof(bool));

			glfwMakeContextCurrent(m_Window);											/////////////////////////////////////////////////////////////////
			glfwSetWindowUserPointer(m_Window, this);									//															   //
			glfwSetKeyCallback(m_Window, key_callback);									// We set our callback's to their respective calling function. //
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);				//	    These functions are predefined in the GLFW Library     //
			glfwSetCursorPosCallback(m_Window, mouse_pos_callback);						/////////////////////////////////////////////////////////////////
			glfwSwapInterval(1);	//This defines how often we swap our buffers in the update function

			return 1;
		}
	}
}