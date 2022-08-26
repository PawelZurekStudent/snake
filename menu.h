#pragma once
#include <SFML/Graphics.hpp>

class menu
{
public:
	menu(sf::RenderWindow& okno);
	bool aktualizuj_glowne(sf::RenderWindow& okno);
	void aktualizuj_koniec(sf::RenderWindow& okno);

private:
	sf::Font czcionka;
	sf::Text menu_glowne[4];
	sf::RectangleShape prostokat_menu_glowne[4];

	sf::Text menu_koniec[4];
	sf::RectangleShape prostokat_menu_koniec[4];

	bool myszka(sf::RectangleShape prostokat, sf::RenderWindow& okno);
};