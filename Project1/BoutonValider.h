#ifndef BOUTONVALIDER_H
#define BOUTONVALIDER_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

// Includes
#include "bouton.h" // héritage

class BoutonValider : public Bouton
{
public:
    BoutonValider();
    void draw(RenderWindow& window) override;
    bool boutonClique(const Vector2f& mousePosition) override;
    void configuration(const Vector2f position);
    void changerClique(bool boolClique);
    bool avoirClique();


private:
    RectangleShape bouton;
    const Vector2f position;
    Color couleur = Color::White; //couleur du bouton, peut changer
    Color couleurGris = Color(217, 217, 217);
    const Vector2f& dimension = Vector2f(143.f, 39.44f);
    //BoutonValeur chiffre;
    bool clique = false;
    Texte ecriture;
};

#endif // BOUTONVALIDER
