#include "Window.h"

namespace nirangine {
	namespace graphics {
		void windowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
		Window::Window(const char* title, int height, int width) 
		{
			m_title = title;
			m_height = height;
			m_width = width;
			if (!init())
				glfwTerminate();
		}

		Window::~Window()
		{
			glfwTerminate();
		}
		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW" << std::endl;
				return false;
			}
			
			m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
			if (!m_window)
			{
				glfwTerminate();
				std::cout << "Failed to create GLFW window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_window);
			glfwSetWindowSizeCallback(m_window, windowResize);
			return true;
		}
		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		void Window::update() 
		{
			glfwPollEvents();
			glfwGetFramebufferSize(m_window, &m_width, &m_height);
			
			glfwSwapBuffers(m_window);
		}
		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_window)==1;
		}
		
	}
}
