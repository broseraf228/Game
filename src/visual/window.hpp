#pragma once

#include "SFML/Graphics.hpp"

namespace bg {
	
	class Window : public sf::RenderWindow {
		// singleton sf::Window 
	public:
		// Singleton
		Window(Window& other) = delete;
		void operator=(const Window&) = delete;
		static Window* GetInstance();

		static int Init();
		static void Destroy();
	private:
		// Singleton instance ptr
		static Window* self;

		Window();
		~Window();
	};
}