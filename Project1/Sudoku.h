#ifndef SUDOKU_H
#define SUDOKU_H
#include <SFML/Graphics.hpp>
#include <iostream>


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

private:
	int jeuInitial[9][9]; // sudoku donn� au joueur, celle ci ne change pas 
	int jeuEnCours[9][9]; // sudoku que le joueur change quand il joue
	int jeuReference[9][9]; // sudoku fini, solution finale que doit atteindre le joueur
	int niveau; // le niveau de la grille pouvant aller de 1 (facile) � 3 (difficile)
	bool etat = false;// �tat de la grille, =true si la grille est compl�t�e


};

#endif // SUDOKU
#pragma once

