#pragma once

#include <memory>

namespace bg {

	class GameObject {
	public:
		// i am not recommended use constructor, better use fabric method
		GameObject();

		//game object parameters
		int x, y, s;
	};
	

	class ObjectManager {
	public:
		// factory method
		static std::shared_ptr<GameObject> create_game_object(int, int, int);
	};
}