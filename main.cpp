#include <SDL.h>
#include <iostream>
#include "GameLoop.h"
#include<SDL_image.h>


GameLoop *g = new GameLoop();  //pointer to gameloop class to access function

int main(int argc, char *argv[]) {
    g->Initialize();
    while (g->getState()){
        g->Renderer();
        g->Event();
    }
    g->Clear();

    return 0;
}




























//#include <SDL.h>
//#include <iostream>
//
////Screen dimension constants
//const int SCREEN_WIDTH = 1920;
//const int SCREEN_HEIGHT = 1080;
//
//int main(int argc, char* argv[]) {
//    //The window we'll be rendering to
//    SDL_Window* window = NULL;
//
//    //The surface contained by the window
//    SDL_Surface* screenSurface = NULL;
//
//    //Initialize SDL
//    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
//        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
//    }
//    else
//    {
//        //Create window
//        window = SDL_CreateWindow( "SDL Tutorial - Hello SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
//        if( window == NULL ) {
//            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
//        }
//        else {
//            //Get window surface
//            screenSurface = SDL_GetWindowSurface( window );
//
//            //Fill the surface white
//            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x33, 0xFF, 0x33 ) );
//
//            //Update the surface
//            SDL_UpdateWindowSurface( window );
//
//            //Wait two seconds
//            SDL_Delay( 2000 );
//        }
//    }
//
//    //Destroy window
//    SDL_DestroyWindow( window );
//
//    //Quit SDL subsystems
//    SDL_Quit();
//
//    return 0;
//}
