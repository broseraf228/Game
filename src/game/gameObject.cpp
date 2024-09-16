#include "gameObject.hpp"
#include "../project.hpp"


using namespace bg;

GameObject::GameObject() {
	x = 0, y = 0, s = 0;
}

std::shared_ptr<GameObject> ObjectManager::create_game_object(int x, int y, int s) {

	std::shared_ptr<GameObject> obj = std::make_shared<GameObject>( GameObject() );

	obj->x = x, obj->y = y, obj->s = s;

	return obj;
}