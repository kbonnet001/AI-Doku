#include "IA.h"

IA::IA(Sudoku& sudoku)
{

	prendreNote(sudoku);
	for (int i=0;i<9;i++)
		for (int j = 0; j < 9; j++)
		{
			voirNoteConsole(i, j);
		}
	for (int i = 0; i < 30; i++) // sécurité pour éviter boucle infini
	{
		cout << " singleton évident : " << i << endl;
		singletonEvident(sudoku);
		if (sudoku.avoirEtat() == true)
		{
			break;
		}
		cout << " maintenant dernier chiffre restant : " << i << endl;
		dernierChiffrePossible(sudoku);
		if (sudoku.avoirEtat() == true)
		{
			break;
		}
		cout << " maintenant paires nues : " << i << endl;
		pairesNues(sudoku);
	}

	// 
	//int i = 0;
	//while (sudoku.avoirEtat() == false)
	//{
	//	cout << " singleton évident : " << i << endl;
	//	singletonEvident(sudoku);
	//	if (sudoku.avoirEtat() == true)
	//	{
	//		break;
	//	}
	//	cout << " maintenant dernier chiffre restant : " << i << endl;
	//	dernierChiffrePossible(sudoku);
	//	i += 1;
	//}
	//prendreNote(sudoku);

}

void IA::prendreNote(Sudoku& sudoku)
{
	// L'IA ecrit ses premières notes
	// à utliser seulement au tout début
	// ne pas s'en servir pour une mise à jour de note
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
	// Retourne toute les possibilités de la ligne/ce qu'il manque pour que la ligne soit complète
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
	// Retourne toute les possibilités de la colonne/ce qu'il manque pour que la colonne soit complète
	vector<int> noteColonne{ 1,2,3,4,5,6,7,8,9 }; // de base, on met toute les notes possibles
	for (int i = 0; i < 9; i++)
	{
		if (sudoku.avoirJeu(i, j) != 0)
		{
			retirerElementVecteur(sudoku.avoirJeu(i, j), noteColonne);
		}
	}
	return noteColonne;
}

vector<int> IA::regarderCarre(Sudoku& sudoku, int i, int j)
{
	// Retourne toute les possibilités du carre/ce qu'il manque pour que le carre soit complet
	vector<int> noteCarre{ 1,2,3,4,5,6,7,8,9 }; // de base, on met toute les notes possibles
	int a = i / 3;
	int b = j /3;
	for (int n=0+a*3;n<3+a*3;n++)
		for (int m = 0+b*3; m < 3+b*3; m++)
		{
			if (sudoku.avoirJeu(n, m) != 0)
			{
				retirerElementVecteur(sudoku.avoirJeu(n, m), noteCarre);
				//cout << "nm : " << n << m << endl;
				//cout << "yo je suis ij : " << i << j << " et noteLigne ";
				//for (int element : noteCarre)
				//{
				//	cout << element ;
				//}
				//cout << "" << endl;
			}
		}
	return noteCarre;
}

void IA::retirerElementVecteur(int k, vector<int>& vecteur)
{
	// Permet de retirer un élément k d'un vecteur
	auto it = std::find(vecteur.begin(), vecteur.end(), k);
	if (it != vecteur.end()) {
		vecteur.erase(it);
	}
}

vector<int> IA::compareNotes(vector<int> note1, vector<int> note2)
{
	// Permet de comparer 2 listes de note et ne garde que celles en commun
	// Retourne la liste des éléments communs au 2 listes
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
	// Permet de savoir si un chiffre est présent dans 2 listes différentes
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
	// Par sécurité, on vide entièrement le vecteur note de la case
	note[i][j].clear();
}

bool IA::estPresent(vector<int>& vecteur, int k) 
{
	// Permet de verifier si un élément k est présent dans un vecteur
	auto it = std::find(vecteur.begin(), vecteur.end(), k);
	return it != vecteur.end(); 
}

void IA::voirNoteConsole(int i, int j)
{
	cout << "i : " << i << " - j : " << j << " --";
	avoirNote(i, j);
	cout << "----" << endl;
}

bool IA::dernierChiffrePossibleLigne(Sudoku& sudoku)
{
	bool occurence = false;
	int m;

	// on regarde les lignes
	for (int i = 0; i < 9; i++)
	{
		vector<int> noteLigne = regarderLigne(sudoku, i);
		// on récupère les chiffres qu'il nous manque sur la ligne i
		for (int element : noteLigne)
		{
			for (int j = 0; j < 9; j++)
			{
				if (sudoku.avoirJeu(i, j) == 0 && estPresent(note[i][j], element) == true && occurence == false)
				{
					// première fois que l'on trouve l'element dans la ligne
					occurence = true; // on garde en mémoire que l'on a trouvé
					m = j; // On garde en mémoire la colonne où se trouve l'élément
				}
				else if (sudoku.avoirJeu(i, j) == 0 && estPresent(note[i][j], element) == true && occurence == true)
				{
					// seconde fois que l'on trouve l'element dans la ligne
					// la strategie ne peut être appliquée ici
					occurence = false; // on remet à jour
					break;// on quitte la boucle pour cet élément, rien ne sert de continuer
				}
			}
			if (occurence == true)
			{
				// si l'element k n'est présent qu'une seul fois dans la ligne, on l'écrit
				sudoku.ecrire(element, i, m);
				mettreAJourNote(sudoku.avoirJeu(i,m), i, m);
				cout << "Ligne - ecrit dans la case : " << i << m << " le chiffre : " << element << endl;
				return true;
			}
		}
	}
	// si on arrive ici c'est qu'on ne pouvait appliquée la stratégie sur aucune ligne
	cout << "rien à signaler (ligne)" << endl;
	return false;
}

bool IA::dernierChiffrePossibleColonne(Sudoku& sudoku)
{
	bool occurence = false;
	int n;
	// on regarde les colonnes
	for (int j = 0; j < 9; j++)
	{
		vector<int> noteColonne = regarderColonne(sudoku, j);
		// on récupère les chiffres qu'il nous manque sur la colonne j
		for (int element : noteColonne)
		{
			for (int i = 0; i < 9; i++)
			{
				if (sudoku.avoirJeu(i, j) == 0 && estPresent(note[i][j], element) == true && occurence == false)
				{
					// première fois que l'on trouve l'element dans la colonne
					occurence = true; // on garde en mémoire que l'on a trouvé
					n = i; // On garde en mémoire la colonne où se trouve l'élément
				}
				else if (sudoku.avoirJeu(i, j) == 0 &&  estPresent(note[i][j], element) == true && occurence == true)
				{
					// seconde fois que l'on trouve l'element dans la ligne
					// la strategie ne peut être appliquée ici
					occurence = false; // on remet à jour
					break;// on quitte la boucle pour cet élément, rien ne sert de continuer
				}
			}
			if (occurence == true)
			{
				// si l'element k n'est présent qu'une seul fois dans la colonne, on l'écrit
				sudoku.ecrire(element, n, j);
				mettreAJourNote(sudoku.avoirJeu(n, j), n, j);
				cout << "Colonne - ecrit dans la case : " << n << j << " le chiffre : " << element << endl;
				return true;
			}
		}
	}
	// si on arrive ici c'est qu'on ne pouvait appliquée la stratégie sur aucune colonne
	cout << "rien à signaler (colonne)" << endl;
	return false;
}

bool IA::dernierChiffrePossibleCarre(Sudoku& sudoku)
{
	bool occurence = false;
	int n;
	int m;
	// on regarde les carrées
	// On va de carré en carré
	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
		{
			// On prend des notes des possibilités du carré ab
			vector<int> noteCarre = regarderCarre(sudoku, a, b);
			// pour chaque k des notes possibles
			for (int element : noteCarre)
			{
				// On parcourt les cases du carre ab
				for (int i = a * 3; i < 3 + a * 3; i++)
				{
					for (int j = b * 3; j < 3 + b * 3; j++)
					{
						if (sudoku.avoirJeu(i, j) == 0 && estPresent(note[i][j], element) == true && occurence == false)
						{
							// première fois que l'on trouve l'element dans le carre
							occurence = true; // on garde en mémoire que l'on a trouvé
							n = i; // On garde en mémoire la ligne où se trouve l'élément
							m = j; // On garde en mémoire la colonne où se trouve l'élément
						}
						else if (sudoku.avoirJeu(i, j) == 0 && estPresent(note[i][j], element) == true && occurence == true)
						{
							// seconde fois que l'on trouve l'element dans la ligne
							// la strategie ne peut être appliquée ici
							occurence = false; // on remet à jour
							break;// on quitte la boucle pour cet élément, rien ne sert de continuer
						}
					}
					if (occurence == false)
					{
						break;
					}
				}
				// après avoir regardé tout le carre pour un element
				if (occurence == true)
				{
					// si l'element k n'est présent qu'une seul fois dans le carre, on l'écrit
					sudoku.ecrire(element, n, m);
					mettreAJourNote(sudoku.avoirJeu(n, m), n, m);
					return true;
				}
			}


		}
	// si on arrive ici c'est qu'on ne pouvait appliquée la stratégie sur aucune colonne
	cout << "rien à signaler (carre)" << endl;
	return false;
}

void IA::dernierChiffrePossible(Sudoku& sudoku)
{
	// Stratégie n°2 : 
	// Regarder si sur une ligne, une colonne ou un carré, 
	// il n'y a qu'un seul emplacement possible pour k
	bool strategieOk = false; // permet d'indiquer si la strategie a pu etre appliquée

	// On commence par regarder les lignes
	do
	{
		strategieOk = false; // initialisation
		if (dernierChiffrePossibleLigne(sudoku) == true)
		{
			strategieOk = true;
			break;
		}
		if (dernierChiffrePossibleColonne(sudoku) == true)
		{
			strategieOk = true;
			break;
		}
		if (dernierChiffrePossibleCarre(sudoku) == true)
		{
			strategieOk = true;
			break;
		}

	} while (strategieOk == true); // on recommence tant jusqu'à ce que la stratégie ne soit plus applicable nul part
}
	

void IA::actionIA(Sudoku& sudoku)
{
	//while (sudoku.avoirEtat() == false)
	{
		singletonEvident(sudoku);
		dernierChiffrePossible(sudoku);
	}
}

void IA::pairesNues(Sudoku& sudoku)
{
	// Stratégie n°3 : 
	// Regarder si sur une ligne, une colonne ou un carré, 
	// il existe des paires nues
	// Si oui, on regarde les autres chiffres de la ligne, colonne ou carre 
	// et on supprime les chiffres de la paire
	bool strategieOk = false; // permet d'indiquer si la strategie a pu etre appliquée

	// On commence par regarder les lignes
	do
	{
		strategieOk = false; // initialisation
		if (pairesNuesLigne(sudoku) == true)
		{
			strategieOk = true;
			break;
		}
		if (pairesNuesColonne(sudoku) == true)
		{
			strategieOk = true;
			break;
		}
		if (pairesNuesCarre(sudoku) == true)
		{
			strategieOk = true;
			break;
		}

	} while (strategieOk == true); // on recommence tant jusqu'à ce que la stratégie ne soit plus applicable nul part
}

bool IA::pairesNuesLigne(Sudoku& sudoku)
{
	// on regarde les lignes
	cout << "yo c'est les lignes" << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sudoku.avoirJeu(i, j) == 0 && note[i][j].size() == 2 && paireLigne[i][j]!=true)
			{
				cout << " voici une première paire en ij = " << i << j << " et la paire est : " << note[i][j][0] << note[i][j][1] << endl;
				// si la case est vide et qu'elle ne contient que 2 éléments
				// On garde de cote les ij
				// C'est une paire nue possible

				// On regarde ensuite dans les restes des cases si on a une autre paires 
				for (int p = j+1; p < 9; p++)
				{
					if (sudoku.avoirJeu(i, p) == 0 && note[i][p].size() == 2)
					{
						cout << " voici une 2e paire en ip = " << i << p << " et la paire est : " << note[i][p][0] << note[i][p][1] << endl;
						// si la case est vide et qu'elle ne contient que 2 éléments
						// C'est la 2e paire que l'on trouve
						// On verifie si c'est la même paire
						if (note[i][p] == note[i][j])
						{
							cout << "waouh une paire" << endl;
							// on a la meme paire ! 
							// Il faut maintenant supprimer les notes inutiles de la ligne
							// Les cases qui ne doivent pas être touchées sont ij et im
							// on regarde dans la ligne i
							paireLigne[i][j] = true;
							paireLigne[i][p] = true;
							for (int k = 0; k < 9; k++)
							{
								cout << "on regarde : note de la case ik = " << i << k << " contient = ";
								avoirNote(i, k);
								if (sudoku.avoirJeu(i, k) == 0 && estPresent(note[i][k], note[i][j][0]) && j != k && p != k)
								{
									cout << "j'ai trouvé " << note[i][j][0]<<endl;
									// on retire le premier élément de la paire
									retirerElementVecteur(note[i][j][0], note[i][k]);
									cout << "on regarde après avoir retiré: note de la case ik = " << i << k << " contient = ";
									avoirNote(i, k);
								}
								if (sudoku.avoirJeu(i, k) == 0 && estPresent(note[i][k], note[i][j][1]) && j != k && p != k)
								{
									cout << "j'ai trouvé " << note[i][j][1]<< endl;
									// on retire le second élément de la paire
									retirerElementVecteur(note[i][j][1], note[i][k]);
									cout << "on regarde après avoir retiré: note de la case ik = " << i << k << " contient = ";
									avoirNote(i, k);
								}
							}
							return true;
						}

					}
				}
			}
			
		}
	}
	return false;
}

bool IA::pairesNuesColonne(Sudoku& sudoku)
{

	// on regarde les colonnes
	cout << "yo c'est les colonnes" << endl;
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			if (sudoku.avoirJeu(i, j) == 0 && note[i][j].size() == 2 && paireColonne[i][j] != true)
			{
				// si la case est vide et qu'elle ne contient que 2 éléments
				// On garde de cote les ij
				// C'est une paire nue possible

				// On regarde ensuite dans les restes des cases si on a une autre paires 
				for (int q = i + 1; q < 9; q++)
				{
					if (sudoku.avoirJeu(q, j) == 0 && note[q][j].size() == 2)
					{
						cout << " voici une 2e paire en qj = " << q << j << " et la paire est : " << note[q][j][0] << note[q][j][1] << endl;
						// si la case est vide et qu'elle ne contient que 2 éléments
						// C'est la 2e paire que l'on trouve
						// On verifie si c'est la même paire
						if (note[q][j] == note[i][j])
						{
							cout << "waouh une paire" << endl;
							// on a la meme paire ! 
							paireColonne[i][j] = true;
							paireColonne[q][j] = true;
							// Il faut maintenant supprimer les notes inutiles de la ligne
							// Les cases qui ne doivent pas être touchées sont ij et im
							// on regarde dans la ligne i
							for (int k = 0; k < 9; k++)
							{
								cout << "on regarde : note de la case ik = " << i << k << " contient = ";
								avoirNote(i, k);
								if (sudoku.avoirJeu(k,j) == 0 && estPresent(note[k][j], note[i][j][0]) && i != k && q != k)
								{
									cout << "j'ai trouvé " << note[i][j][0] << endl;
									// on retire le premier élément de la paire
									retirerElementVecteur(note[q][j][0], note[k][j]);
									cout << "on regarde après avoir retiré: note de la case kj = " << k << j << " contient = ";
									avoirNote(k, j);
								}
								if (sudoku.avoirJeu(k, j) == 0 && estPresent(note[k][j], note[i][j][1]) && i != k && q != k)
								{
									cout << "j'ai trouvé " << note[i][j][0] << endl;
									// on retire le second élément de la paire
									retirerElementVecteur(note[q][j][1], note[k][j]);
									cout << "on regarde après avoir retiré: note de la case kj = " << k << j << " contient = ";
									avoirNote(k, j);
								}
							}
							return true;
						}

					}
				}
			}
			
		}
	}
	return false;
}


bool IA::pairesNuesCarre(Sudoku& sudoku)
{
	// on regarde les carrées
	cout << "yo c'est les carres" << endl;
	// On va de carré en carré
	for (int a = 0; a < 3; a++)
		for (int b = 0; b < 3; b++)
		{
			cout << "on est dans le carre ab = " << a << b << endl;
			for (int i = a * 3; i < 3 + a * 3; i++)
			{
				for (int j = b * 3; j < 3 + b * 3; j++)
				{
					cout << "on est dans la case ij = " << i << j << endl;
					if (sudoku.avoirJeu(i, j) == 0 && note[i][j].size() == 2 && paireCarre[i][j] != true)
					{
						cout << " voici une première paire en ij = " << i << j << " et la paire est : " << note[i][j][0] << note[i][j][1] << endl;
						// si la case est vide et qu'elle ne contient que 2 éléments
						// On garde de cote les ij
						// C'est une paire nue possible

						for (int n= i; n < 3 + a * 3; n++)
							for (int m= j; m < 3 + b * 3; m++) // on part de ij
							{
								cout << "on est dans la case nm = " << n << m << endl;
								cout << "n!=i : " << n<<i << " m!=j : " << m<<j << endl;
								if (sudoku.avoirJeu(n, m) == 0 && note[n][m].size() == 2)
								{
									if (n == i && m == j)
									{
										// si on est dans la même case on fait rien
										cout << "stop c'est pareil on fait rien !" << endl;
									}
									else // on peut
									{
										cout << " voici une 2e paire en nm = " << n << m << " et la paire est : " << note[n][m][0] << note[n][m][1] << endl;
										// si la case est vide et qu'elle ne contient que 2 éléments
										// C'est la 2e paire que l'on trouve
										// On verifie si c'est la même paire
										if (note[n][m] == note[i][j])
										{
											cout << "waouh une paire" << endl;
											// on a la meme paire ! 
											paireCarre[i][j] = true;
											paireCarre[n][m] = true;
											// Il faut maintenant supprimer les notes inutiles de la ligne
											// Les cases qui ne doivent pas être touchées sont ij et im
											// on regarde dans la ligne i
											for (int k = a * 3; k < 3 + a * 3; k++)
												for (int l = b * 3 ; l < 3 + b * 3; l++)
												{
													cout << "on regarde : note de la case kl = " << k << l << " contient = ";
													avoirNote(k, l);
													if (sudoku.avoirJeu(k, l) == 0 && estPresent(note[k][l], note[i][j][0]) && i != k && n != k && j != l && m != l)
													{
														cout << "j'ai trouvé " << note[i][j][0] << endl;
														// on retire le premier élément de la paire
														retirerElementVecteur(note[i][j][0], note[k][l]);
														cout << "on regarde après avoir retiré: note de la case kl = " << k << l << " contient = ";
														avoirNote(k, l);
													}
													if (sudoku.avoirJeu(k, l) == 0 && estPresent(note[k][l], note[i][j][1]) && i != k && n != k && j != l && m != l)
													{
														cout << "j'ai trouvé " << note[i][j][1] << endl;
														// on retire le premier élément de la paire
														retirerElementVecteur(note[i][j][1], note[k][l]);
														cout << "on regarde après avoir retiré: note de la case kl = " << k << l << " contient = ";
														avoirNote(k, l);
													}
												}
											return true;
										}
									}
									

								}
							}
						

					}
					
				}
			}
		}
	return false;
}
