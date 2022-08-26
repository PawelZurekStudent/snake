#include <iostream>
#include <SFML/Graphics.hpp>

#include "gra.h"

#include "menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 600), "SFML works!");

    gra gra(window);

    menu ustawienia(window);

    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //gra.graj(window);
        ustawienia.aktualizuj_glowne(window);

        window.display();
    }

    return 0;
}