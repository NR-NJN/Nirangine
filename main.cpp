
#include "src/graphics/Window.h"
int main()
{
	using namespace nirangine;
	using namespace graphics;

	Window win("Nirangine", 960, 540);
	glClearColor(0.8f, 0.2f, 0.3f, 1.0f);

	while (!win.closed())
	{
		win.clear();
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.75f);
		glVertex2f(0.5f, -0.75f);
		glVertex2f(0.5f, 0.75f);
		glVertex2f(-0.5f, 0.75f);
		glEnd();
		win.update();
	}
	
	std::cin.get();
	return 0;
}