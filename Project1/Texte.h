#ifndef TEXTE_H
#define TEXTE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Texte
{
	// La classe texte est utilisée par les boutons
public:
	Texte();
	void ChargerFont();
	void ConfigurationTexteBouton( int police, string ecriture, Vector2f position, RectangleShape bouton);
	void CentrerTexte(Vector2f position, RectangleShape bouton);
	void drawTexte(RenderWindow& window);
	void changerCouleur(Color nouvelleCouleur);
	string avoirTexteTest();
	void ConfigurationTexte(int police, string ecriture, Vector2f position);
	void nouveauTexte(string nouveauTexte);


private:
	// Un élément texte contient un font et un text
	Font font;
	Text texte;
	Color couleur=Color::Black;
};

#endif // TEXTE
#pragma once

