#include "app.hpp"
#include "project.hpp"

using namespace bg;
int main(int argc, char** argv)
{
    int result = 0;

    //creating the application
    result = Application::Init(argc, argv);
    if (result) {
        ELOG("can't initialise the Application");
        return result;
    }
    DLOG("Application was initialised");

    //get pointer on application
    Application* app = Application::GetInstance();
    
    //start application worcking
    DLOG("start the Application");
    result = app->Run();

    //destroy the application
    app->CleanUp();
    DLOG("stop the Application");

    //exit
    return result;
}