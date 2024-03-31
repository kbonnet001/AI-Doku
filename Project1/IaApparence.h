#pragma once
#ifndef IAAPPARENCE_H
#define IAAPPARENCE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Texte.h"

enum class EtatDialogue { NiveauFaible, Initial, Note, SingletonEvident, DernierChiffrePossible, PairesNues, Final};
// NiveauFaible --> L'IA n'a pas utilis� de strat�gie, elle ne peut pas terminer la r�solution
// Initial --> D�but de la grille, dialogue d'introduction
// Note --> Prendre des notes la premi�re fois
// SingletonEvident --> 1e strat�gie niv facile
// PairesNues --> strat�gie niv difficile
// Final --> Sudoku termin�


using namespace sf;
using namespace std;

class IaApparence
{
public:
	IaApparence();
	void afficherIA(RenderWindow& window);
	bool loadVideo(string cheminVideo);
	void dessinerIa(RenderWindow& window);
	void configurationDialogue();
	void ligneSuivante();
	void lignePrecedente();
	void paragrapheSuivant();
	void ajouterTextePairesNues();

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
	void ajouterTexteDernierChiffrePossible();
	void ajouterTexteFinal();
	void ajouterTexteNiveauFaible();

private:
	Texture texture;
	const Vector2f& positionSprite = Vector2f(13.f, 35.f);
	const Vector2f& dimensionSprite = Vector2f(0.18f, 0.18f);
	RectangleShape boiteDialogue;
	Texte ligneDialogue;
	Color couleurTurquoiseClair = Color(188, 255, 253);
	string ligneTexte;

	int paragrapheActuel = 0;
	int ligneActuelle = 0;

	vector<vector<string>> dialogue;
	bool initialisation = false;
	vector<string> nouvelleLigne;

	EtatDialogue etatDialogue = EtatDialogue::Initial; // On commence par le dialogue d'introduction
	bool finDialogue = false; // true si --> Final ou --> Niveau trop faible (pour ne pas avoir une boucle de dialogue infini)
};

#endif // IAAPPARENCE

