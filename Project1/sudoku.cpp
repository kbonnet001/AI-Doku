#include "Sudoku.h"

Sudoku::Sudoku(int niveau)
{
	if (niveau == 0) // mode manuel
	{
		// on ne fait rien pour le moment
	}
	else // niveau déjà tout prêt
	{
		genererJeu(niveau);
		copieTableau(jeuInitial, jeuEnCours);
	}
}

void Sudoku::genererJeu(int niveau)
{
	// à terme, génération automatique de grille de sudoku
	// Pour le moment, on va faire plus simple et donner dirrectement un tableau de jeu
	if (niveau == 1) // très facile
	{
		 int grille[9][9] = {{3, 4, 0, 2, 0, 9, 5, 6, 1}, {9,0,6,5,1,4,0,3,2}, {1,2,0,8,3,0,7,4,9}, {0,5,3,6,2,1,9,0,4}, {0,8,2,0,9,7,0,5,3}, {4,9,0,3,8,5,2,7,0}, {2,0,4,1,0,0,3,9,0}, {8,1,7,0,6,3,4,2,5}, {5,0,9,7,4,2,0,1,8}};
		 copieTableau(grille, jeuInitial);
	}
	else if (niveau == 2) // facile
	{
		int grille[9][9] = { {5,0,2,7,3,0,0,8,6}, {7,0,9,0,4,0,2,0,3}, {1,3,0,2,6,0,0,5,7}, {0,0,0,4,0,2,7,6,9}, {4,0,0,3,8,6,0,0,5}, {2,0,0,0,9,0,0,0,0}, {9,0,0,0,1,5,8,7,0}, {8,7,0,9,0,0,0,0,1}, {0,1,4,0,0,0,0,0,0} };
		copieTableau(grille, jeuInitial);
	}
	else if (niveau == 3) // facile
	{
		int grille[9][9] = { {0,1,0,5,2,0,4,3}, {0,0,8,0,0,6,0,0,0}, {5,0,3,7,9,0,2,0,0}, {0,2,7,0,0,9,0,0,5}, {0,3,6,2,4,0,0,0,7}, {9,0,4,0,7,3,0,6,0}, {0,7,0,0,8,0,0,1,0}, {0,0,0,9,6,0,7,0,4}, {0,0,0,3,0,0,6,0,0} };
		copieTableau(grille, jeuInitial);
	}
	else if (niveau == 4) // moyen
	{
		int grille[9][9] = { {0,0,0,3,0,0,7,0,0}, {0,0,7,4,0,9,0,1,0}, {6,4,0,0,2,7,5,0,0}, {1,0,0,0,0,0,0,7,5}, {7,0,0,0,0,0,0,0,0}, {4,8,9,7,1,5,0,0,0}, {8,0,4,6,0,3,0,0,0}, {0,0,0,8,4,0,6,9,0}, {0,6,1,0,0,0,4,0,0} };
		copieTableau(grille, jeuInitial);
	}

	else if (niveau == 5) // moyen
	{
		int grille[9][9] = { {0,5,7,0,0,0,0,0,6}, {3,0,0,0,0,0,2,1,8}, {2,0,4,0,0,0,0,0,0}, {0,0,9,0,1,0,0,2,0}, {8,3,0,0,0,2,0,0,0}, {0,0,0,4,8,0,5,3,0}, {4,0,0,0,0,0,9,0,2}, {0,6,0,9,0,4,0,0,0}, {9,0,8,0,6,5,0,0,4} };
		copieTableau(grille, jeuInitial);
	}
	else if (niveau == 6) // difficile
	{
		int grille[9][9] = { {8,6,0,0,0,0,0,0,0}, {0,0,0,0,0,5,0,0,7}, {0,0,0,6,8,0,0,5,4}, {0,3,0,0,9,0,1,0,0}, {5,0,6,0,0,0,0,0,0}, {9,0,0,7,0,4,0,0,0}, {0,2,9,0,7,0,3,0,0}, {0,0,0,3,0,0,0,2,6}, {0,0,0,0,5,6,0,0,0} };
		copieTableau(grille, jeuInitial);
	}

	else if (niveau == 7) // difficile
	{
		int grille[9][9] = { {4,1,5,0,0,0,0,6,0}, {9,2,0,0,0,0,3,0,4}, {7,0,0,0,0,0,0,0,0}, {0,7,0,0,9,0,0,0,1}, {0,0,0,5,2,7,0,4,0}, {5,0,9,0,0,0,0,2,0}, {0,0,6,4,0,0,0,1,8}, {0,0,0,0,0,0,4,0,6}, {2,0,0,9,0,6,0,0,3} };
		copieTableau(grille, jeuInitial);
	}

	else if (niveau == 8) // difficile
	{
		int grille[9][9] = { {0,8,0,3,7,0,0,0,0}, {0,0,3,0,0,0,0,0,0}, {0,0,7,0,4,0,2,0,0}, {1,0,0,0,0,0,0,0,8}, {0,0,0,0,0,0,4,3,7}, {8,0,9,0,0,0,0,0,2}, {0,0,0,8,0,0,6,0,0}, {5,6,0,0,0,9,0,0,0}, {0,0,0,0,0,2,0,4,0} };
		copieTableau(grille, jeuInitial);
	}


}

void Sudoku::copieTableau(int t1[9][9], int t2[9][9])
{
	// Permet de copier une tableau, t1 est la ref
	for (int i=0;i<9;i++)
		for (int j = 0; j < 9; j++)
		{
			t2[i][j] = t1[i][j];
		}
}

void Sudoku::ecrire(int k, int i, int j)
{
	if (jeuInitial[i][j] != 0)
	{
		cerr << "Vous ne pouvez pas écrire dans cette case"<< jeuInitial[i][j] << endl;
	}
	else
	{
		jeuEnCours[i][j] = k;
	}

}

bool Sudoku::estPresent(vector<int>& vecteur, int k)
{
	// Permet de verifier si un élément k est présent dans un vecteur
	auto it = std::find(vecteur.begin(), vecteur.end(), k);
	return it != vecteur.end();
}

void Sudoku::ecrireNote(int k, int i, int j)
{
	if (estPresent(noteSudoku[i][j], k) == false)
	{
		// Si la note qui vient d'être faite n'est pas encore écrite
		// On l'ajoute et on s'assure que les notes sont bien dans l'ordre croissant
		noteSudoku[i][j].push_back(k);
		sort(noteSudoku[i][j].begin(), noteSudoku[i][j].end());
	}
}

int Sudoku::avoirJeu(int i, int j )
{
	return jeuEnCours[i][j];
}

bool Sudoku::verifieSiJeuInital(int i, int j)
{
	return jeuEnCours[i][j] == jeuInitial[i][j];
}

void Sudoku::mettreAJourEtat()
{
	bool etatActuel = true;
	for (int i=0;i<9;i++)
		for (int j = 0; j < 9; j++)
		{
			if (jeuEnCours[i][j] == 0) // si une case est encore vide
			{
				etatActuel = false;
				break;
			}
		}
	etat = etatActuel;
}

bool Sudoku::avoirEtat()
{
	mettreAJourEtat();
	return etat;
}

vector<int> Sudoku::avoirNoteVecteur(int i, int j)
{
	return noteSudoku[i][j];
}

void Sudoku::creerJeuInitial()
{
	copieTableau(jeuEnCours, jeuInitial);
}