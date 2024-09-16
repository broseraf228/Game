#pragma once
#include <vector>
#include <memory>

namespace bg {

	class Window;
	class GameObject;

	class Screen {
		// a class for drawing game objects, interfaces, etc.
	public:
		// Singleton
		Screen(Screen& other) = delete;
		void operator=(const Screen&) = delete;
		static Screen* GetInstance();

		static int Init();
		static int Destroy();
		
		// draw game objects
		void drawObjects(const std::vector< std::shared_ptr<GameObject> > &);
		void clear();

	private:
		// Singleton instance ptr
		static Screen* self;

		Window* window = nullptr;

		Screen();
	};
}