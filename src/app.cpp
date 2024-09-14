#include "app.hpp"

#include <iostream>

using namespace bg;

Application* Application::self = nullptr;
int exit_code = 0;

Application* Application::GetInstance() {
	if (self == nullptr) {
		// application was not initialise
	}
	return self;
}

int Application::Init(int argc, char** argv) {
	if (self != nullptr) {
		// application was initialised earlier
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
	int lifetime = 0;
	while (lifetime++ < 100) {
		std::cout << lifetime << std::endl;
	}
	return 0;
}
