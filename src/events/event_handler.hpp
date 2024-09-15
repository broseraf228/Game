#pragma once
#include "../project.hpp"

#include "SFML/Graphics.hpp"

namespace bg {

	class EventHandler {
		// class needed for event handling
	public:
		// due to the simplicity of the functionality, I will make all the methods static
		
		static void handleEvents();

		// CAN BE INITED ONLY AFTER THE WINDOW
		static void Init();

	private:

		// ptr on the window
		static sf::RenderWindow* window;

		// is inited flag
		static bool isInit;
	};
}