#pragma once
#ifndef IAAPPARENCE_H
#define IAAPPARENCE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


// Include des objets de l'interface

using namespace sf;
using namespace std;
//using erase;

class IaApparence
{
public:
	IaApparence();
	void afficherIA(RenderWindow& window);
	bool loadVideo(string cheminVideo);
	void dessinerIa(RenderWindow& window);

private:
	Texture texture;
	const Vector2f& positionSprite = Vector2f(13.f, 83.f);
	const Vector2f& dimensionSprite = Vector2f(0.12f, 0.12f);


};

#endif // IAAPPARENCE

