#include "BoutonNavigation.h"

BoutonNavigation::BoutonNavigation()
{
    // Défaut
}

void BoutonNavigation::configuration(const::Vector2f& position,EtatBouton etatInitial) 
{
    // Permet de configurer le bouton
    bouton.setSize(Vector2f(111.f, 39.44f));
    bouton.setFillColor(Color::White);
    bouton.setOutlineColor(Color::Black);
    bouton.setOutlineThickness(2.48f);
    bouton.setPosition(position);
    etatBouton = etatInitial;

    // On ajoute ensuite le texte du bouton
    ecriture.ConfigurationTexteBouton(16, avoirStringEnum(), position, bouton);
}

void BoutonNavigation::draw(RenderWindow& window)
{
    // Permet de dessiner le bouton sur la référence window souhaitée
    window.draw(bouton);
    ecriture.drawTexte(window);
}

void BoutonNavigation::actionClique(RenderWindow& window, IaApparence& iaApparence)
{
    // Action faite si le bouton est cliqué
    switch (etatBouton) {
    case EtatBouton::Suivant:
        //gestionDialogueBouton.ligneSuivante();
        //iaApparence.avoirGestionDialogue().ligneSuivante();
        iaApparence.ligneSuivante();

        break;
    case EtatBouton::Precedent:
        iaApparence.lignePrecedente();
        //gestionDialogueBouton.lignePrecedente();
        //iaApparence.avoirGestionDialogue().lignePrecedente();
        break;
    }
}

bool BoutonNavigation::boutonClique(const Vector2f& mousePosition)
{
    return bouton.getGlobalBounds().contains(mousePosition);
}

string BoutonNavigation::avoirStringEnum()
{
    switch (etatBouton) {
    case EtatBouton::Suivant:
        return "-->";
        break;
    case EtatBouton::Precedent:
        return "<--";
        break;
    }
}

//GestionDialogue BoutonNavigation::avoirGestionDialogueTest()
//{
//    return gestionDialogueBouton;
//}
