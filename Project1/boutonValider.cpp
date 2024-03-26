#include "BoutonValider.h"

BoutonValider::BoutonValider()
{
    // Défaut
}

void BoutonValider::configuration(const Vector2f position)
{
    // Permet de configurer le bouton
    bouton.setSize(dimension);
    bouton.setFillColor(couleur);
    bouton.setOutlineColor(Color::Black);
    bouton.setOutlineThickness(2.48f);
    bouton.setPosition(position);

    // Configuration du texte
    ecriture.ConfigurationTexteBouton(16, "Valider", position, bouton);
}

void BoutonValider::draw(RenderWindow& window)
{
    // Permet de dessiner le bouton sur la référence window souhaitée
    window.draw(bouton);
    ecriture.drawTexte(window);
}

bool BoutonValider::boutonClique(const Vector2f& mousePosition)
{
    return bouton.getGlobalBounds().contains(mousePosition);
}

void BoutonValider::changerClique(bool boolClique)
{
    clique = boolClique;
}

bool BoutonValider::avoirClique()
{
    return clique;
}