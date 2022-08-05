#pragma once
#include <SFML/Graphics.hpp>

class plansza
{
public:
	plansza(sf::RenderWindow& okno);
	void aktualizuj(sf::RenderWindow& okno, int czas_lacznie);
	sf::RectangleShape getPole();
private:
	sf::RectangleShape obwod,pole;
	sf::RectangleShape siatka[100];
	sf::Text czas;
	sf::Font czcionka;
	std::string zegarek;
	int minuty, sekndy;
};