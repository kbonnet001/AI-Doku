#pragma once
#ifndef IAAPPARENCE_H
#define IAAPPARENCE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Texte.h"
#include "GestionDialogue.h"


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
	void configurationDialogue();
	//void miseAJourDialogue();
	GestionDialogue avoirGestionDialogue();
	void ligneSuivante();
	void lignePrecedente();

private:
	Texture texture;
	const Vector2f& positionSprite = Vector2f(13.f, 35.f);
	const Vector2f& dimensionSprite = Vector2f(0.18f, 0.18f);
	RectangleShape boiteDialogue;
	Texte dialogue;
	Color couleurTurquoiseClair = Color(188, 255, 253);
	GestionDialogue gestionDialogue;
	string ligneTexte;

	int paragrapheActuel = 0;
	int ligneActuelle = 0;
};

#endif // IAAPPARENCE

