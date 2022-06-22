#include "Gameloop.h"


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
    }
    else {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            std::cout << "Renderer created!\n";
            state = true;
            bird = TextureMenager::Texture("images/bird.png", renderer);
            background = TextureMenager::Texture("images/background.webp", renderer);
        }
        else {
            std::cout << "Renderer couldn't be created! SDL_Error\n" << SDL_GetError() << std::endl;
        }
    }
}


void GameLoop::Update(){
    srcBird.w = 120;
    srcBird.h = 85;
    srcBird.x = 0;
    srcBird.y = 0;

    destBird.w = 120;
    destBird.h = 85;
    destBird.x = 10;
    destBird.y = 10;
}

void GameLoop::Event() {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        state = false;
    }
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        std::cout << "click\n";
    }
    if (event.type == SDL_KEYDOWN) {
        std::cout << "click keyboard\n";
    }
}

void GameLoop::Renderer() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_RenderCopy(renderer, bird, &srcBird, &destBird);
    SDL_RenderPresent(renderer);
}

void GameLoop::Clear() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

bool GameLoop::getState() {
    return state;
}