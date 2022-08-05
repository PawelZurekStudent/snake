#pragma once
#include <SFML/Graphics.hpp>
#include <plansza.h>
#include <wonsz.h>

class gra
{
public:
	void graj(sf::RenderWindow& okno, wonsz& wonz, plansza& plansz);
private:
	sf::Clock zegar;
};

