#include "wonsz.h"

wonsz::wonsz(sf::Vector2f pole)
{

}
void wonsz::aktualizuj(sf::RenderWindow& okno)
{
	for (int i = 0; i < cialo.size(); i++)
	{
		okno.draw(cialo[i]);
	}
}
void wonsz::add()
{
	cialo.push_back(sf::RectangleShape(sf::Vector2f(20, 20)));
}