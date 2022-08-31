#include "Gameloop.h"


GameLoop::GameLoop() {
    window = NULL;
    renderer = NULL;
    state = false;
    b.setSrc(0, 0, 85, 120);
    brT.setDest(0, 0, 2, 1920);
    brL.setDest(0, 0, 1080, 2);
    brR.setDest(1918, 0, 1080, 2);
    brB.setDest(0, 1078, 2, 1920);

    Pipe_Above.setSrc(0, 0, 320, 52);
    Pipe_Above.setDest(1600, -500, 800, 102);
    Pipe_Below.setSrc(0, 0, 320, 52);
    Pipe_Below.setDest(1600, 650, 800, 102);
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
            brB.CreateTexture("images/border.jpg", renderer);
            brT.CreateTexture("images/border.jpg", renderer);
            brL.CreateTexture("images/border.jpg", renderer);
            brR.CreateTexture("images/border.jpg", renderer);

            Pipe_Above.CreateTexture("images/Pipe_Above.png", renderer);
            Pipe_Below.CreateTexture("images/Pipe_Below.png", renderer);

        }
        else {
            std::cout << "Renderer couldn't be created! SDL_Error\n" << SDL_GetError() << std::endl;
        }
    }
}


void GameLoop::Update(){
    b.Update();
    Pipe_Above.Update(renderer);
    Pipe_Below.Update(renderer);
}

void GameLoop::Event() {
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        state = false;
    }
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_w) {
            if (!b.getJumping()) {     
                b.Jump(); 
            }
            else {
                b.Gravity();
            }  
        }
        else if (event.key.keysym.sym == SDLK_d) {
            b.accRight();
            std::cout << "dupa";
            //b.accHorizontal(5);
        }
        else if (event.key.keysym.sym == SDLK_a) {
            b.accLeft();
            //b.accHorizontal(-5);
        }
        else {
            b.Gravity();
        }
    }
    else if ((event.type == SDL_KEYUP)) {
        if (event.key.keysym.sym == SDLK_d) {
            b.setAcceleratingRight(false);
            b.setFdt_x();
            b.setPdt_x();
            std::cout << "lllllllllllllllllllll";


        }
        else {
            b.Gravity();
        }
    }
    else {
        b.Gravity();
    }

}


void GameLoop::CollisionDetection() {
    if (CollisionManager::CheckCollision(&b.getDest(), &brB.getDest()) || CollisionManager::CheckCollision(&b.getDest(), &brT.getDest()) || CollisionManager::CheckCollision(&b.getDest(), &brL.getDest()) || CollisionManager::CheckCollision(&b.getDest(), &Pipe_Above.getDest()) || CollisionManager::CheckCollision(&b.getDest(), &Pipe_Below.getDest())) {
        if (b.getDt() > 500) {
            bgEnd.CreateTexture("images/GO.jpg", renderer);
            state = false;
        }
    }
    
}




void GameLoop::Renderer() {
    SDL_RenderClear(renderer);
    bg.Render(renderer);
    brB.Render(renderer);
    brT.Render(renderer);
    brL.Render(renderer);
    brR.Render(renderer);
    Pipe_Above.PipeRender(renderer);
    Pipe_Below.PipeRender(renderer);
    bgEnd.Render(renderer);

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