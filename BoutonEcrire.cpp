#include "BoutonEcrire.h"

BoutonEcrire::BoutonEcrire(int i, const Vector2f position) 
{
    chiffre = i;
    if (!font.loadFromFile("res/Poppins-Regular.ttf"))
    {
        // Gestion de l'erreur si le chargement de la police échoue
        std::cerr << "Erreur lors du chargement de la police." << std::endl;
    }

    bouton.setSize(dimension);
    bouton.setPosition(position);
    bouton.setFillColor(couleurGris);
    bouton.setOutlineColor(Color::Black);
    bouton.setOutlineThickness(2.48f);

    texte.setFont(font);
    texte.setCharacterSize(16);
    texte.setFillColor(sf::Color::Black);
    texte.setString(to_string(static_cast<int>(chiffre)));
    // Pour centrer
    FloatRect textBounds = texte.getLocalBounds();
    texte.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
    texte.setPosition(position.x + bouton.getSize().x / 2.f, position.y + bouton.getSize().y / 2.f);
}

//const int BoutonEcrire::AvoirValeur()
//{
//    return chiffre;
//}

void BoutonEcrire::draw(RenderWindow& window)
{
    // Permet de dessiner le bouton sur la référence window souhaitée
    window.draw(bouton);
    window.draw(texte);
}

bool BoutonEcrire::isClicked(const::Vector2f& mousePosition)
{
    // Pour savoir si le clic de la souris est sur le bouton, retourne un 
    return bouton.getGlobalBounds().contains(mousePosition);
}

void BoutonEcrire::onClick(RenderWindow& window) 
{
    //cout << chiffre;
    bouton.setFillColor(Color::Red);
    std::cout << "Button i clicked. Value: " << chiffre << std::endl;
    //clique = false;
}

 void BoutonEcrire::actionBouton(RenderWindow& window, Vector2f& mousePosition)
 {
     // Si un clic gauche a eu lieu (vérification avant)
     if (isClicked(mousePosition))
     {
         onClick(window);
     }
 }