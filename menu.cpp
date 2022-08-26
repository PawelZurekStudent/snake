#include "menu.h"
#include <iostream>

menu::menu(sf::RenderWindow& okno)
{
	czcionka.loadFromFile("Roboto-Light.ttf");

	menu_glowne[0].setString("Start");
	menu_glowne[1].setString("Zmien okno");
	menu_glowne[2].setString("Pomoc");
	menu_glowne[3].setString("Wyjscie");

	for (int i = 0; i < 4; i++)
	{
		//tekst menu
		menu_glowne[i].setFont(czcionka);
		menu_glowne[i].setCharacterSize(100);
		menu_glowne[i].setFillColor(sf::Color::White);

		menu_glowne[i].setOrigin(sf::Vector2f(menu_glowne[i].getLocalBounds().width / 2, 0));
		menu_glowne[i].setPosition(sf::Vector2f(okno.getSize().x / 2, 50 + 120 * i));


		prostokat_menu_glowne[i].setSize(sf::Vector2f(menu_glowne[i].getLocalBounds().width, menu_glowne[i].getLocalBounds().height));
		prostokat_menu_glowne[i].setOrigin(sf::Vector2f(menu_glowne[i].getLocalBounds().width / 2, 0));
		prostokat_menu_glowne[i].setPosition(sf::Vector2f(okno.getSize().x / 2, 50 + 27 + 120 * i));
		prostokat_menu_glowne[i].setFillColor(sf::Color::Green);
	}
}

bool menu::aktualizuj_glowne(sf::RenderWindow& okno)
{
	for (int i = 0; i < 4; i++)
	{
		if (myszka(prostokat_menu_glowne[i], okno))
			std::cout << i << std::endl;
	}
	if (myszka(prostokat_menu_glowne[1], okno))
	{
		okno = new sf::RenderWindow(sf::VideoMode(1600, 900), "SFML dziala!");
	}
	for (int i = 0; i < 4; i++)
	{
		okno.draw(prostokat_menu_glowne[i]);
		okno.draw(menu_glowne[i]);
	}
	return true;
}

bool menu::myszka(sf::RectangleShape prostokat, sf::RenderWindow& okno)
{
	if (sf::Mouse::getPosition(okno).x >= prostokat.getPosition().x - 0.5 * prostokat.getSize().x 
		&& sf::Mouse::getPosition(okno).y >= prostokat.getPosition().y
		&& sf::Mouse::getPosition(okno).x <= prostokat.getPosition().x + 0.5 * prostokat.getSize().x
		&& sf::Mouse::getPosition(okno).y <= prostokat.getPosition().y + prostokat.getSize().y)
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			return true;
	return false;
}