#ifndef BOUTONEFFACER_H
#define BOUTONEFFACER_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

// Includes
#include "bouton.h" // h�ritage
#include "Texte.h"

class BoutonEffacer : public Bouton
{
public:
    BoutonEffacer();
    void draw(RenderWindow& window) override;
    bool boutonClique(const Vector2f& mousePosition) override;
    //void actionClique(RenderWindow& window);
    //void actionBouton(RenderWindow& window, Vector2f& mousePosition);
    //void changerCouleur(Color couleurBouton, Color couleurTexte);
    void configuration(const Vector2f position);
    void changerClique(bool boolClique);


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

#endif // BOUTONEFFACER

