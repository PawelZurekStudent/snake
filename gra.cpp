#include "gra.h"


gra::gra(sf::RenderWindow& okno)
{
	plansz = new plansza(okno);
	waz = new wonsz(plansz->getPole());
	jablko = new jabko(plansz->getPole());
}

void gra::graj(sf::RenderWindow& okno)
{
	//gra
	plansz->aktualizuj(okno, zegar.getElapsedTime().asSeconds(),jablko->punkty());
	czy_dodac = jablko->aktualizuj(okno, zegar.getElapsedTime(), waz->getCialo());
	zyje = waz->aktualizuj(okno, zegar.getElapsedTime(), czy_dodac);
	if (!zyje)
		okno.close();
}