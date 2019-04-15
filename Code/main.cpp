
#include "Code/Core/Application.h"
#include "Pong/Pong.h"
#include "Tennis/Tennis.h"

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
    //Pong* game = new Pong();
    Tennis* game = new Tennis();
    
    game->initialise();
    
    while( game->run() )
    {
        game->process_events();
        game->update();
        game->clear();
        game->display();
    }
    
    game->shutdown();
    
    delete game;
    
    return EXIT_SUCCESS;
}
