#ifndef BOUTON_H
#define BOUTON_H

#include "Texte.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Bouton
{
public:
	virtual ~Bouton() = default;
	virtual void draw(RenderWindow& window);
	//void onClick(RenderWindow& window) = 0;
	virtual bool boutonClique(const Vector2f& mousePosition)=0;
	//virtual void actionBouton(RenderWindow& window, Vector2f& mousePosition) = 0;

private : 
	RectangleShape bouton;
	Texte ecriture;
};

#endif // !BOUTON_H



