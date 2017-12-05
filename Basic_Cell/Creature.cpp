#include "Creature.h"

Creature::Creature()
{
    this-> m_health = MAXHEALTH/2;
    this-> m_type = CreatureType(0 + ( std::rand() % ( 2 - 0 + 1 )));
}
Creature::~Creature()
{

}

sf::Color Creature::getColor()
{
    switch(m_type)
    {
        case CreatureType::nothing:
            return sf::Color::Black;
        case CreatureType::prey:
            return sf::Color::Green;
        case CreatureType::preditor:
            return sf::Color::Red;
    }
}

CreatureType Creature::getType()
{
    return m_type;
}

void Creature::changeType(CreatureType newType)
{
    this->m_type = newType;
}

void Creature::changeHealth(int new_health)
{
    this -> m_health += new_health;
}

void Creature::setHealth(int new_health)
{
    this-> m_health = new_health;
}

int Creature::getHealth()
{
    return this->m_health;
}
