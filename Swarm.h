#ifndef SWARM_H
#define SWARM_H
#include "Particle.h"

class Swarm
{
    private:
        Particle* m_pParticles;
        int lastTime;

    public:
        const static int NPARTICLES = 5000;

    public:
        Swarm();
        void update(int elapsed);
        const Particle * const getParticles(){return m_pParticles;};
};

#endif // SWARM_H
