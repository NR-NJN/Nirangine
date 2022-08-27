#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
namespace nirangine {
	namespace graphics {
		class Window {
		private:
			const char* m_title;
			int m_height, m_width;
			GLFWwindow* m_window;
			bool m_closed;
		public:
			Window(const char* title, int height, int width);
			~Window();
			bool closed() const;
			void update() ;
			void clear() const;
			inline int getWidth() const { return m_width; }
			inline int getHeight() const { return m_height; }
		private: 
			bool init();
			
		};
	}
}