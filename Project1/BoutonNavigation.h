#ifndef BOUTONNAVIGATION_H
#define BOUTONNAVIGATION_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

// Include Hearder
#include "bouton.h" // héritage
#include "Texte.h"
#include "GestionDialogue.h"
#include "IaApparence.h"

enum class EtatBouton { Suivant, Precedent};

class BoutonNavigation : public Bouton
{
public:
    BoutonNavigation();
    void configuration(const::Vector2f& position, EtatBouton etatInitial);
    void draw(RenderWindow& window) override;
    void actionClique(RenderWindow& window, IaApparence& iaApparence);
    bool boutonClique(const sf::Vector2f& position) override;
    string avoirStringEnum();
    //GestionDialogue avoirGestionDialogueTest();

private:
    RectangleShape bouton;
    Texte ecriture;
    EtatBouton etatBouton;
    //GestionDialogue gestionDialogueBouton;
};

#endif // BOUTONCLOSE
