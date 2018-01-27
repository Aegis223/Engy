#include "src/graphics/Window.h"
#include "src/maths/Maths.h"

using namespace engy;
using namespace maths;
using namespace graphics;

int main(int argc, char* args[])
{
	Window* u_Window = new Window(640, 480, "TEST");

	glClearColor(0.0f, 0.5f, 0.5f, 1.0f);

	while(!u_Window->closed())
	{
		u_Window->clear();

		glBegin(GL_QUADS);
			glVertex2f(-0.5f, -0.5f);
			glVertex2f( 0.5f, -0.5f);
			glVertex2f( 0.5f,  0.5f);
			glVertex2f(-0.5f,  0.5f);
		glEnd();

		u_Window->update();
	}

	return 0;
}