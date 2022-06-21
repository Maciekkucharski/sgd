//
// Created by Maciek on 21.06.2022.
//

#include "GameLoop.h"




GameLoop::GameLoop() {
    window = NULL;
    renderer = NULL;

    state = false;

}

void GameLoop::Initialize() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
    } else {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            std::cout << "Renderer created!\n";
            state = true;
        } else {
            std::cout << "Renderer couldn't be created! SDL_Error\n" << SDL_GetError() << std::endl;
        }
    }
}

void GameLoop::Event(){
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT){
        state = false;
    }
}

void GameLoop::Renderer() {
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void GameLoop::Clear() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

bool GameLoop::getState(){
    return state;
}