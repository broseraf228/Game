#include "app.hpp"

#include <iostream>


using namespace bg;
int main(int argc, char** argv)
{
    int result = 0;

    //creating the application
    result = Application::Init(argc, argv);
    if (result) {
        //can't create the application
        return result;
    }

    //get pointer on application
    Application* app = Application::GetInstance();
    
    //start application worcking
    result = app->Run();

    //destroy the application
    app->CleanUp();

    //exit
    return result;
}