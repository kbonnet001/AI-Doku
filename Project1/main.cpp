#include "main.h"

int main()
{
    window.create(VideoMode(360, 800), "AIDOKU");
    //Pour mettre en plein écran, attention pas encore possible de quitter la fenetre !
    //RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Fenêtre en plein écran", sf::Style::Fullscreen);

    if (!num1.loadFromFile("Images/num1.png")) {
        return EXIT_FAILURE;
    }

    mousePosition == window.mapPixelToCoords(Mouse::getPosition(window));

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);

        grilleJeu.drawStatique(window);
        grilleJeu.drawBoutons(window);

        // Actions à faire si clic gauche de la souris
        if (event.type == Event::MouseButtonPressed)
            if (event.mouseButton.button == Mouse::Left)
            {
                // On met à jour la position de la souris
                mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));

                // Puis on fait les actions de la grille
                grilleJeu.actionGrille(window,mousePosition);

            }
        mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));
                
        window.display();
    }

    return 0;
}
