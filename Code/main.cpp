
#include "Code/Core/Application.h"
#include "Code/Pong/Pong.h"

//int main(int, char const**)
//{
//    EMILY::Application* application = new EMILY::Application();
//
//    application->initialise();
//
//    while( application->run() )
//    {
//        application->process_events();
//        application->update();
//        application->display();
//    }
//
//    application->shutdown();
//
//    return EXIT_SUCCESS;
//}

int main( int, char const** )
{
    Pong* game = new Pong();
    game->initialise();
    
    while( game->run() )
    {
        game->process_events();
        game->update();
        game->clear();
        game->display();
    }
    
    game->shutdown();
    
    return EXIT_SUCCESS;
}
