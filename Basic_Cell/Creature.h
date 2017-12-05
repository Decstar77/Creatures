#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED
#include <cstdlib>
#include <SFML/Graphics.hpp>

enum CreatureType
{
    nothing = 0,
    prey = 1,
    preditor = 2
};

const int MAXHEALTH = 100;

class Creature
{
    private:
        CreatureType m_type;
        int m_health;

    public:
        Creature();
        ~Creature();
        void changeType(CreatureType);
        void changeHealth(int);
        void setHealth(int);
        int getHealth();
        CreatureType getType();
        sf::Color getColor();
};


#endif // CREATURE_H_INCLUDED
