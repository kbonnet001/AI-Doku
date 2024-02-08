#include "IA.h"

IA::IA(Sudoku& sudoku)
{
	prendreNote(sudoku);
	//dernierChiffrePossible(sudoku);
	for (int i=0;i<9;i++)
		for (int j = 0; j < 9; j++)
		{
			voirNoteConsole(i, j);
		}
	//prendreNote(sudoku);

	while (sudoku.avoirEtat() == false)
	{
		singletonEvident(sudoku);
	}
}

void IA::prendreNote(Sudoku& sudoku)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			// on parcourt toute les cases
			if (sudoku.avoirJeu(i, j) == 0)
			{
				// si la case est vide, on va regarder pour pouvoir mettre des notes
				note[i][j] = regarderLigne(sudoku, i);
				note[i][j] = compareNotes(note[i][j], regarderColonne(sudoku, j));
				note[i][j] = compareNotes(note[i][j], regarderCarre(sudoku, i, j));
				voirNoteConsole(i, j);
				cout << " je suis " << i << j << " et ma taille est de " << note[i][j].size() << endl;
			}
		}
}

vector<int> IA::regarderLigne(Sudoku& sudoku, int i)
{
	vector<int> noteLigne{ 1,2,3,4,5,6,7,8,9 }; // de base, on met toute les notes possibles
	for (int j = 0; j < 9; j++)
	{
		if (sudoku.avoirJeu(i, j) != 0)
		{
			retirerElementVecteur(sudoku.avoirJeu(i, j), noteLigne);
		}
	}
	return noteLigne;
}

vector<int> IA::regarderColonne(Sudoku& sudoku, int j)
{
	vector<int> noteLigne{ 1,2,3,4,5,6,7,8,9 }; // de base, on met toute les notes possibles
	for (int i = 0; i < 9; i++)
	{
		if (sudoku.avoirJeu(i, j) != 0)
		{
			retirerElementVecteur(sudoku.avoirJeu(i, j), noteLigne);
		}
	}
	return noteLigne;
}

vector<int> IA::regarderCarre(Sudoku& sudoku, int i, int j)
{
	vector<int> noteLigne{ 1,2,3,4,5,6,7,8,9 }; // de base, on met toute les notes possibles
	int a = i / 3;
	int b = j /3;
	for (int n=0+a*3;n<3+a*3;n++)
		for (int m = 0+b*3; m < 3+b*3; m++)
		{
			if (sudoku.avoirJeu(n, m) != 0)
			{
				retirerElementVecteur(sudoku.avoirJeu(n, m), noteLigne);
				cout << "nm : " << n << m << endl;
				cout << "yo je suis ij : " << i << j << " et noteLigne ";
				for (int element : noteLigne)
				{
					cout << element ;
				}
				cout << "" << endl;
			}
		}
	return noteLigne;
}

void IA::retirerElementVecteur(int k, vector<int>& vecteur)
{
	auto it = std::find(vecteur.begin(), vecteur.end(), k);
	if (it != vecteur.end()) {
		vecteur.erase(it);
	}
}

vector<int> IA::compareNotes(vector<int> note1, vector<int> note2)
{
	vector<int> noteCompare;
	for (int k = 1; k < 10; k++)
	{
		if (chiffrePresentDansLesDeux(note1, note2, k))
			noteCompare.push_back(k);
	}
	return noteCompare;
}

bool IA::chiffrePresentDansLesDeux(vector<int>& vect1, vector<int>& vect2, int chiffre)
{
	return (find(vect1.begin(), vect1.end(), chiffre) != vect1.end() &&
		find(vect2.begin(), vect2.end(), chiffre) != vect2.end());
}

void IA::avoirNote(int i, int j)
{
	for (int element : note[i][j]) {
		std::cout << element << " ";
	}
	cout<< "" << endl;
}

void IA::singletonEvident(Sudoku& sudoku)
{
	// Permet de faire la statégie la plus simple : 
	// Si une case ne contient qu'un seul chiffre en note
	// Alors c'est que c'est le bon chiffre
	// Il faut alors compléter la grille de sudoku
	for (int i=0; i<9;i++)
		for (int j = 0; j < 9; j++)
		{
			cout << " je suis " << i << j << " et ma taille est de " << note[i][j].size() << endl;
			if (note[i][j].size() == 1)
			{
				// Si la liste note de la case ne contient qu'un seul élément
				sudoku.ecrire(note[i][j][0], i, j);
				// On met à jour de manière intelligente les notes
				mettreAJourNote(note[i][j][0], i, j);
			}
		}
}

void IA::mettreAJourNote(int k, int i, int j)
{
	// Quand l'IA écrit un chiffre k dans une case i j 
	// Elle doit mettre a jour ses notes
	// Elle le fait de manière statégique
	// il faut enlever tous les k note de la ligne i 
	for (int b = 0; b < 9; b++)
	{
		if (estPresent(note[i][b], k))
		{
			retirerElementVecteur(k, note[i][b]);
		}
	}

	// il faut enlever tous les k note de la colonne j
	for (int a = 0; a < 9; a++)
	{
		if (estPresent(note[a][j], k))
		{
			retirerElementVecteur(k, note[a][j]);
		}
	}
	// il faut enlever tous les k note du carre de la case i j 
	int a = i /3;
	int b = j /3;
	for (int n = 0 + a * 3; n < 3 + a * 3; n++)
		for (int m = 0 + b * 3; m < 3 + b * 3; m++)
		{
			if (estPresent(note[n][m], k))
			{
				retirerElementVecteur(k, note[n][m]);
			}
		}
}

bool IA::estPresent(vector<int>& vecteur, int k) 
{
	auto it = std::find(vecteur.begin(), vecteur.end(), k);
	return it != vecteur.end(); 
}

void IA::voirNoteConsole(int i, int j)
{
	cout << "i : " << i << " - j : " << j << " --";
	avoirNote(i, j);
	cout << "----" << endl;
}

//void IA::dernierChiffrePossible(Sudoku& sudoku)
//{
//	// Stratégie n°2 : 
//	// Regarder si sur une ligne, une colonne ou un carré, 
//	// il n'y a qu'un seul emplacement possible pour k
//	for (int i = 0; i < 9; i++)
//	{
//		vector<int> noteLigne = regarderLigne(sudoku, i);
//		// on récupère les chiffres qu'il nous manque sur la ligne i
//		for (int element : noteLigne)
//		{
//
//		}
//
//
//	}
//
//}