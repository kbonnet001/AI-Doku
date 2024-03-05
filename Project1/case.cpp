#include "Case.h"

Case::Case()
{
    // Défaut
    ecritureNoteString = savoirTexteNote();
}

void Case::configuration(Vector2f position)
{
    // Permet de configurer la case
    carre.setPosition(Vector2f(1.f, 1.f));
    carre.setSize(dimension);
    carre.setFillColor(couleur);
    carre.setPosition(position);

    // Permet de mettre le texte de la case
    ecriture.ConfigurationTexte(16, savoirChiffre(), position, carre);

}

void Case::configurationNote(Vector2f position)
{
    // On prépare ensuite l'écriture des notes
    ecritureNote.ConfigurationTexteNoteLigne(8, savoirTexteNote(), position);

 //   for (int m = 0; m < 3; m++)
 //       for (int n = 0; n < 3; n++)
 //       {
 ///*           if (m == 2 && n == 2)
 //           {
 //               break;
 //           }*/
 //           cout << "--" << endl;
 //           cout << "n = " << n << " et m = " << m << endl;
 //           cout << "k = " << n + 1 + 3 * m << endl;
 //           cout << "donc savoirChiffreNote(n + 1 + 3 * m) = " << savoirChiffreNote(n + 1 + 3 * m) << endl;
 //           cout << "on regarde maintenant la position : " << position.x + 11 * n << " et " << position.y + 11 * m << endl;
 //           ecritureCases[n  + 3 * m].ConfigurationTexteNote(8, "2", Vector2f(position.x + 11 * n, position.y + 11 * m));
 //          
 //           ecritureCases[n + 3 * m].avoirTexteTest();
 //           //
 //           for (int i = 0; i < 9; i++)
 //           {
 //               cout << "on parcourt la liste, i = " << i << endl;
 //               ecritureCases[i].avoirTexteTest();
 //           }
 //       }
}

void Case::ecrireValeurCase(int chiffre)
{
    // Pour écrire dans la case, on change la valeur de la case --> chiffre 
    // Le chiffre est donné par le bouton sur lequel l'utilisateur clique
    valeur = chiffre;
}

void Case::effacerValeurCase()
{
    // Si on efface la valeur de la case, alors valeur --> 0
    valeur = 0;
}

string Case::savoirChiffre()
{
    // Retourne le texte à écrire dans la case
    // Si valeur = 0 alors la case doit être vide
    if (valeur == 0)
    {
        return " ";
    }
    else if (valeur >= 1 && valeur <= 9)
    {
        return to_string(static_cast<int>(valeur));
    }
    else // valeur a un valeur abérante
    {
        // Gestion de l'erreur si le chargement de la police échoue
        std::cerr << "Erreur, la valeur de la case n'est correcte (<0 ou >=10)" << std::endl;
    }
}

string Case::savoirTexteNote()
{
    // retourne ce que l'on va écrire dans la case
    String ecriture="";
    for (int i = 0; i < 3; i++)
    {
        ecriture += " ";
        for (int j = 0; j < 3; j++)
        {
            ecriture += " " + savoirChiffreNote(j + 1 + 3 * i) + "  ";
            if (j == 2)
            {
                ecriture += "\n";
            }
        }
    }
        
    return ecriture;




    // test où on s'en fou
    //return to_string(static_cast<int>(k));
}

string Case::savoirChiffreNote(int k)
{
    // Retourne le texte à écrire en note dans la case
    // Si k n'est pas dans les notes, on écrit pas
    if (valeur != 0)
    {
        return " ";
    }
    else if (estPresent(noteCase,k))
    {
        return to_string(static_cast<int>(k));
    }
    else 
    {
        return " ";
    }

}

void Case::draw(RenderWindow& window)
{
    window.draw(carre);
    if (valeur == 0)
    {
        ecritureNote.drawTexte(window);
    }
    else // il y a un chiffre dans la case
    {
        ecriture.drawTexte(window);
    }
}

bool Case::boutonClique(const Vector2f& mousePosition)
{
    return carre.getGlobalBounds().contains(mousePosition);
}

void Case::changerCouleur(Color couleurBouton)
{
    //bouton.setFillColor(couleurBouton);
    couleur = couleurBouton;
}

void Case::changerCouleurTexte(Color couleurTexte)
{
    ecriture.changerCouleur(couleurTexte);
}

void Case::mettreAJourNoteCase(vector<int> noteVecteur)
{
    noteCase = noteVecteur;
}

bool Case::estPresent(vector<int>& vecteur, int k)
{
    // Permet de verifier si un élément k est présent dans un vecteur
    auto it = find(vecteur.begin(), vecteur.end(), k);
    return it != vecteur.end();
}

int Case::avoirValeur()
{
    return valeur;
}