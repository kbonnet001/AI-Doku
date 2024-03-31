#pragma once
#ifndef IA_H
#define IA_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


#include "Sudoku.h"
#include "IaApparence.h"

using namespace sf;
using namespace std;


class IA
{
public:
	IA(Sudoku& sudoku);
	// -------------- RESOLUTIONS --------------
	void resolution(Sudoku& sudoku);
	EtatDialogue resolutionManuelle(Sudoku& sudoku);

	// -------------- PRENDRE DES NOTES --------------
	void prendreNote(Sudoku& sudoku, bool modeManuel);
	vector<int> regarderLigne(Sudoku& sudoku, int i);
	vector<int> regarderColonne(Sudoku& sudoku, int j);
	vector<int> regarderCarre(Sudoku& sudoku, int i, int j);

	// -------------- METTRE A JOUR LES NOTES --------------
	vector<int> compareNotes(vector<int> note1, vector<int> note2);
	void mettreAJourNote(int k, int i, int j);

	// -------------- STRATEGIE N°1 --------------
	bool singletonEvident(Sudoku& sudoku);

	// -------------- STRATEGIE N°2 --------------
	bool dernierChiffrePossible(Sudoku& sudoku);
	bool dernierChiffrePossibleLigne(Sudoku& sudoku);
	bool dernierChiffrePossibleColonne(Sudoku& sudoku);
	bool dernierChiffrePossibleCarre(Sudoku& sudoku);

	// -------------- STRATEGIE N°3 --------------
	bool pairesNues(Sudoku& sudoku);
	bool pairesNuesLigne(Sudoku& sudoku);
	bool pairesNuesColonne(Sudoku& sudoku);
	bool pairesNuesCarre(Sudoku& sudoku);

	// -------------- AUTRES PRATIQUES --------------

	void changerActivation(bool nouvelleAct);
	void retirerElementVecteur(int k, vector<int>& vecteur);
	bool chiffrePresentDansLesDeux(vector<int>& vect1, vector<int>& vect2, int chiffre);
	void avoirNote(int i, int j);	
	bool estPresent(vector<int>& vecteur, int k);
	void voirNoteConsole(int i, int j);
	vector<int> avoirVecteurNote(int i, int j);

private:
	vector<int> note[9][9]; // chaque case contient un vecteur contenant les notes 
	bool paireLigne[9][9]; // la case vaut true si une paire a déjà été identifiée
	bool paireColonne[9][9]; // la case vaut true si une paire a déjà été identifiée
	bool paireCarre[9][9]; // la case vaut true si une paire a déjà été identifiée
	bool active; // si faux, pas d'IA

	IaApparence iaApparence;
};

#endif // IA

