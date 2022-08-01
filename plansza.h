#pragma once
#include <SFML/Graphics.hpp>

class plansza
{
public:
	plansza(sf::RenderWindow& okno);
	void aktualizuj(sf::RenderWindow& okno);
private:
	sf::RectangleShape obwod,pole;
	sf::Clock zegar;
	sf::Text czas;
	sf::Font czcionka;
	std::string zegarek;
	int czas_lacznie, minuty, sekndy;
};

