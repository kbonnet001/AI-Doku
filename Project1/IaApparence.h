#pragma once
#ifndef IAAPPARENCE_H
#define IAAPPARENCE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Texte.h"
//#include "GestionDialogue.h"

enum class EtatDialogue { Initial, Note, SingletonEvident };
// Initial --> Début de la grille, dialogue d'introduction
// Note --> Prendre des notes la première fois
// SingletonEvident --> 1e stratégie niv facile


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
	//GestionDialogue avoirGestionDialogue();
	void ligneSuivante();
	void lignePrecedente();
	void paragrapheSuivant();

	void ajouterParagraphe(const vector<string> nouveauParagraphe);
	void affichageTest(int& paragrapheActuel, int& ligneActuelle);
	string avoirLigneDialogue(int& paragrapheActuel, int& ligneActuelle);
	void ajouterTexteSingletonEvident();
	void ajouterTexteNote(bool sansNote /*vector<int> positionCase*/);
	void ajouterTexteInitial();
	string formaterLigneTexte(string ligneTexte, int nbCaracMax = 20, int nbLigneMax = 4);

	void changerEtat(EtatDialogue nouvelleEtatDialogue);
	void ajouterTexte();
	bool savoirSiFinParagraphe();


private:
	Texture texture;
	const Vector2f& positionSprite = Vector2f(13.f, 35.f);
	const Vector2f& dimensionSprite = Vector2f(0.18f, 0.18f);
	RectangleShape boiteDialogue;
	Texte ligneDialogue;
	Color couleurTurquoiseClair = Color(188, 255, 253);
	//GestionDialogue gestionDialogue;
	string ligneTexte;

	int paragrapheActuel = 0;
	int ligneActuelle = 0;

	vector<vector<string>> dialogue;
	bool initialisation = false;
	vector<string> nouvelleLigne;

	EtatDialogue etatDialogue = EtatDialogue::Initial;
};

#endif // IAAPPARENCE

