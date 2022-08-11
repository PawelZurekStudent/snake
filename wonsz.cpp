#include "wonsz.h"

#include <iostream>

wonsz::wonsz(sf::RectangleShape pole)
{
	//kopia obszaru do kolizji ze scianami
	obszar = pole;

	//dodanie "glowy"
	add();
	cialo[0].setFillColor(sf::Color::Green);

	//add(); add(); add(); add(); add();
	
	//ustawienie weza na srodku
	pozycja_siatka = sf::Vector2f(21, 12);
	pozycja_ekran_siatka();
	cialo[0].setPosition(pozycja_ekran);
}
bool wonsz::aktualizuj(sf::RenderWindow& okno, sf::Time czas_aktualny, bool dodaj)
{
	//dodanie segmantu
	if (dodaj == true)
		this->add();

	//ruch
	uplynelo = czas_aktualny - czas_poprzedni;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		kierunek = 3;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		kierunek = 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		kierunek = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		kierunek = 0;

	if (uplynelo.asMilliseconds() > czas_ruchu)
	{
		if (kierunek == 0)
			pozycja_siatka.y--;
		if (kierunek == 1)
			pozycja_siatka.y++;
		if (kierunek == 2)
			pozycja_siatka.x--;
		if (kierunek == 3)
			pozycja_siatka.x++;
		
		for (int i = cialo.size() - 1; i > 0; i--)
		{
			cialo[i].setPosition(cialo[i - 1].getPosition());
		}

		czas_poprzedni = czas_aktualny;
	}
	pozycja_ekran_siatka();
	
	//ustawienie pozycji na ekranie
	cialo[0].setPosition(pozycja_ekran);

	//obsluga umierania
	//krawedzie mapy lewo i gora
	if (cialo[0].getPosition().x < obszar.getPosition().x || cialo[0].getPosition().y < obszar.getPosition().y)
		return false;
	//krawedzie mapy prawo i dol
	if (cialo[0].getPosition().x + 19 > obszar.getPosition().x + obszar.getSize().x || cialo[0].getPosition().y + 19 > obszar.getPosition().y + obszar.getSize().y)
		return false;
	//waz sam w sie wchodzi
	for (int i = 1; i < cialo.size(); i++)
		if (cialo[0].getPosition() == cialo[i].getPosition())
			return false;

	//rysowanie na ekranie
	for (int i = 0; i < cialo.size(); i++)
		okno.draw(cialo[i]);

	return true;
}
void wonsz::add()
{
	cialo.push_back(sf::RectangleShape(sf::Vector2f(18, 18)));
	cialo[cialo.size()-1].setFillColor(sf::Color::White);
	czas_ruchu -= 2;
	//cialo[cialo.size()-1].setOrigin(sf::Vector2f(9, 9));
	//std::cout << cialo.size();
}

std::vector <sf::RectangleShape> wonsz::getCialo()
{
	return cialo;
}

void wonsz::pozycja_ekran_siatka()
{
	pozycja_ekran.x = obszar.getPosition().x + 1 + pozycja_siatka.x * 20;
	pozycja_ekran.y = obszar.getPosition().y + 1 + pozycja_siatka.y * 20;
}