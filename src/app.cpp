#include "app.hpp"
#include "project.hpp"

#include "visual/window.hpp"
#include "events/event_handler.hpp"


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

	TimeStruct::self.time = 1 / 120;

	Window::Init();
	EventHandler::Init();

	return 0;
}

int Application::preUpdate() {
	return 0;
}
int Application::update() {

	EventHandler::handleEvents();

	return 0;
}
int Application::postUpdate() {
	return 0;
}
int Application::cleanup() {

	Window::Destroy();

	return 0;
}
