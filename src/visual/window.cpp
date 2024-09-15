#include "window.hpp"
#include "../project.hpp"

using namespace bg;

Window* Window::self = nullptr;

int Window::Init() {

	self = new Window();

	DLOG("Window was created");

	return 0;
}

void Window::Destroy() {

	if (self == nullptr) {
		DLOG("Window double destroy");
		return;
	}

	delete self;
	DLOG("Window was destroyed");
}

Window* Window::GetInstance() {

	if ( self == nullptr)
		DLOG("Window called before initialisation");

	return self;

}

Window::Window() :
	sf::RenderWindow(sf::VideoMode(800,600), "title")
{

}
Window::~Window()
{

}