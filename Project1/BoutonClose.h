#ifndef BOUTONCLOSE_H
#define BOUTONCLOSE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

// Include Hearder
#include "bouton.h" // héritage
#include "Texte.h"

class BoutonClose : public Bouton
{
public:
    BoutonClose();
    void configuration(const::Vector2f& position);
    void draw(RenderWindow& window) override;
    void actionClique(RenderWindow& window);
    bool boutonClique(const sf::Vector2f& position) override;

private:
    RectangleShape bouton;
    Texte ecriture;
};

#endif // BOUTONCLOSE
