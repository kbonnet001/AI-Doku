#include "boutonclose.h"

//BoutonClose::BoutonClose(const::Vector2f& position)
//{
//    // Quand on crée un bouton pour fermer une page, on doit donner sa position
//    bouton.setSize(Vector2f(50.f, 50.f));
//    bouton.setPosition(position);
//    bouton.setFillColor(Color::Red);
//}

BoutonClose::BoutonClose(const::Vector2f& position)
{

    if (!font.loadFromFile("res/Poppins-Regular.ttf")) 
    {
        // Gestion de l'erreur si le chargement de la police échoue
        std::cerr << "Erreur lors du chargement de la police." << std::endl;
        // Vous pouvez choisir de quitter ou de continuer avec une police par défaut
    }
    
    bouton.setSize(Vector2f(280.f, 34.f));
    bouton.setPosition(position);
    bouton.setFillColor(Color(217, 217, 217));

    texte.setFont(font);
    texte.setCharacterSize(16);
    texte.setFillColor(sf::Color::Black);
    texte.setString("Quitter");
    FloatRect textBounds = texte.getLocalBounds();
    texte.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
    texte.setPosition(position.x + bouton.getSize().x / 2.f, position.y + bouton.getSize().y / 2.f);
}

void BoutonClose::draw(RenderWindow& window)
{
    // Permet de dessiner le bouton sur la référence window souhaitée
    window.draw(bouton);
    window.draw(texte);
}

bool BoutonClose::isClicked(const::Vector2f& mousePosition)
{
    // Pour savoir si le clic de la souris est sur le bouton, retourne un bool
    return bouton.getGlobalBounds().contains(mousePosition);
}

void BoutonClose::onClick(RenderWindow& window)
{
    // Pour dire que ça marche
    std::cout << "Close button clicked!" << std::endl;
    window.close();
}

void BoutonClose::actionBouton(RenderWindow& window, Vector2f& mousePosition)
{
    // Si un clic gauche a eu lieu (vérification avant)
    if (isClicked(mousePosition))
    {
        onClick(window);
    }
        
}

