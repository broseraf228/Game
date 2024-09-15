#include "event_handler.hpp"

#include "../visual/window.hpp"
#include "../app.hpp"

using namespace bg;

sf::RenderWindow* EventHandler::window = nullptr;
bool EventHandler::isInit = false;

void EventHandler::Init() {
	window = bg::Window::GetInstance();
	if (window == nullptr) {
		//if window is not inited
		ELOG("The window was not inited");
		return;
	}
	isInit = true;
}

void EventHandler::handleEvents() {

	if (!isInit) {
		//if not inited
		ELOG("Event Handler called before initialisation");
		return;
	}


	static sf::Event event;
	//                                  EVENTS HANDLING 
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			// "close requested" event: we close the window
			Application::stop();
	}
}
