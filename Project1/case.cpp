#include "Case.h"

Case::Case()
{
    // Défaut
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

void Case::draw(RenderWindow& window)
{
    window.draw(carre);
    ecriture.drawTexte(window);
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