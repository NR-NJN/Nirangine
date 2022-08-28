
#include "src/graphics/Window.h"
int main()
{
	using namespace nirangine;
	using namespace graphics;

	Window win("Nirangine", 960, 540);
	glClearColor(0.8f, 0.2f, 0.3f, 1.0f);
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!win.closed())
	{
		win.clear();
		double x, y;
		win.getMousePosition(x, y);
		std::cout << x<<"," << y << std::endl;

		
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.75f);
		glVertex2f(0.5f, -0.75f);
		glVertex2f(0.5f, 0.75f);
		glVertex2f(-0.5f, 0.75f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		win.update();
	}
	
	std::cin.get();
	return 0;
}