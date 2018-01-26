#include <iostream>

#include "src/graphics/Window.h"

using namespace engy;
using namespace graphics;

int main(int argc, char* args[]) 
{
	Window* u_Window = new Window(1280, 720, "TEST");

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	while (!u_Window->closed()) {
		u_Window->clear();

		u_Window->update();
	}

	delete u_Window;

	return 0;
}