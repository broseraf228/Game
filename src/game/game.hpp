#pragma once
#include "../math/math.hpp"

#include <memory>
#include <vector>
#include <string>
#include <map>

namespace bg {

	class GameObject;

	class Core {
		// main game class needed for update the entities/maps , set game maps and etc.
	public:
		// Singleton
		Core(Core& other) = delete;
		void operator=(const Core&) = delete;
		static Core* GetInstance();

		static int Init();
		static int Destroy();
	private:
		// Singleton instance ptr
		static Core* self;

		Core();

	//------------------------------ 
	// public game functions
	public:

		// run this method evry ingame tact (not in menu)
		void update();
		// use once
		void load();

		const std::vector< std::shared_ptr<GameObject> >& getGameObjects();
		
	// private game parameters and methods
	private:

		// array of all game objects
		std::vector< std::shared_ptr<GameObject> > m_objects;

	};
}