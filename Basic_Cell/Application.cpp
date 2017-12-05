#include "Application.h"



Application::Application() : m_window(nullptr), m_creature(WIDTH * HEIGHT), m_pixels(WIDTH * HEIGHT)
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            auto currentIndex = getIndex(x, y);
            m_pixels[currentIndex].position = {x, y};
            switch(m_creature[currentIndex].getType())
            {
                case CreatureType::nothing:
                    m_pixels[currentIndex].color = m_creature[currentIndex].getColor(); break;
                case CreatureType::prey:
                    m_pixels[currentIndex].color = m_creature[currentIndex].getColor(); break;
                case CreatureType::preditor:
                    m_pixels[currentIndex].color = m_creature[currentIndex].getColor(); break;
            }
        }
    }
}
Application::~Application()
{

}
void Application::update()
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            int xChange = (-1 + (std::rand() % ( 2 - 0 + 1)));
            int yChange = (-1 + (std::rand() % ( 2 - 0 + 1)));
            int xAdj = x + xChange;
            int yAdj = y + yChange;

            if (xAdj < 0 || xAdj >= WIDTH) continue;
            if (yAdj < 0 || yAdj >= HEIGHT) continue;

            auto currentIndex = getIndex(x, y);
            auto adjIndex = getIndex(xAdj, yAdj);

            Creature *currentCreature = &m_creature[currentIndex];
            Creature *otherCreature = &m_creature[adjIndex];

            switch (currentCreature->getType())
            {
                case CreatureType::nothing:
                    continue;
                    break;
                case CreatureType::preditor:
                    updatePreditor(currentCreature, otherCreature);
                    break;
                case CreatureType::prey:
                    updatePrey(currentCreature, otherCreature);
                    break;

            }

            m_pixels[currentIndex].color = currentCreature->getColor();
            m_pixels[adjIndex].color = otherCreature->getColor();
        }
    }

}

void Application::updatePreditor(Creature *currentCreature, Creature *otherCreature)
{
    currentCreature->changeHealth(-3);
    if (currentCreature->getHealth() <= 0)
    {
        currentCreature->changeType(CreatureType::nothing);
        currentCreature->changeHealth(0);
        return;
    }

    switch(otherCreature->getType())
    {
        case CreatureType::nothing:
            //otherCreature->changeType(currentCreature->getType());
            //otherCreature->changeHealth(currentCreature->getHealth());
            //currentCreature->changeType(CreatureType::nothing);
            return;
        case CreatureType::preditor:
            return;
        case CreatureType::prey:
            currentCreature->setHealth(otherCreature->getHealth());
            otherCreature->changeType(currentCreature->getType());
            break;
    }

}

void Application::updatePrey(Creature *currentCreature, Creature *otherCreature)
{
    currentCreature->changeHealth(2);
    switch(otherCreature->getType())
    {
        case CreatureType::prey:
            return;
        case CreatureType::preditor:
            return;
        case CreatureType::nothing:
            if (currentCreature->getHealth() >= MAXHEALTH)
            {
                currentCreature->setHealth(50);
                otherCreature->changeType(currentCreature->getType());
                otherCreature->setHealth(50);
            }
            else
            {
                otherCreature->changeType(currentCreature->getType());
                otherCreature->changeHealth(currentCreature->getHealth());
                currentCreature->changeType(CreatureType::nothing);
            }
            break;
    }

}

void Application::run()
{
    while(m_window->isOpen())
    {
        m_window->clear();
        update();
        m_window->draw(m_pixels.data(), m_pixels.size(), sf::Points);
        pollEvents();
        m_window->display();
    }
}

void Application::pollEvents()
{
    sf::Event events;

    while(m_window->pollEvent(events))
    {
        if (events.type == sf::Event::Closed)
        {
            m_window->close();
        }
    }
}

int Application::getIndex(int x, int y)
{
    return y*WIDTH + x;
}
