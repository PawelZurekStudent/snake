#include "wonsz.h"

#include <iostream>

wonsz::wonsz(sf::RectangleShape pole)
{
	//kopia obszaru do kolizji ze scianami
	obszar = pole;

	//dodanie "glowy"
	add();
	cialo[0].setFillColor(sf::Color::Green);

	//ustawienie weza na srodku
	pozycja_siatka = sf::Vector2f(21, 12);
	pozycja_ekran_siatka();
	cialo[0].setPosition(pozycja_ekran);
}
void wonsz::aktualizuj(sf::RenderWindow& okno, sf::Time czas_aktualny)
{
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

	//std::cout << cialo.size() << std::endl;

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
	cialo[0].setPosition(pozycja_ekran);

	//rysowanie na ekranie
	for (int i = 0; i < cialo.size(); i++)
	{
		okno.draw(cialo[i]);
	}
	
}
void wonsz::add()
{
	cialo.push_back(sf::RectangleShape(sf::Vector2f(18, 18)));
	cialo[cialo.size()-1].setFillColor(sf::Color::White);
	//cialo[cialo.size()-1].setOrigin(sf::Vector2f(9, 9));


	//std::cout << cialo.size();
}

void wonsz::pozycja_ekran_siatka()
{
	pozycja_ekran.x = obszar.getPosition().x + 1 + pozycja_siatka.x * 20;
	pozycja_ekran.y = obszar.getPosition().y + 1 + pozycja_siatka.y * 20;
}