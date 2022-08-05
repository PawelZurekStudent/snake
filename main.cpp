#include <iostream>
#include <SFML/Graphics.hpp>

#include <plansza.h>
#include <wonsz.h>
#include "gra.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 600), "SFML works!");

    plansza plansza(window);
    wonsz waz(plansza.getPole());
    
    gra gra;

    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        gra.graj(window, waz, plansza);

        window.display();
    }

    return 0;
}