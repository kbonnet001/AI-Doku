#ifndef BOUTON_H
#define BOUTON_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Bouton
{
public:
	virtual ~Bouton() = default;
	virtual void draw(RenderWindow& window) = 0;
	virtual bool isClicked(const Vector2f& mousePosition) = 0;
	virtual void onClick(RenderWindow& window) = 0;
	virtual void actionBouton(RenderWindow& window, Vector2f& mousePosition) = 0;
};

#endif // !BOUTON_H



