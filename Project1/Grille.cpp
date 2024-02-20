#include "Grille.h"

Grille::Grille()
{
	// Défaut
}

void Grille::drawStatique(RenderWindow& window)
{
	// Permet de dessiner tous les éléments fixes de l'interface
	drawGrilleJeu(window);
	drawCase(window);
	drawBoutonClose(window);
}

void Grille::drawGrilleJeu(RenderWindow& window)
{
	// Paramètres pour le cadre carré où sera la grille
	// Afin de bien visionner les 9 carrées, on va dessiner 9 carrés gris avec des contours noirs
	int k;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			// Pour la grille de jeu, on a besoin de 9 carrés
			// Seule la position change
			carresJeu[i][j].setPosition(Vector2f(19 + i * (105 + 3), 235 + j * (105 + 3)));

			//ils ont tous la même couleur et la meme taille
			carresJeu[i][j].setFillColor(couleurTurquoise);
			carresJeu[i][j].setOutlineColor(Color::Black);
			carresJeu[i][j].setOutlineThickness(3.f);
			carresJeu[i][j].setSize(dimensionCadreJeu);

			window.draw(carresJeu[i][j]);
		}
}

void Grille::drawCase(RenderWindow& window)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
		{
			cases[i][j].configuration(Vector2f(19 + i * (3 + 33), 235 + j * (3 + 33)));
			cases[i][j].ecrireValeurCase(sudoku.avoirJeu(i, j));
			if (sudoku.verifieSiJeuInital(i, j) == false)
			{
				cases[i][j].changerCouleurTexte(couleurRouge);
			}
			(cases[i][j]).draw(window);
		}
}

BoutonEcrire Grille::avoirBoutonEcrire(int i)
{
	return nums[i];
}

void Grille::drawBoutons(RenderWindow& window)
{
	// Permet de dessiner tous les éléments boutons sur l'interface
	for (int i = 0; i < 9; i++)
	{
		nums[i].configuration(i+1, Vector2f(18.31 + i * (33.93 + 2.48), 584.3));
		nums[i].draw(window);
	}
}

void Grille::drawBoutonClose(RenderWindow& window)
{
	boutonQuitter.configuration(Vector2f(35.f, 743.f));
	boutonQuitter.draw(window);
}

void Grille::ActionGrille(RenderWindow& window,const::Vector2f& mousePosition)
{

	// L'action grille est pour jouer en tant qu'utilisateur, ne fait pas intervenir d'IA
	// Un clique droit a été effectué par l'utilisateur, on cherche à savoir quel bouton a été cliqué
	if (mousePosition.y > 580 && mousePosition.y < 622)
	{
		int k = 0;
		// L'utilisateur est en train de cliquer sur la barre des boutons Ecrire
		// On vérifie pour chaque bouton Ecrire qui a été cliqué
		for (int i = 0; i < 9; i++)
		{
			if (nums[i].boutonClique(mousePosition)==true)
			{
				k = i; // on garde de cote qui a été cliqué
				// lorsque l'on a trouvé le bouton sur lequel l'utilisateur à cliquer, plus besoin de contienuer
				break;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (i == k) // On change le bool clique de celui qu'on a cliqué
			{
				nums[i].changerClique(true);
				valeurClique=nums[i].avoirChiffre();
				
				if (caseClique[0] != -1)
				{
					sudoku.ecrire(nums[i].avoirChiffre(), caseClique[0], caseClique[1]);
					//cases[caseClique[0]][caseClique[1]].ecrireValeurCase(nums[i].avoirChiffre());
				}
			}
			else // on fait en sorte que les autres soit bien faux
				nums[i].changerClique(false);
			nums[i].actionClique(window); // On fait l'action du bouton
		}
	}

	else if (mousePosition.y > 230 && mousePosition.y<565)
	{
		// Si l'utilisateur a cliqué dans la grille de jeu, on va chercher à savoir dans quelle ligne : 
		for (int i =0;i<9;i++)
			if ((mousePosition.y >= 235+i*(33+3)) && (mousePosition.y <= 268+i * (33 + 3)))
			{
				cout << "olalala" << endl;
				// On a trouvé la ligne, cherchons maintenant la case
				for (int j = 0; j < 9; j++)
				{
					if (cases[j][i].boutonClique(mousePosition))
					{
						cout << "cc je le carré " << i << j << endl;
						Aidoku.avoirNote(j, i);
						if (caseClique[0] != -1)// Si une case était cliquée avant, on la ré initialise
						{
							cases[caseClique[0]][caseClique[1]].changerCouleur(Color::White);
						}
						caseClique[0] = j;
						caseClique[1] = i;
						cases[caseClique[0]][caseClique[1]].changerCouleur(couleurTurquoiseClair);
						// lorsque l'on a trouvé le bouton sur lequel l'utilisateur à cliquer, plus besoin de continuer
						break;
					}
				}
			}
	}

	else if (boutonQuitter.boutonClique(mousePosition))
	{
		// L'utilisateur a cliqué sur le bouton quitter pour fermer la page
		boutonQuitter.actionClique(window);
	}
	else // si on a cliqué nul part (pour le moment à corriger selon)
	{
		cout << "ola macarena" << endl;
		for (int i = 0; i < 9; i++)
		{
			nums[i].changerClique(false);
			nums[i].actionClique(window);
		}
		//cases[caseClique[0], caseClique[1]]->changerCouleur(Color::White, Color::Black);
		//caseClique[0] = -1;
		//caseClique[1] = -1;
		//marche pas '^'
	}
}

void Grille::ActionGrilleIA(RenderWindow& window, const::Vector2f& mousePosition)
{
	//Aidoku.actionIA(sudoku);
	// L'action grille est pour jouer en tant qu'utilisateur, ne fait pas intervenir d'IA
	// Un clique droit a été effectué par l'utilisateur, on cherche à savoir quel bouton a été cliqué
	if (mousePosition.y > 580 && mousePosition.y < 622)
	{
		int k = 0;
		// L'utilisateur est en train de cliquer sur la barre des boutons Ecrire
		// On vérifie pour chaque bouton Ecrire qui a été cliqué
		for (int i = 0; i < 9; i++)
		{
			if (nums[i].boutonClique(mousePosition) == true)
			{
				k = i; // on garde de cote qui a été cliqué
				// lorsque l'on a trouvé le bouton sur lequel l'utilisateur à cliquer, plus besoin de contienuer
				break;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			if (i == k) // On change le bool clique de celui qu'on a cliqué
			{
				nums[i].changerClique(true);
				valeurClique = nums[i].avoirChiffre();

				if (caseClique[0] != -1)
				{
					sudoku.ecrire(nums[i].avoirChiffre(), caseClique[0], caseClique[1]);
					//cases[caseClique[0]][caseClique[1]].ecrireValeurCase(nums[i].avoirChiffre());
				}
			}
			else // on fait en sorte que les autres soit bien faux
				nums[i].changerClique(false);
			nums[i].actionClique(window); // On fait l'action du bouton
		}
	}

	else if (mousePosition.y > 230 && mousePosition.y < 565)
	{
		// Si l'utilisateur a cliqué dans la grille de jeu, on va chercher à savoir dans quelle ligne : 
		for (int i = 0; i < 9; i++)
			if ((mousePosition.y >= 235 + i * (33 + 3)) && (mousePosition.y <= 268 + i * (33 + 3)))
			{
				cout << "olalala" << endl;
				// On a trouvé la ligne, cherchons maintenant la case
				for (int j = 0; j < 9; j++)
				{
					if (cases[j][i].boutonClique(mousePosition))
					{
						cout << "cc je le carré " << i << j << endl;
						Aidoku.avoirNote(j, i);
						if (caseClique[0] != -1)// Si une case était cliquée avant, on la ré initialise
						{
							cases[caseClique[0]][caseClique[1]].changerCouleur(Color::White);
						}
						caseClique[0] = j;
						caseClique[1] = i;
						cases[caseClique[0]][caseClique[1]].changerCouleur(couleurTurquoiseClair);
						// lorsque l'on a trouvé le bouton sur lequel l'utilisateur à cliquer, plus besoin de continuer
						break;
					}
				}
			}
	}

	else if (boutonQuitter.boutonClique(mousePosition))
	{
		// L'utilisateur a cliqué sur le bouton quitter pour fermer la page
		boutonQuitter.actionClique(window);
	}
	else // si on a cliqué nul part (pour le moment à corriger selon)
	{
		cout << "ola macarena" << endl;
		for (int i = 0; i < 9; i++)
		{
			nums[i].changerClique(false);
			nums[i].actionClique(window);
		}
		//cases[caseClique[0], caseClique[1]]->changerCouleur(Color::White, Color::Black);
		//caseClique[0] = -1;
		//caseClique[1] = -1;
		//marche pas '^'
	}
}