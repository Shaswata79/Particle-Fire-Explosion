#ifndef PARTICLE_H
#define PARTICLE_H


struct Particle
{
    public:
        double m_x;
        double m_y;
        double m_speed;
        double m_direction;

    public:
        Particle();
        void update(int interval);
};

#endif // PARTICLE_H
