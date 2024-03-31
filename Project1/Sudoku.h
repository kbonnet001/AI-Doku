#ifndef SUDOKU_H
#define SUDOKU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace sf;
using namespace std;

class Sudoku
{
public:
	Sudoku(int niveau);
	void genererJeu(int niveau);
	void copieTableau(int t1[9][9], int t2[9][9]);
	void ecrire(int k, int i, int j);
	int avoirJeu(int i, int j);
	bool verifieSiJeuInital(int i, int j);
	void mettreAJourEtat();
	bool avoirEtat();
	bool estPresent(vector<int>& vecteur, int k);
	vector<int> avoirNoteVecteur(int i, int j);
	void ecrireNote(int k, int i, int j);
	void creerJeuInitial();

private:
	int jeuInitial[9][9]; // grille de sudoku donné au joueur, celle ci ne change pas 
	int jeuEnCours[9][9]; // sudoku que le joueur change quand il joue
	int jeuReference[9][9]; // sudoku fini, solution finale que doit atteindre le joueur (non utilisé actuellement, pour persepective du projet)
	int niveau=1; // le niveau de la grille pouvant aller de 1 (facile) à 3 (difficile)
	bool etat = false;// état de la grille, = true si la grille est complétée
	vector<int> noteSudoku[9][9]; // chaque case de la grille contient un vecteur des notes 


};

#endif // SUDOKU
#pragma once

