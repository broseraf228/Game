#include "app.hpp"
#include "project.hpp"

#include "SFML/Graphics.hpp"

#include "visual/window.hpp"
#include "visual/screen.hpp"
#include "events/event_handler.hpp"
#include "game/game.hpp"
#include "game/gameObject.hpp"

#include <string>


using namespace bg;

Application* Application::self = nullptr;
bool Application::isRun = false;
int exit_code = 0;

Application* Application::GetInstance() {
	if (self == nullptr) {
		ELOG("Application called before initialisation");
	}
	return self;
}

int Application::Init(int argc, char** argv) {
	if (self != nullptr) {
		ELOG("Application double initialisation");
		return 1;
	}
	self = new Application(argc, argv);

	return exit_code;
}
void Application::CleanUp() {
	if (self == nullptr) {
		// application was not initialise
		return;
	}
	delete self;
	return;
}

Application::Application(int argc, char** argv) {
	exit_code = 0;
}
Application::~Application() {

}

int Application::Run() {
	// store exit code here
	int result = 0;

	// load function (load the textures, sounds and other prepare things)
	result = load();
	if (result) {
		ELOG("application load fail | exit code " << result);
	}

	// game loop
	isRun = true;
	while (isRun) { 

		if (preUpdate()) {
			// error on pre update phase
			ELOG("application pre update fail");
		}
		if (update()) {
			// error on pre update phase
			ELOG("application pre update fail");
		}
		if (postUpdate()) {
			// error on pre update phase
			ELOG("application pre update fail");
		}
	}

	// cleanup game
	cleanup();

	return result;
}

void Application::stop() {
	isRun = false;
}


////////////////////////////////////////////////////////////////////////
// WRITE CODE BOTTOM
////////////////////////////////////////////////////////////////////////

int Application::load() {

	Time::self.deltaTime = 1.0 / 120;

	// initialize programm components
	Core::Init();

	Window::Init();
	Screen::Init();
	EventHandler::Init();

	// prepare game
	Core::GetInstance()->load();

	return 0;
}

int Application::preUpdate() {

	// timer that counts the running time
	static sf::Clock clock;
	Time::self.time = clock.getElapsedTime().asSeconds();

	return 0;
}
int Application::update() {

	// draw objects
	Screen::GetInstance()->drawObjects(Core::GetInstance()->getGameObjects());
	
	// handle events
	EventHandler::handleEvents();

	// update the game
	Core::GetInstance()->update();

	// clear the screen
	Screen::GetInstance()->clear();

	return 0;
}
int Application::postUpdate() {

	static sf::Clock clock;
	clock.restart();
	Time::self.frameTime = clock.getElapsedTime().asSeconds();

	Window::GetInstance()->setTitle(std::to_string( Time::self.frameTime ));

	return 0;
}
int Application::cleanup() {

	Screen::Destroy();
	Window::Destroy();
	Core::Destroy();

	return 0;
}
