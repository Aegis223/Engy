#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace engy { namespace graphics {

	class Window
	{
	private:
		int m_Width, m_Height;
		const char* m_Title;
		GLFWwindow* m_Window;

		double m_X, m_Y;
		bool m_Keys[MAX_KEYS];
		bool m_Buttons[MAX_BUTTONS];
	public:
		Window();
		Window(int width, int height, const char* title);

		~Window();

		void getCursorPos(double &x, double &y);
		bool isKeyPressed(int key) const;
		bool isButtonPressed(int button) const;

		bool closed() const;
		void clear() const;
		void update();
	private:
		bool init();
		friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
		friend void resize_callback(GLFWwindow* window, int width, int height);
	};
} }