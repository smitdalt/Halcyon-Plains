#include "../include/LTimer.h"
#include <SDL2/SDL.h>
#include <iostream>

const int WIDTH = 1080;
const int HEIGHT = 720;
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

bool running, fullscreen;

SDL_Renderer* renderer;
SDL_Window* window;

// FPS Variables
int countedFrames = 0;
LTimer fps;
LTimer cap;

void update() {
    if(fullscreen) SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    if(!fullscreen) SDL_SetWindowFullscreen(window, 0);
}

void input() {
    SDL_Event e;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    while(SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) running = false;
    }
    
    if(keystates[SDL_SCANCODE_ESCAPE]) running = false;
    if(keystates[SDL_SCANCODE_F11]) fullscreen = !fullscreen;
}

void draw() {
    //Background Rendering
    SDL_SetRenderDrawColor(renderer, 40, 43, 200, 255);
    SDL_Rect rect;
    rect.x=rect.y = 0;
    rect.w=WIDTH;
    rect.h=HEIGHT;
    SDL_RenderFillRect(renderer, &rect);
    //End Background Rendering

    //Keep track of number of frames
    //TODO: Refactor
    if(cap.getTicks() < SCREEN_TICKS_PER_FRAME)
    {
        //Sleep the remaining frame time
        SDL_Delay(SCREEN_TICKS_PER_FRAME - cap.getTicks());
    }

    SDL_RenderPresent(renderer);
    countedFrames++;
}

int main(int argc, char* args[]) {
    running = true;
    fullscreen = false;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed to initialize SDL..." << std::endl;
    if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer) < 0) std::cout << "Failed to create SDL Window or Renderer" << std::endl;
    SDL_SetWindowTitle(window, "SDL Test Game");
    SDL_ShowCursor(1);

    fps.start();

    while(running) {

        cap.start();

        //Calculate and correct fps
        float avgFPS = countedFrames / ( fps.getTicks() / 1000.f );
        std::cout << "Frames per Second: " << avgFPS << std::endl;

        update();
        input();
        draw();
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}