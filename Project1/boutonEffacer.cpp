#include "BoutonEffacer.h"

BoutonEffacer::BoutonEffacer()
{
    // Défaut
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
    // Permet de dessiner le bouton sur la référence window souhaitée
    window.draw(bouton);
    ecriture.drawTexte(window);
}

bool BoutonEffacer::boutonClique(const Vector2f& mousePosition)
{
    return bouton.getGlobalBounds().contains(mousePosition);
}

void BoutonEffacer::changerClique(bool boolClique)
{
    clique = boolClique;
}