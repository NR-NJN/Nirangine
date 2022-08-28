#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
namespace nirangine {
	namespace graphics {
#define MAX_KEYS 1024
#define MAX_MOUSE 32
		class Window 
		{
		private:
			const char* m_title;
			int m_height, m_width;
			GLFWwindow* m_window;
			bool m_closed;
			
		    bool m_keys[MAX_KEYS];
			bool m_MouseButton[MAX_MOUSE];
		    
		    double mx, my;
		public:
			Window(const char* title, int height, int width);
			~Window();
			bool closed() const;
			void update() ;
			void clear() const;
			
			inline int getWidth() const { return m_width; }
			inline int getHeight() const { return m_height; }
			
			bool isKeyPressed(unsigned int keycode) const;
			bool isMouseButtonPressed(unsigned int button) const;
			void getMousePosition(double& x, double& y) const;
		private: 
			bool init();
			friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);	
			friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend static void cursor_postion_callback(GLFWwindow* window, double xpos, double ypos);
		};
	}
}
