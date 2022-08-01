#include <iostream>
#include <SFML/Graphics.hpp>

#include <plansza.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 600), "SFML works!");

    plansza plansza(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        plansza.aktualizuj(window);
        window.display();
    }

    return 0;
}