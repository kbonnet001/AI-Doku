#pragma once
#ifndef IA_H
#define IA_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


#include "Sudoku.h"
#include "GestionDialogue.h"

// Include des objets de l'interface

using namespace sf;
using namespace std;
//using erase;

class IA
{
public:
	IA(Sudoku& sudoku);
	void changerActivation(bool nouvelleAct);
	void prendreNote(Sudoku& sudoku);
	void retirerElementVecteur(int k, vector<int>& vecteur);
	vector<int> regarderLigne(Sudoku& sudoku, int i);
	vector<int> regarderColonne(Sudoku& sudoku, int j);
	vector<int> regarderCarre(Sudoku& sudoku, int i, int j);
	vector<int> compareNotes(vector<int> note1, vector<int> note2);
	bool chiffrePresentDansLesDeux(vector<int>& vect1, vector<int>& vect2, int chiffre);
	void avoirNote(int i, int j);
	bool singletonEvident(Sudoku& sudoku);
	void mettreAJourNote(int k, int i, int j);
	bool estPresent(vector<int>& vecteur, int k);
	void voirNoteConsole(int i, int j);

	// Stratégie n°2 : Dernier Chiffre Possible
	void dernierChiffrePossible(Sudoku& sudoku);
	bool dernierChiffrePossibleLigne(Sudoku& sudoku);
	bool dernierChiffrePossibleColonne(Sudoku& sudoku);
	bool dernierChiffrePossibleCarre(Sudoku& sudoku);

	void actionIA(Sudoku& sudoku);

	void pairesNues(Sudoku& sudoku);
	bool pairesNuesLigne(Sudoku& sudoku);
	bool pairesNuesColonne(Sudoku& sudoku);
	bool pairesNuesCarre(Sudoku& sudoku);
	void resolution(Sudoku& sudoku);
	void resolutionManuelle(Sudoku& sudoku);


private:
	vector<int> note[9][9];
	bool paireLigne[9][9]; // la case vaut true si une paire a déjà été identifiée
	bool paireColonne[9][9]; // la case vaut true si une paire a déjà été identifiée
	bool paireCarre[9][9]; // la case vaut true si une paire a déjà été identifiée
	//Sudoku sudoku;
	bool active; // si faux, pas d'IA
	

	GestionDialogue gestionDialogueIa;

};

#endif // IA

