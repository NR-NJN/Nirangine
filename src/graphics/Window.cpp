#include "Window.h"

namespace nirangine {
	namespace graphics {
		
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		void cursor_postion_callback(GLFWwindow* window, double xpos, double ypos);
		//help
		
		
		void window_resize(GLFWwindow* window, int width, int height);
		 
		Window::Window(const char* title, int height, int width) 
		{
			m_title = title;
			m_height = height;
			m_width = width;
			if (!init())
				glfwTerminate();
			for (int i=0;i<MAX_KEYS; i++)
			{
				m_keys[i] = false;
			}
			for (int i = 0; i < MAX_MOUSE; i++)
			{
				m_MouseButton[i] = false;
			}
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
			glfwSetWindowUserPointer(m_window, this);
			glfwSetWindowSizeCallback(m_window, window_resize);
			glfwSetKeyCallback(m_window, key_callback);
			glfwSetMouseButtonCallback(m_window, mouse_button_callback);
			glfwSetCursorPosCallback(m_window, cursor_postion_callback);
			if (glewInit() != GLEW_OK)
			{
				std::cout << "Failed to initialize GLEW" << std::endl;
				return false;
			}
			return true;
		}
		bool Window::isKeyPressed(unsigned int keycode) const
		{	
			if (keycode >= MAX_KEYS)
				return false;
			return m_keys[keycode];
		}
		bool Window::isMouseButtonPressed(unsigned int button) const
		{
			if (button >= MAX_MOUSE)
				return false;
			return m_MouseButton[button];
		}
		void Window::getMousePosition(double& x, double& y) const
		{
			x = mx;
			y = my;
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
		void window_resize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* whin= (Window*)glfwGetWindowUserPointer(window);
			
			whin->m_keys[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			 Window* whin = (Window*)glfwGetWindowUserPointer(window);
			  whin->m_MouseButton[button] = action != GLFW_RELEASE;
		}

		void cursor_postion_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* whin = (Window*)glfwGetWindowUserPointer(window);
			whin->mx = xpos;
			whin->my = ypos;
		}
	}
}
