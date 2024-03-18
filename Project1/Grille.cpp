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
	// Permet de dessiner tous les �l�ments fixes de l'interface
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
	// Param�tres pour le cadre carr� o� sera la grille
	// Afin de bien visionner les 9 carr�es, on va dessiner 9 carr�s gris avec des contours noirs
	int k;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			// Pour la grille de jeu, on a besoin de 9 carr�s
			// Seule la position change
			carresJeu[i][j].setPosition(Vector2f(19 + i * (105 + 3), 235 + j * (105 + 3)));

			//ils ont tous la m�me couleur et la meme taille
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
	// Permet de dessiner tous les �l�ments boutons sur l'interface
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
	// R�solution automatique de la grille par l'IA
	// Cela permet notamment � la programmeuse (moi ^^) de v�rifier si l'IA arrive � r�soudre les grilles donn�es
	// Aucune interaction de l'utilisateur n'est n�cessaire

	if (boutonQuitter.boutonClique(mousePosition))
	{
		// L'utilisateur a cliqu� sur le bouton quitter pour fermer la page
		boutonQuitter.actionClique(window);
	}

}

void Grille :: actionGrilleManuel(RenderWindow& window, const::Vector2f& mousePosition)
{


	// 1e cas : 
	// Un clique gauche a �t� effectu� par l'utilisateur, on cherche � savoir quel bouton a �t� cliqu�
	if (mousePosition.y > 580 && mousePosition.y < 622)
	{
		for (int i = 0; i < 9; i++)
		{
			// On a trouv� o� on a cliqu�
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
		// Si l'utilisateur a cliqu� dans la grille de jeu, on va chercher � savoir dans quelle ligne : 
		for (int i = 0; i < 9; i++)
			// On cherche la ligne
			if ((mousePosition.y >= 235 + i * (33 + 3)) && (mousePosition.y <= 268 + i * (33 + 3)))
			{
				// On a trouv� la ligne, cherchons maintenant la case
				for (int j = 0; j < 9; j++)
				{
					if (cases[j][i].boutonClique(mousePosition))
					{
						// Retour ----------------
						cout << "cc je le carr� " << i << j << endl;
						Aidoku.avoirNote(j, i);
						//------------------------

						if (caseClique[0] != -1)// Si une case �tait cliqu�e avant, on la r� initialise
						{
							cases[caseClique[0]][caseClique[1]].changerCouleur(Color::White);
						}

						// On remplace ensuite par la nouvelle case
						caseClique[0] = j;
						caseClique[1] = i;
						cases[caseClique[0]][caseClique[1]].changerCouleur(couleurTurquoiseClair);
						// lorsque l'on a trouv� le bouton sur lequel l'utilisateur � cliquer, plus besoin de continuer
						break;
					}
				}
			}
	}

	else if (boutonQuitter.boutonClique(mousePosition))
	{
		// L'utilisateur a cliqu� sur le bouton quitter pour fermer la page
		boutonQuitter.actionClique(window);
	}

	else if (boutonSuivant.boutonClique(mousePosition))
	{
		cout << "yayayaya" << endl;
		if (iaDesign.savoirSiFinParagraphe() == true)
		{
			cout << "omg on est l�" << endl;
			// On est � la fin du paragraphe
			// Avant de passer � la ligne suivante
			// ie : le paragraphe suivant qui n'existe pas encore
			// On va faire la r�solution de la prochaine �tape par l'ia
			// Puis changer l'�tat du dialogue
			iaDesign.changerEtat(Aidoku.resolutionManuelle(sudoku));
			//iaDesign.ajouterTexte();
			// Maintenant on peut ajouter le texte
			//iaDesign.ajouterTexte();
			// Le paragraphe suivant a bien �t� ajout�
			// On peut passer au paragraphe suivant sans probl�me
		}
		boutonSuivant.actionClique(window, iaDesign);
	}
	else if (boutonPrecedent.boutonClique(mousePosition))
	{
		boutonPrecedent.actionClique(window, iaDesign);
	}

	else // si on a cliqu� nul part (pour le moment � corriger selon)
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
	// Un clique gauche a �t� effectu� par l'utilisateur, on cherche � savoir quel bouton a �t� cliqu�
	if (mousePosition.y > 580 && mousePosition.y < 622)
	{
		for (int i = 0; i < 9; i++)
		{
			// On a trouv� o� on a cliqu�
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
		// Si l'utilisateur a cliqu� dans la grille de jeu, on va chercher � savoir dans quelle ligne : 
		for (int i = 0; i < 9; i++)
			// On cherche la ligne
			if ((mousePosition.y >= 235 + i * (33 + 3)) && (mousePosition.y <= 268 + i * (33 + 3)))
			{
				// On a trouv� la ligne, cherchons maintenant la case
				for (int j = 0; j < 9; j++)
				{
					if (cases[j][i].boutonClique(mousePosition))
					{
						// Retour ----------------
						cout << "cc je le carr� " << i << j << endl;
						Aidoku.avoirNote(j, i);
						//------------------------

						if (caseClique[0] != -1)// Si une case �tait cliqu�e avant, on la r� initialise
						{
							cases[caseClique[0]][caseClique[1]].changerCouleur(Color::White);
						}

						// On remplace ensuite par la nouvelle case
						caseClique[0] = j;
						caseClique[1] = i;
						cases[caseClique[0]][caseClique[1]].changerCouleur(couleurTurquoiseClair);
						// lorsque l'on a trouv� le bouton sur lequel l'utilisateur � cliquer, plus besoin de continuer
						break;
					}
				}
			}
	}

	else if (boutonEffacer.boutonClique(mousePosition))
	{
		// On a cliqu� sur le bouton pour effacer
		boutonEffacer.changerClique(true);

		if (caseClique[0] != -1)
		{
			sudoku.ecrire(0, caseClique[0], caseClique[1]);
		}
	}

	else if (boutonValider.boutonClique(mousePosition))
	{
		// si on est bien dans le cas d'un niveau manuel et que l'on n'a pas encore valid�
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

			// 1e �tape de r�solution par l'IA
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
//	// Un clique gauche a �t� effectu� par l'utilisateur, on cherche � savoir quel bouton a �t� cliqu�
//	if (mousePosition.y > 580 && mousePosition.y < 622)
//	{
//		for (int i = 0; i < 9; i++)
//		{
//			// On a trouv� o� on a cliqu�
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
//		// Si l'utilisateur a cliqu� dans la grille de jeu, on va chercher � savoir dans quelle ligne : 
//		for (int i = 0; i < 9; i++)
//			// On cherche la ligne
//			if ((mousePosition.y >= 235 + i * (33 + 3)) && (mousePosition.y <= 268 + i * (33 + 3)))
//			{
//				// On a trouv� la ligne, cherchons maintenant la case
//				for (int j = 0; j < 9; j++)
//				{
//					if (cases[j][i].boutonClique(mousePosition))
//					{
//						// Retour ----------------
//						cout << "cc je le carr� " << i << j << endl;
//						Aidoku.avoirNote(j, i);
//						//------------------------
//
//						if (caseClique[0] != -1)// Si une case �tait cliqu�e avant, on la r� initialise
//						{
//							cases[caseClique[0]][caseClique[1]].changerCouleur(Color::White);
//						}
//
//						// On remplace ensuite par la nouvelle case
//						caseClique[0] = j;
//						caseClique[1] = i;
//						cases[caseClique[0]][caseClique[1]].changerCouleur(couleurTurquoiseClair);
//						// lorsque l'on a trouv� le bouton sur lequel l'utilisateur � cliquer, plus besoin de continuer
//						break;
//					}
//				}
//			}
//	}
//
//	else if (boutonQuitter.boutonClique(mousePosition))
//	{
//		// L'utilisateur a cliqu� sur le bouton quitter pour fermer la page
//		boutonQuitter.actionClique(window);
//	}
//	else // si on a cliqu� nul part (pour le moment � corriger selon)
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