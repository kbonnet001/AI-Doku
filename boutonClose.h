#ifndef BOUTONCLOSE_H
#define BOUTONCLOSE_H
#include <string>
#include <SFML/Graphics.hpp>
#include "bouton.h" // héritage
#include <iostream>

class BoutonClose : public Bouton
{
public:
    BoutonClose(const Vector2f& position);
    void draw(RenderWindow& window) override;
    bool isClicked(const Vector2f& mousePosition) override;
    void onClick(RenderWindow& window) ;
    void actionBouton(RenderWindow& window,Vector2f& mousePosition) override;

private:
    sf::RectangleShape bouton;
    sf::Text texte;
    sf::Font font;
};

#endif // BOUTONCLOSE
