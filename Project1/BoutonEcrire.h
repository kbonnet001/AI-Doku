#ifndef BOUTONECRIRE_H
#define BOUTONECRIRE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

// Includes
#include "bouton.h" // héritage
#include "Texte.h"

class BoutonEcrire : public Bouton
{
public:
    BoutonEcrire();
    void draw(RenderWindow& window) override;
    bool boutonClique(const Vector2f& mousePosition) override;
    void actionClique(RenderWindow& window);
    int actionBouton(RenderWindow& window, Vector2f& mousePosition);
    void changerCouleur(Color couleurBouton, Color couleurTexte);
    void configuration(int i, const Vector2f position);
    int avoirChiffre();
    void changerClique(bool boolClique);


private:
    RectangleShape bouton;
    const Vector2f position;
    Color couleur=Color::White; //couleur du bouton, peut changer
    Color couleurGris = Color(217, 217, 217);
    const Vector2f& dimension = Vector2f(33.83f, 33.83f);
    //BoutonValeur chiffre;
    int chiffre=0;
    bool clique = false;
    Texte ecriture;
};

#endif // BOUTONECRIRE
#pragma once
