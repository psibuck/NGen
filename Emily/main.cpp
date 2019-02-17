
#include "Code/Application.h"

int main(int, char const**)
{
    EMILY::Application* application = new EMILY::Application();
    
    application->initialise();
    
    while( application->run() )
    {
        application->process_events();
        application->update();
        application->display();
    }
    
    application->shutdown();
    
    return EXIT_SUCCESS;
}

