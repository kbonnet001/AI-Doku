#include "boutonclose.h"

BoutonClose::BoutonClose()
{
    // D�faut
}

void BoutonClose::configuration(const::Vector2f& position)
{
    // Permet de configurer le bouton
    bouton.setSize(Vector2f(280.f, 34.f));
    bouton.setFillColor(Color(217, 217, 217));
    bouton.setPosition(position);

    // On ajoute ensuite le texte du bouton
    ecriture.ConfigurationTexte(16, "Quitter", position, bouton);
}

void BoutonClose::draw(RenderWindow& window)
{
    // Permet de dessiner le bouton sur la r�f�rence window souhait�e
    window.draw(bouton);
    ecriture.drawTexte(window);
}

void BoutonClose::actionClique(RenderWindow& window)
{
    // Action faite si le bouton est cliqu�
    window.close();
}

bool BoutonClose::boutonClique(const Vector2f& mousePosition)
{
    return bouton.getGlobalBounds().contains(mousePosition);
}