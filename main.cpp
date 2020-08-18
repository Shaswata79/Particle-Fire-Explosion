#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Screen.h"
#include <time.h>
#include "Swarm.h"
#include "Particle.h"

using namespace std;

int main(int argc, char* argv[])
{


    //srand(time(NULL));
    Screen screen;
    Swarm swarm;



    if(screen.init()  == false){
        std::cout << "Error initialising SDL" << endl;
    }

    int j = 0;
    while(true){

        int elapsed = SDL_GetTicks();

        cout << "Frames: " << j++ << endl;


        //update particles
        //Draw particles
        int time = SDL_GetTicks();



        swarm.update(elapsed);

        unsigned char green = (1 + sin(time * 0.0001)) * 128;
        unsigned char red = (1 + sin(time * 0.0002)) * 128;
        unsigned char blue = (1 + sin(time * 0.0003)) * 128;


        const Particle * const pParticles = swarm.getParticles();

        for(int i = 0; i < swarm.NPARTICLES; i++){
            Particle particle = pParticles[i];
            int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH/2;
            int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT/2;

            screen.setPixel(x, y, red, green, blue);
        }


        screen.boxBlur();

        screen.update();  //draw the changed screen

        if(screen.processEvents() == false){     //Check for messages or events
            break;
        }
    }

    screen.close();

    return 0;
}
