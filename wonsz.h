#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class wonsz
{
public:
	wonsz(sf::Vector2f pole);
	void aktualizuj(sf::RenderWindow& okno);
	void add();

private:

	std::vector <sf::RectangleShape> cialo;
	int rozmiar = 0;

	sf::RectangleShape obszar;
	float predkosc;
};

