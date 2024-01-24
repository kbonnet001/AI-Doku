#include "Grille.h"

Grille::Grille()
{
	// Param�tres pour le cadre o� seront les boutons avec les chiffres
	//cadreBoutonChiffre.setSize(dimensionCadreChiffre);
	//cadreBoutonChiffre.setPosition(positionCadreChiffre);
	//cadreBoutonChiffre.setFillColor(Color(0, 0, 0));
}

void Grille::drawStatique(RenderWindow& window)
{
	// Permet de dessiner tous les �l�ments fixes de l'interface
	drawGrilleJeu(window);
}

void Grille::drawGrilleJeu(RenderWindow& window)
{
	// Param�tres pour le cadre carr� o� sera la grille
	// Afin de bien visionner les 9 carr�es, on va dessiner 9 carr�s gris avec des contours noirs
	int k;
	for (int i = 1; i < 10; i++)
	{
		if (i >=7)
		{
			k = 2;
		}
		else if (i >= 4)
		{
			k = 1;
		}
		else
		{
			k = 0;
		}
		// Pour la grille de jeu, on a besoin de 9 carr�s
		// Seule la position change
		carresJeu[i - 1].setPosition(Vector2f(19 + (i % 3) * (106 + 3), 234 + k * (106 + 3)));

		//ils ont tous la m�me couleur et la meme taille
		carresJeu[i - 1].setFillColor(couleurGris);
		carresJeu[i - 1].setOutlineColor(noir);
		carresJeu[i - 1].setOutlineThickness(3.f);
		carresJeu[i - 1].setSize(dimensionCadreJeu);

		window.draw(carresJeu[i - 1]);
	}
}

BoutonEcrire Grille::avoirBoutonEcrire(int i)
{
	return nums[i];
}

void Grille::drawBoutons(RenderWindow& window)
{
	// Permet de dessiner tous les �l�ments boutons sur l'interface
	for (int i = 0; i < 9; i++)
	{
		nums[i].draw(window);
	}
}
