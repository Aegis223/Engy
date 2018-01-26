#include <iostream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

int main(int argc, char* args[]) 
{
	if (!glfwInit())
		std::cout << "Error: GLFW could not initialize." << std::endl;

	system("pause");

	return 0;
}