#pragma once
#ifndef IA_H
#define IA_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


#include "Sudoku.h"

// Include des objets de l'interface

using namespace sf;
using namespace std;
//using erase;

class IA
{
public:
	IA(Sudoku& sudoku);
	void prendreNote(Sudoku& sudoku);
	void retirerElementVecteur(int k, vector<int>& vecteur);
	vector<int> regarderLigne(Sudoku& sudoku, int i);
	vector<int> regarderColonne(Sudoku& sudoku, int j);
	vector<int> regarderCarre(Sudoku& sudoku, int i, int j);
	vector<int> compareNotes(vector<int> note1, vector<int> note2);
	bool chiffrePresentDansLesDeux(vector<int>& vect1, vector<int>& vect2, int chiffre);
	void avoirNote(int i, int j);
	void singletonEvident(Sudoku& sudoku);
	void mettreAJourNote(int k, int i, int j);
	bool estPresent(vector<int>& vecteur, int k);
	void voirNoteConsole(int i, int j);
	void dernierChiffrePossible(Sudoku& sudoku);

private:
	vector<int> note[9][9];
	//Sudoku sudoku;

};

#endif // IA

