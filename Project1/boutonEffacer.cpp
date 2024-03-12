#include "BoutonEffacer.h"

BoutonEffacer::BoutonEffacer()
{
    // D�faut
}

void BoutonEffacer::configuration(const Vector2f position)
{
    // Permet de configurer le bouton
    bouton.setSize(dimension);
    bouton.setFillColor(couleur);
    bouton.setOutlineColor(Color::Black);
    bouton.setOutlineThickness(2.48f);
    bouton.setPosition(position);

    // Configuration du texte
    ecriture.ConfigurationTexteBouton(16,"Effacer", position, bouton);
}

void BoutonEffacer::draw(RenderWindow& window)
{
    // Permet de dessiner le bouton sur la r�f�rence window souhait�e
    window.draw(bouton);
    ecriture.drawTexte(window);
}


//void BoutonEffacer::actionClique(RenderWindow& window)
//{
//    if (clique == false)
//    {
//        changerCouleur(Color::White, Color::Black);
//        std::cout << "Button effac� not cliqu�" << std::endl;
//    }
//    else // clique ==true
//    {
//        changerCouleur(couleurGris, Color::Black);
//        std::cout << "Button effac� cliqu�" << std::endl;
//    }
//}

//void BoutonEffacer::actionBouton(RenderWindow& window, Vector2f& mousePosition)
//{
//    // Si un clic gauche a eu lieu (v�rification avant)
//    if (boutonClique(mousePosition))
//    {
//        actionClique(window);
//    }
//}

//void BoutonEffacer::changerCouleur(Color couleurBouton, Color couleurTexte)
//{
//    //bouton.setFillColor(couleurBouton);
//    couleur = couleurBouton;
//    ecriture.changerCouleur(couleurTexte);
//}

bool BoutonEffacer::boutonClique(const Vector2f& mousePosition)
{
    return bouton.getGlobalBounds().contains(mousePosition);
}

void BoutonEffacer::changerClique(bool boolClique)
{
    clique = boolClique;
}