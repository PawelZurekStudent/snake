#include "gra.h"


void gra::graj(sf::RenderWindow& okno, wonsz& wonz, plansza& plansz)
{
	//gra
	plansz.aktualizuj(okno, zegar.getElapsedTime().asSeconds());
	wonz.aktualizuj(okno, zegar.getElapsedTime());
}