#include "IaApparence.h"

IaApparence::IaApparence()
{
    //
}

void IaApparence::afficherIA(RenderWindow& window)
{
    dessinerIa(window);
}


bool IaApparence::loadVideo(string cheminVideo)
{
    if (!texture.loadFromFile(cheminVideo)) {
        std::cerr << "Erreur lors du chargement de l'animation GIF." << std::endl;
        return false; // Indique que le chargement a échoué
    }
    return true; // Indique que le chargement a réussi
}

void IaApparence::dessinerIa(RenderWindow& window)
{
    loadVideo("Images/hello.gif");
    Sprite sprite(texture);
    sprite.setScale(dimensionSprite); 
    sprite.setPosition(positionSprite);

    window.draw(sprite);
}