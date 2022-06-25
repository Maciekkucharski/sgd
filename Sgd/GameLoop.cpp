#include "Gameloop.h"


GameLoop::GameLoop() {
    window = NULL;
    renderer = NULL;
    state = false;
    b.setSrc(0, 0, 85, 120);
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
            b.CreateTexture("images/bird.png", renderer);
            bg.CreateTexture("images/background.webp", renderer);
        }
        else {
            std::cout << "Renderer couldn't be created! SDL_Error\n" << SDL_GetError() << std::endl;
        }
    }
}


void GameLoop::Update(){
    b.Update();
}

void GameLoop::Event() {

    b.getJumpTime();
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        state = false;
    }
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_UP) {
            if (!b.getJumping()) {     
                b.Jump(); 
            }
            else {
                b.Gravity();
            }  
        }
    }
    else {
        b.Gravity();
    }
}

void GameLoop::Renderer() {
    SDL_RenderClear(renderer);
    bg.Render(renderer);
    b.Render(renderer);
    SDL_RenderPresent(renderer);
}

void GameLoop::Clear() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

bool GameLoop::getState() {
    return state;
}