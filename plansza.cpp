#include "plansza.h"

#include <iostream>

plansza::plansza(sf::RenderWindow& okno)
{
	//kolory
	obwod.setFillColor(sf::Color::White);
	pole.setFillColor(sf::Color::Black);

	//rozmiary
	obwod.setSize(sf::Vector2f(okno.getSize().x - 40, okno.getSize().y - 120));
	pole.setSize(sf::Vector2f(okno.getSize().x - 80, okno.getSize().y - 160));

	//polozenie
	obwod.setPosition(sf::Vector2f(20, 20));
	pole.setPosition(sf::Vector2f(40, 40));

	//napis
	czcionka.loadFromFile("Roboto-Light.ttf");
	czas.setFont(czcionka);
	czas.setCharacterSize(80);
	czas.setFillColor(sf::Color::White);
	czas.setString("00:00");

	//punkty
	punkty.setFont(czcionka);
	punkty.setCharacterSize(80);
	punkty.setFillColor(sf::Color::White);
	punkty.setString("0");
	punkty.setPosition(40, okno.getSize().y - 100);

	//siatke trzeba zrobic tak zeby sie nie psula przy duzej rozdzielczosci
	////siatka
	//int j = 0;
	//for (int i = pole.getPosition().x + 20; i < pole.getPosition().x + pole.getSize().x; i = i + 20)
	//{
	//	siatka[j].setFillColor(sf::Color::Color(100, 100, 100, 100));
	//	siatka[j].setSize(sf::Vector2f(2, 440));
	//	siatka[j].setPosition(sf::Vector2f(i - 1, 40));
	//	j++;
	//}
	//for (int i = pole.getPosition().y + 20; i < pole.getPosition().y + pole.getSize().y; i = i + 20)
	//{
	//	siatka[j].setFillColor(sf::Color::Color(100, 100, 100, 100));
	//	siatka[j].setSize(sf::Vector2f(820, 2));
	//	siatka[j].setPosition(sf::Vector2f(40, i - 1));
	//	j++;
	//}
	//std::cout << j;
}

void plansza::aktualizuj(sf::RenderWindow& okno, int czas_lacznie, int punkt)
{
	//aktualizacja czasu
	minuty = czas_lacznie / 60;
	sekndy = czas_lacznie % 60;

	if(sekndy<10)
		zegarek = std::to_string(minuty) + ":0" + std::to_string(sekndy);
	else
		zegarek = std::to_string(minuty) + ":" + std::to_string(sekndy);

	czas.setString(zegarek);

	//ustawianie zegarka na srodku
	czas.setOrigin(sf::Vector2f(czas.getLocalBounds().width / 2, 0));// czas.getLocalBounds().height / 2));
	czas.setPosition(sf::Vector2f(okno.getSize().x / 2, okno.getSize().y - 100));

	//aktualizacja punktow
	punkty.setString(std::to_string(punkt));


	//rysowanie
	okno.draw(obwod);
	okno.draw(pole);
	okno.draw(czas);
	okno.draw(punkty);

	////siatka
	//for (int i = 0; i < 61; i++)
	//	okno.draw(siatka[i]);
}

sf::RectangleShape plansza::getPole() 
{
	return pole;
}