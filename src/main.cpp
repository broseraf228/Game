#include "app.hpp"
#include "project.hpp"

using namespace bg;
int main(int argc, char** argv)
{
    int result = 0;

    //creating the application
    result = Application::Init(argc, argv);
    if (result) {
        ELOG("can't initialise the Application\n");
        return result;
    }
    LOG("Application was initialised\n");

    //get pointer on application
    Application* app = Application::GetInstance();
    
    //start application worcking
    LOG("start the Application\n");
    result = app->Run();

    //destroy the application
    app->CleanUp();
    LOG("Application was stopped\n");

    //exit
    return result;
}