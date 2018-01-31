#include <iostream>

#include "src/graphics/Window.h"
#include "src/maths/Maths.h"

using namespace engy;
using namespace graphics;
using namespace maths;

int main(int argc, char* args[]) 
{
	Window* u_Window = new Window(1280, 720, "TEST");

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	vec2 a(2.0f, 3.0f);
	vec2 b(3.0f, 2.0f);

	std::cout << a.add(b) << std::endl;
	std::cout << b << std::endl;

	while (!u_Window->closed()) {
		u_Window->clear();

		glBegin(GL_QUADS);
			glVertex2f(-0.5, -0.5);
			glVertex2f( 0.5, -0.5);
			glVertex2f( 0.5,  0.5);
			glVertex2f(-0.5,  0.5);
		glEnd();

		u_Window->update();
	}

	delete u_Window;

	return 0;
}