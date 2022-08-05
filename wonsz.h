#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class wonsz
{
public:
	wonsz(sf::RectangleShape pole);
	void aktualizuj(sf::RenderWindow& okno, sf::Time czas);
	void add();
private:
	std::vector <sf::RectangleShape> cialo;
	sf::RectangleShape obszar;
	float czas_ruchu = 200;
	sf::Time czas_poprzedni, uplynelo;
	sf::Vector2f pozycja_ekran,pozycja_siatka;//siatka od 0,0 do 40,21
	int kierunek = 0;
	void pozycja_ekran_siatka();
};

