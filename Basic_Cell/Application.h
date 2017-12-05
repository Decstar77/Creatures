#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Creature.h"


const int WIDTH = 800;
const int HEIGHT = 600;

class Application
{
    private:
        void pollEvents();
        void update();
        void updatePreditor(Creature *, Creature *);
        void updatePrey(Creature *, Creature *);
        int getIndex(int, int);
        std::vector<Creature> m_creature;
        std::vector<sf::Vertex> m_pixels;



    public:
        Application();
        ~Application();
        sf::RenderWindow *m_window;
        void run();

};





#endif // APPLICATION_H_INCLUDED
