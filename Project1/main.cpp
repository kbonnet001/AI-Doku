#include "main.h"

int main()
{
    window.create(VideoMode(WIN_WIDTH, WIN_HEIGHT), "AIDOKU");
    //Pour mettre en plein �cran
    //RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Fen�tre en plein �cran", sf::Style::Fullscreen);

    mousePosition == window.mapPixelToCoords(Mouse::getPosition(window));

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);

        // On dessine sur le window l'interface du jeu
        grilleJeu.drawStatique(window);
        grilleJeu.drawBoutons(window);

        // Actions � faire si clic gauche de la souris
        if (event.type == Event::MouseButtonPressed)
            if (event.mouseButton.button == Mouse::Left)
            {
                // On met � jour la position de la souris
                mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));

                // Puis on fait les actions de la grille
                grilleJeu.actionGrille(window,mousePosition);

            }
        mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));
                
        window.display();
    }

    return 0;
}
