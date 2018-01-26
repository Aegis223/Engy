#pragma once

#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#define MAX_KEYS 1024 //MAX NUMBER OF GLFW KEYBOARD KEYCODES PLUS PADDING
#define MAX_BUTTONS 32 //MAX NUMBER OF GLFW MOUSE BUTTON KEYCODES PLUS PADDING

namespace engy { namespace graphics {
		
		/* ! GLFW Window wrapper object.
			* const char* m_Title; PR
			* int m_Width, m_Height; PR
			* GLFWwindow* m_Window; PR
			* double m_X, m_Y; PR
			* bool m_Keys[@MAX_KEYS]; PR
			* bool m_Buttons[@MAX_BUTTONS]; PR
			*@Window(); PU
			*@Window(int, width, int height, const char* title); PU
			*@~Window(); PU
			*@void getMousePos(double &x, double&y); PU
			*@isKeyPressed(int key) const; PU
			*@isMbuttonPressed(int button) const; PU
			*@bool closed() const; PU
			*@void clear() const; PU
			*@void update(); PU
			*@bool init(); PR
			*@friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods); PR
			*@friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods); PR
			*@friend void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos); PR
		*/
		class Window{
		private:
			const char* m_Title;			//Character pointer holding the GLFW window title.
			int m_Width, m_Height;			//Width and Height of the GLFW window.

			GLFWwindow* m_Window;			//The container for the GLFW window; GLFWwindw*.

			double m_X, m_Y;				//X and Y pos(double) for the cursor position relative to the GLFW window.
			bool m_Keys[MAX_KEYS];			//Boolean container of the maximum number of GLFW keyboard int based keycode plus extra padding.
			bool m_Buttons[MAX_BUTTONS];	//Boolean container of the maximum number of GLFW MouseButton int based codes plus extra pudding.
		public:
			Window();													//Default class constructor
			Window(int width, int height, const char* title);			//Overloaded class constructor(int width, int height, const char* title)

			~Window();													//Default destructor

			void getMousePos(double &x, double &y);						//Takes two double params as reference to modify and set to the cursor position in GLFW window.
			bool isKeyPressed(int key) const;							//Returns the bool value of the bool array of m_Keys at int key.
			bool isMbuttonPressed(int button) const;					//Return the bool value of the bool array of m_Buttons at int button.

			bool closed() const;										//Checks PollEvents as well as GLFW Window events and returns the status of the quit() event.
			void clear() const;											//glClear() clears both the BUFFER_BIT and DEPTH_BIT.
			void update();												//Swaps current buffers then Polls current evens.
		private:
			bool init();
			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend void mouse_pos_callback(GLFWwindow* window, double xpos, double ypos);
			friend void resize_callback(GLFWwindow* window, int width, int height);
		};
	}
}