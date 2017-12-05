#include "Application.h"
#include <iostream>

int main()
{

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "FF");
    Application app;
    app.m_window = &window;
    app.run();

    return 0;
}
