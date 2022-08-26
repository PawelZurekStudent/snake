#pragma once
#include <SFML/Graphics.hpp>

#include <plansza.h>
#include <wonsz.h>
#include <jabko.h>

class gra
{
public:
	gra(sf::RenderWindow& okno);
	void graj(sf::RenderWindow& okno);
private:
	sf::Clock zegar;
	plansza *plansz;
	wonsz *waz;
	jabko *jablko;
	bool zyje = true, czy_dodac = false;
};