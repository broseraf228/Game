#pragma once

namespace bg {

	class Window;

	class Application {

	public:
		// Singleton
		Application(Application& other) = delete;
		void operator=(const Application&) = delete;
		static Application* GetInstance();

		// Application lifetime methods
		static int Init(int argc, char** argv);
		int Run();
		static void CleanUp();

		static void stop();

	private:
		// Singleton instance ptr
		static Application* self;

		// Constructor and destructor
		Application(int argc, char** argv);
		~Application();

		//application running status
		static bool isRun;
		//private lifetime methods
		int load();
		int preUpdate();
		int update();
		int postUpdate();
		int cleanup();
	};
}