#include "plansza.h"

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
}

void plansza::aktualizuj(sf::RenderWindow& okno)
{
	//aktualizacja czasu
	czas_lacznie = zegar.getElapsedTime().asSeconds();
	minuty = czas_lacznie / 60;
	sekndy = czas_lacznie % 60;

	if(sekndy<10)
		zegarek = std::to_string(minuty) + ":0" + std::to_string(sekndy);
	else
		zegarek = std::to_string(minuty) + ":" + std::to_string(sekndy);

	czas.setString(zegarek);

	//ustawianie zegarka na srodku
	czas.setOrigin(sf::Vector2f(czas.getLocalBounds().width/2, czas.getLocalBounds().height / 2));
	czas.setPosition(sf::Vector2f(okno.getSize().x / 2, okno.getSize().y - 70));

	//rysowanie
	okno.draw(obwod);
	okno.draw(pole);
	okno.draw(czas);
}