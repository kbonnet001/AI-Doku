#ifndef BOUTONECRIRE_H
#define BOUTONECRIRE_H
#include <string>
#include <SFML/Graphics.hpp>
#include "bouton.h" // héritage
#include <iostream>

//enum class BoutonValeur
//{
//    Un = 1,
//    Deux,
//    Trois,
//    Quatre,
//    Cinq,
//    Six,
//    Sept,
//    Huit,
//    Neuf
//};

class BoutonEcrire : public Bouton
{
public:
    BoutonEcrire(int chiffre, const Vector2f position);
    //const int AvoirValeur();
    void draw(RenderWindow& window) override;
    bool isClicked(const Vector2f& mousePosition) override;
    void  onClick(RenderWindow& window);
    void actionBouton(RenderWindow& window, Vector2f& mousePosition) override;

private:
    RectangleShape bouton;
    Text texte;
    Font font;
    const Vector2f position;
    Color couleurGris = Color(217, 217, 217);
    const Vector2f& dimension = Vector2f(33.83f, 33.83f);
    //BoutonValeur chiffre;
    int chiffre;
    bool clique = false;


};

#endif // BOUTONECRIRE
#pragma once
