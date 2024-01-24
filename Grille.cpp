#include "Grille.h"

Grille::Grille()
{
	// Paramètres pour le cadre où seront les boutons avec les chiffres
	//cadreBoutonChiffre.setSize(dimensionCadreChiffre);
	//cadreBoutonChiffre.setPosition(positionCadreChiffre);
	//cadreBoutonChiffre.setFillColor(Color(0, 0, 0));
}

void Grille::drawStatique(RenderWindow& window)
{
	// Permet de dessiner tous les éléments fixes de l'interface
	drawGrilleJeu(window);
}

void Grille::drawGrilleJeu(RenderWindow& window)
{
	// Paramètres pour le cadre carré où sera la grille
	// Afin de bien visionner les 9 carrées, on va dessiner 9 carrés gris avec des contours noirs
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
		// Pour la grille de jeu, on a besoin de 9 carrés
		// Seule la position change
		carresJeu[i - 1].setPosition(Vector2f(19 + (i % 3) * (106 + 3), 234 + k * (106 + 3)));

		//ils ont tous la même couleur et la meme taille
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
	// Permet de dessiner tous les éléments boutons sur l'interface
	for (int i = 0; i < 9; i++)
	{
		nums[i].draw(window);
	}
}
