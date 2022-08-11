#pragma once
#include <SFML/Graphics.hpp>

#include <vector>

class jabko
{
public:
	jabko(sf::RectangleShape pole);
	bool aktualizuj(sf::RenderWindow& okno, sf::Time laczny_czas, std::vector <sf::RectangleShape> cialo_weza);
	int punkty();
private:
	int ilosc_zjedzonych;
	sf::RectangleShape obszar;
	sf::CircleShape jablko;
	sf::Time czas;
	sf::Vector2f pozycja_ekran, pozycja_siatka;;//siatka od 0,0 do 40,21
	void rusz_jabko(std::vector <sf::RectangleShape> cialo_weza);
	void pozycja_ekran_siatka();
};

