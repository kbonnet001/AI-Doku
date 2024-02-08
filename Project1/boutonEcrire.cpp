#include "BoutonEcrire.h"

BoutonEcrire::BoutonEcrire() 
{
    // Défaut
}

void BoutonEcrire::configuration(int i, const Vector2f position)
{
    chiffre = i;
    // Permet de configurer le bouton
    bouton.setSize(dimension);
    bouton.setFillColor(couleur);
    bouton.setOutlineColor(Color::Black);
    bouton.setOutlineThickness(2.48f);
    bouton.setPosition(position);

    // Configuration du texte
    ecriture.ConfigurationTexte(16, to_string(static_cast<int>(chiffre)), position, bouton);

}

void BoutonEcrire::draw(RenderWindow& window)
{
    // Permet de dessiner le bouton sur la référence window souhaitée
    window.draw(bouton);
    ecriture.drawTexte(window);
}


void BoutonEcrire::actionClique(RenderWindow& window) 
{
    if (clique == false)
    {
        changerCouleur(Color::White, Color::Black);
        std::cout << "Button i clicked. Value: " << chiffre << std::endl;
    }
    else // clique ==true
    {
        changerCouleur(couleurGris, Color::Black);
        std::cout << "Button i clicked. Value: " << chiffre << std::endl;
    }
}

 int BoutonEcrire::actionBouton(RenderWindow& window, Vector2f& mousePosition)
 {
     // Si un clic gauche a eu lieu (vérification avant)
     if (boutonClique(mousePosition))
     {
         actionClique(window);
         return chiffre;
     }
 }

 void BoutonEcrire::changerCouleur(Color couleurBouton, Color couleurTexte)
 {
     //bouton.setFillColor(couleurBouton);
     couleur = couleurBouton;
     ecriture.changerCouleur(couleurTexte);
 }

 bool BoutonEcrire::boutonClique(const Vector2f& mousePosition)
 {
     return bouton.getGlobalBounds().contains(mousePosition);
 }

 int BoutonEcrire:: avoirChiffre()
 {
     return chiffre;
 }

 void BoutonEcrire::changerClique(bool boolClique)
 {
     clique = boolClique;
 }