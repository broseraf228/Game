#include "game.hpp"

#include "../project.hpp"

#include "gameObject.hpp"

using namespace bg;

Core* Core::self = nullptr;

Core* Core::GetInstance() {
	if (self == nullptr) {
		ELOG("Core called before initialisation");
	}
	return self;
}

int Core::Init() {
	if (self != nullptr) {
		ELOG("Core double initialisation");
		return 1;
	}
	self = new Core();
	DLOG("Core was created");

	return 0;
}
int Core::Destroy() {
	DLOG("Core was destroyed");
	return 0;
}

Core::Core() {

}

const std::vector< std::shared_ptr<GameObject> >& Core::getGameObjects() {
	return m_objects;
}

void Core::load()
{
	m_objects.push_back(ObjectManager::create_game_object(50, 100, 20));
}

void Core::update() 
{

}