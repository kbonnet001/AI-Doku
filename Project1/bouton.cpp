#include "Bouton.h"

void Bouton:: draw(RenderWindow& window)
{
    window.draw(bouton);
    ecriture.drawTexte(window);
}