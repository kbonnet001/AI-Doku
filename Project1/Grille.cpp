#include "Grille.h"

Grille::Grille()
{
	// si on est en mode auto --> resolution de la grille par l'IA avant tout affichage
	if (niveauGrille!=0)
	{
		Aidoku.changerActivation(true);
		Aidoku.resolution(sudoku);
	}
}
// --------------------------------------- DESSINER L'INTERFACE ---------------------------------------
void Grille::drawStatique(RenderWindow& window)
{
	// Permet de dessiner tous les éléments fixes de l'interface
	iaDesign.afficherIA(window);
	drawGrilleJeu(window);
	drawCase(window);
	drawBoutonClose(window);

	if (niveauGrille == 0) // mode manuel
	{
		drawBoutonEffacer(window);
		drawBoutonValider(window);
		drawBoutonNav(window);
	}
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
			if (cases[i][j].avoirValeur() == 0)
			{
				cases[i][j].configurationNote(Vector2f(19 + i * (3 + 33), 235 + j * (3 + 33)));
				cases[i][j].mettreAJourNoteCase(Aidoku.avoirVecteurNote(i, j));
			}
			
			if (sudoku.verifieSiJeuInital(i, j) == false)
			{
				cases[i][j].changerCouleurTexte(couleurRouge);
			}
			(cases[i][j]).draw(window);
		}
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

void Grille::drawBoutonEffacer(RenderWindow& window)
{
	boutonEffacer.configuration(Vector2f(18.f, 655.f));
	boutonEffacer.draw(window);
}

void Grille::drawBoutonValider(RenderWindow& window)
{
	boutonValider.configuration(Vector2f(199.f, 655.f));
	boutonValider.draw(window);
}

void Grille::drawBoutonClose(RenderWindow& window)
{
	boutonQuitter.configuration(Vector2f(35.f, 743.f));
	boutonQuitter.draw(window);
}

void Grille::drawBoutonNav(RenderWindow& window)
{
	boutonSuivant.configuration(Vector2f(232.f, 176.f), EtatBouton::Suivant);
	boutonSuivant.draw(window);

	boutonPrecedent.configuration(Vector2f(16.f, 176.f), EtatBouton::Precedent);
	boutonPrecedent.draw(window);
}

BoutonEcrire Grille::avoirBoutonEcrire(int i)
{
	return nums[i];
}

// --------------------------------------- ACTION GRILLE ---------------------------------------

void Grille::actionGrille(RenderWindow& window, const::Vector2f& mousePosition)
{
	if (niveauGrille == 0) // mode manuel
	{
		//while (boutonValider.avoirClique() ==false)
		//{
		//	actionGrilleManuelInitial(window, mousePosition);
		//}
		
		// L'action grille est pour jouer en tant qu'utilisateur, ne fait pas intervenir d'IA
		if (boutonValider.avoirClique() == false)
		{
			actionGrilleManuelInitial(window, mousePosition);
		}
		else
		{
			actionGrilleManuel(window, mousePosition);
		}
		
		
	}
	else // mode auto, test du niv de l'IA
	{
		actionGrilleIA(window, mousePosition);
	}
}

void Grille::actionGrilleIA(RenderWindow& window, const::Vector2f& mousePosition)
{
	// Résolution automatique de la grille par l'IA
	// Cela permet notamment à la programmeuse (moi ^^) de vérifier si l'IA arrive à résoudre les grilles données
	// Aucune interaction de l'utilisateur n'est nécessaire

	if (boutonQuitter.boutonClique(mousePosition))
	{
		// L'utilisateur a cliqué sur le bouton quitter pour fermer la page
		boutonQuitter.actionClique(window);
	}

}

void Grille :: actionGrilleManuel(RenderWindow& window, const::Vector2f& mousePosition)
{


	// 1e cas : 
	// Un clique gauche a été effectué par l'utilisateur, on cherche à savoir quel bouton a été cliqué
	if (mousePosition.y > 580 && mousePosition.y < 622)
	{
		for (int i = 0; i < 9; i++)
		{
			// On a trouvé où on a cliqué
			if (nums[i].boutonClique(mousePosition) == true)
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
			// On cherche la ligne
			if ((mousePosition.y >= 235 + i * (33 + 3)) && (mousePosition.y <= 268 + i * (33 + 3)))
			{
				// On a trouvé la ligne, cherchons maintenant la case
				for (int j = 0; j < 9; j++)
				{
					if (cases[j][i].boutonClique(mousePosition))
					{
						// Retour ----------------
						cout << "cc je le carré " << i << j << endl;
						Aidoku.avoirNote(j, i);
						//------------------------

						if (caseClique[0] != -1)// Si une case était cliquée avant, on la ré initialise
						{
							cases[caseClique[0]][caseClique[1]].changerCouleur(Color::White);
						}

						// On remplace ensuite par la nouvelle case
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

	else if (boutonSuivant.boutonClique(mousePosition))
	{
		cout << "yayayaya" << endl;
		if (iaDesign.savoirSiFinParagraphe() == true)
		{
			cout << "omg on est là" << endl;
			// On est à la fin du paragraphe
			// Avant de passer à la ligne suivante
			// ie : le paragraphe suivant qui n'existe pas encore
			// On va faire la résolution de la prochaine étape par l'ia
			// Puis changer l'état du dialogue
			iaDesign.changerEtat(Aidoku.resolutionManuelle(sudoku));
			//iaDesign.ajouterTexte();
			// Maintenant on peut ajouter le texte
			//iaDesign.ajouterTexte();
			// Le paragraphe suivant a bien été ajouté
			// On peut passer au paragraphe suivant sans problème
		}
		boutonSuivant.actionClique(window, iaDesign);
	}
	else if (boutonPrecedent.boutonClique(mousePosition))
	{
		boutonPrecedent.actionClique(window, iaDesign);
	}

	else // si on a cliqué nul part (pour le moment à corriger selon)
	{
		cout << "ola macarena" << endl;
		for (int i = 0; i < 9; i++)
		{
			nums[i].changerClique(false);
			nums[i].actionClique(window);
		}
		boutonEffacer.changerClique(false);
	}
}


void Grille::actionGrilleManuelInitial(RenderWindow& window, const::Vector2f& mousePosition)
{
	// 1e cas : 
	// Un clique gauche a été effectué par l'utilisateur, on cherche à savoir quel bouton a été cliqué
	if (mousePosition.y > 580 && mousePosition.y < 622)
	{
		for (int i = 0; i < 9; i++)
		{
			// On a trouvé où on a cliqué
			if (nums[i].boutonClique(mousePosition) == true)
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
			// On cherche la ligne
			if ((mousePosition.y >= 235 + i * (33 + 3)) && (mousePosition.y <= 268 + i * (33 + 3)))
			{
				// On a trouvé la ligne, cherchons maintenant la case
				for (int j = 0; j < 9; j++)
				{
					if (cases[j][i].boutonClique(mousePosition))
					{
						// Retour ----------------
						cout << "cc je le carré " << i << j << endl;
						Aidoku.avoirNote(j, i);
						//------------------------

						if (caseClique[0] != -1)// Si une case était cliquée avant, on la ré initialise
						{
							cases[caseClique[0]][caseClique[1]].changerCouleur(Color::White);
						}

						// On remplace ensuite par la nouvelle case
						caseClique[0] = j;
						caseClique[1] = i;
						cases[caseClique[0]][caseClique[1]].changerCouleur(couleurTurquoiseClair);
						// lorsque l'on a trouvé le bouton sur lequel l'utilisateur à cliquer, plus besoin de continuer
						break;
					}
				}
			}
	}

	else if (boutonEffacer.boutonClique(mousePosition))
	{
		// On a cliqué sur le bouton pour effacer
		boutonEffacer.changerClique(true);

		if (caseClique[0] != -1)
		{
			sudoku.ecrire(0, caseClique[0], caseClique[1]);
		}
	}

	else if (boutonValider.boutonClique(mousePosition))
	{
		// si on est bien dans le cas d'un niveau manuel et que l'on n'a pas encore validé
		if (niveauGrille == 0)
		{
			boutonValider.changerClique(true);

			// On fait des changements au niveau de la grille
			sudoku.creerJeuInitial();
			for (int i = 0; i < 9; i++)
				for (int j = 0; j < 9; j++)
				{
					cases[i][j].changerCouleurTexte(Color::Black);
				}

			// On fait des changements avec l'IA

			// 1e étape de résolution par l'IA
			// iaDesign.avoirGestionDialogue().ajouterTexteNote(true);
			Aidoku.prendreNote(sudoku, true);

			iaDesign.changerEtat(EtatDialogue::Note);
			//iaDesign.ajouterTexte();
			
			// --> Doit passer au prochain paragraphe
			iaDesign.paragrapheSuivant();
		}
	}
	else if (boutonSuivant.boutonClique(mousePosition))
	{
		boutonSuivant.actionClique(window, iaDesign);
	}
	else if (boutonPrecedent.boutonClique(mousePosition))
	{
		boutonPrecedent.actionClique(window, iaDesign);
	}
}

//void Grille::actionGrilleManuel(RenderWindow& window, const::Vector2f& mousePosition)
//{
//	// L'action grille est pour jouer en tant qu'utilisateur, ne fait pas intervenir d'IA
//
//	// 1e cas : 
//	// Un clique gauche a été effectué par l'utilisateur, on cherche à savoir quel bouton a été cliqué
//	if (mousePosition.y > 580 && mousePosition.y < 622)
//	{
//		for (int i = 0; i < 9; i++)
//		{
//			// On a trouvé où on a cliqué
//			if (nums[i].boutonClique(mousePosition) == true)
//			{
//				nums[i].changerClique(true);
//				valeurClique = nums[i].avoirChiffre();
//
//				if (caseClique[0] != -1)
//				{
//					sudoku.ecrire(nums[i].avoirChiffre(), caseClique[0], caseClique[1]);
//					//cases[caseClique[0]][caseClique[1]].ecrireValeurCase(nums[i].avoirChiffre());
//				}
//			}
//
//			else // on fait en sorte que les autres soit bien faux
//				nums[i].changerClique(false);
//			nums[i].actionClique(window); // On fait l'action du bouton
//		}
//	}
//
//	else if (mousePosition.y > 230 && mousePosition.y < 565)
//	{
//		// Si l'utilisateur a cliqué dans la grille de jeu, on va chercher à savoir dans quelle ligne : 
//		for (int i = 0; i < 9; i++)
//			// On cherche la ligne
//			if ((mousePosition.y >= 235 + i * (33 + 3)) && (mousePosition.y <= 268 + i * (33 + 3)))
//			{
//				// On a trouvé la ligne, cherchons maintenant la case
//				for (int j = 0; j < 9; j++)
//				{
//					if (cases[j][i].boutonClique(mousePosition))
//					{
//						// Retour ----------------
//						cout << "cc je le carré " << i << j << endl;
//						Aidoku.avoirNote(j, i);
//						//------------------------
//
//						if (caseClique[0] != -1)// Si une case était cliquée avant, on la ré initialise
//						{
//							cases[caseClique[0]][caseClique[1]].changerCouleur(Color::White);
//						}
//
//						// On remplace ensuite par la nouvelle case
//						caseClique[0] = j;
//						caseClique[1] = i;
//						cases[caseClique[0]][caseClique[1]].changerCouleur(couleurTurquoiseClair);
//						// lorsque l'on a trouvé le bouton sur lequel l'utilisateur à cliquer, plus besoin de continuer
//						break;
//					}
//				}
//			}
//	}
//
//	else if (boutonQuitter.boutonClique(mousePosition))
//	{
//		// L'utilisateur a cliqué sur le bouton quitter pour fermer la page
//		boutonQuitter.actionClique(window);
//	}
//	else // si on a cliqué nul part (pour le moment à corriger selon)
//	{
//		cout << "ola macarena" << endl;
//		for (int i = 0; i < 9; i++)
//		{
//			nums[i].changerClique(false);
//			nums[i].actionClique(window);
//		}
//		boutonEffacer.changerClique(false);
//
//	}
//}