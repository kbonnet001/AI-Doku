#ifndef CASE_H
#define CASE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

// Includes Header
#include "BoutonEcrire.h"
#include "Texte.h"

using namespace sf;
using namespace std;

class Case
{
public:
	Case();
	void ecrireValeurCase(int chiffre);
	void effacerValeurCase();
	//bool isClicked(const::Vector2f& mousePosition);
	string savoirChiffre();
	void configuration(Vector2f position);
	void draw(RenderWindow& window);
	bool boutonClique(const Vector2f& mousePosition);
	void changerCouleur(Color couleurBouton);
	void changerCouleurTexte(Color couleurTexte);

private:
	const Vector2f position;
	const Vector2f dimension = Vector2f(33.33f, 33.33f);
	int valeur = 0; // on initialise à 0 au début
	RectangleShape carre;
	bool clique = false;
	Texte ecriture;
	Color couleur = Color::White;
};

#endif // CASE
#pragma once
#pragma once
