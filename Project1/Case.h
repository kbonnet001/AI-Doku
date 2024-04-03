#ifndef CASE_H
#define CASE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

// Includes Header
#include "BoutonEcrire.h"

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
	void configurationNote(Vector2f position);
	void draw(RenderWindow& window);
	bool boutonClique(const Vector2f& mousePosition);
	void changerCouleur(Color couleurBouton);
	void changerCouleurTexte(Color couleurTexte);
	void mettreAJourNoteCase(vector<int> noteVecteur);
	string savoirChiffreNote(int k);
	bool estPresent(vector<int>& vecteur, int k);
	int avoirValeur();
	string savoirTexteNote();

private:
	const Vector2f position;
	const Vector2f dimension = Vector2f(33.33f, 33.33f);
	int valeur = 0; // on initialise à 0 au début
	RectangleShape carre;
	bool clique = false;
	Texte ecriture; // texte de la case si valeur !=0 --> pas de notes

	Texte ecritureNote; // texte "phrase" avec les notes de la case et retour à la ligne --> pb d'optimisation
	String ecritureNoteString;
	vector<int> noteCase; // note de la case
	
	Color couleur = Color::White; // couleur de la case
};

#endif // CASE

