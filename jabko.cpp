#include "jabko.h"

jabko::jabko(sf::RectangleShape pole)
{
	//kopia obszaru do kolizji ze scianami
	obszar = pole;

	//ustawienie jablka
	jablko.setFillColor(sf::Color::Red);
	jablko.setRadius(9);

	pozycja_siatka = sf::Vector2f(13, 13);
	pozycja_ekran_siatka();
	jablko.setPosition(pozycja_ekran);


	ilosc_zjedzonych = 0;

}

bool jabko::aktualizuj(sf::RenderWindow& okno, sf::Time laczny_czas, std::vector <sf::RectangleShape> cialo_weza)
{
	//pozycja
	if (jablko.getPosition() == cialo_weza[0].getPosition())
	{
		ilosc_zjedzonych++;
		czas = laczny_czas;
		rusz_jabko(cialo_weza);
		return true;
	}
	if ((laczny_czas - czas).asSeconds() > 20)
	{
		czas = laczny_czas;
		rusz_jabko(cialo_weza);
		return false;
	}

	//rysowanie
	okno.draw(jablko);

	return false;
}
//petla losuje pozycje jablka ktora nie pokrywa sie z wezem
void jabko::rusz_jabko(std::vector <sf::RectangleShape> cialo_weza)
{
	bool petla = true;
	while (petla)
	{
		petla = false;
		pozycja_siatka.x = rand() % 41;
		pozycja_siatka.y = rand() % 22;

		pozycja_ekran_siatka();
		jablko.setPosition(pozycja_ekran);

		for (int i = 0; i < cialo_weza.size(); i++)
		{
			if (jablko.getPosition() == cialo_weza[i].getPosition())
				petla = true;
		}
	}
}

int jabko::punkty()
{
	return ilosc_zjedzonych;
}

void jabko::pozycja_ekran_siatka()
{
	pozycja_ekran.x = obszar.getPosition().x + 1 + pozycja_siatka.x * 20;
	pozycja_ekran.y = obszar.getPosition().y + 1 + pozycja_siatka.y * 20;
}