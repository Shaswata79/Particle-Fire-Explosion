#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include <string.h>

class Screen
{
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 800;

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;
    Uint32* m_buffer1;
    Uint32* m_buffer2;

public:
    Screen();
    bool init();
    bool processEvents();
    void close();
    void update();
    void Clear();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
    void boxBlur();

};

#endif // SCREEN_H

