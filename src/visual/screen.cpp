#include "screen.hpp"
#include "../project.hpp"

#include "window.hpp"
#include "../game/gameObject.hpp"

#include "SFML/Graphics.hpp"


using namespace bg;

Screen* Screen::self = nullptr;

Screen* Screen::GetInstance() {
	if (self == nullptr) {
		ELOG("Screen called before initialisation");
	}
	return self;
}

int Screen::Init() {
	if (self != nullptr) {
		ELOG("Screen double initialisation");
		return 1;
	}
	self = new Screen();
	DLOG("screen was created");

	return 0;
}
int Screen::Destroy(){
	DLOG("screen was destroyed");
	return 0;
}

Screen::Screen() {
	window = Window::GetInstance();
	if (window == nullptr) {
		ELOG("screen initialisate before window");
	}
}

void Screen::drawObjects(const std::vector< std::shared_ptr<GameObject> >& objects) {

	sf::CircleShape shape;
	shape.setFillColor(sf::Color::Red);
	for (auto item : objects) {

		shape.setOrigin(item->s*0.5, item->s * 0.5);
		shape.setPosition(item->x, item->y);
		shape.setRadius(item->s);

		window->draw(shape);

	}
}

void Screen::clear() {
	window->display();
	window->clear(sf::Color::Black);
}