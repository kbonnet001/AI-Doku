#include "main.h"

// Variables
RenderWindow window;
Event event;
RectangleShape square;
Vector2f mousePosition;
Texture num1;
Sprite sprite;

int main()
{
    window.create(VideoMode(360, 800), "SFML works!");
    //Pour mettre en plein écran, attention pas encore possible de quitter la fenetre !
    //RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Fenêtre en plein écran", sf::Style::Fullscreen);

    BoutonClose boutonClose(sf::Vector2f(35.f, 743.f));

    square.setSize(Vector2f(50.f, 50.f));
    square.setFillColor(Color::White);
    square.setOutlineThickness(2.f);
    square.setOutlineColor(Color::Black);
    square.setPosition(100.f, 100.f);

    if (!num1.loadFromFile("Images/num1.png")) {
        return EXIT_FAILURE;
    }

    sprite.setTexture(num1);
    sprite.setPosition(100.f, 100.f);
    sprite.setScale(0.05f, 0.05f);

    mousePosition == window.mapPixelToCoords(Mouse::getPosition(window));

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::White);

        //window.draw(square);
        //window.draw(sprite);
        boutonClose.draw(window);

        // Actions à faire si clic gauche de la souris
        if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
        {
            // On met à jour la position de la souris
            mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));
            boutonClose.actionBouton(window, mousePosition);
        }
                
        window.display();
    }

    return 0;
}


//void ButtonText(RectangleShape& bouton)
//{
//    // Bouton avec un text dessus, quand on clique dessus il permet d'écrire un chiffre
//    if (event.type == Event::MouseButtonPressed)
//        if (event.mouseButton.button == Mouse::Left)
//        {
//            // Récupérer les coordonnées du clic de la souris
//            Vector2f mousePosition = window.mapPixelToCoords(Mouse::getPosition(window));
//
//            // Vérifier si la zone du bouton contient les coordonées du clic
//            if (bouton.getGlobalBounds().contains(mousePosition))
//            {
//                // Si le clic a été effectué sur le bouton, on regarde le chiffre du bouton
//                // Fonction qui n'existe pas encore pour savoir quel chiffre on a 
//                // Ecrire dans la case qu'il faut le bon chiffre
//            }
//        }
//}

//int DonneValeurBouton(Texture sprite)
//{
//    sprite==sprite
//}

//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//enum class ButtonValue
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
//
//class NumberButton
//{
//public:
//    NumberButton(ButtonValue value, const sf::Vector2f& position) : value(value)
//    {
//        font.loadFromFile("res/Poppins-Regular.ttf"); 
//
//
//        button.setSize(sf::Vector2f(50.f, 50.f));
//        button.setPosition(position);
//
//        text.setFont(font);
//        text.setCharacterSize(20);
//        text.setFillColor(sf::Color::Black);
//        text.setString(std::to_string(static_cast<int>(value)));
//        sf::FloatRect textBounds = text.getLocalBounds();
//        text.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
//        text.setPosition(position.x + button.getSize().x / 2.f, position.y + button.getSize().y / 2.f);
//    }
//
//    void draw(sf::RenderWindow& window)
//    {
//        window.draw(button);
//        window.draw(text);
//    }
//
//    bool isClicked(const sf::Vector2f& mousePosition)
//    {
//        return button.getGlobalBounds().contains(mousePosition);
//    }
//
//    ButtonValue getValue() const
//    {
//        return value;
//    }
//
//private:
//    ButtonValue value;
//    sf::RectangleShape button;
//    sf::Text text;
//    sf::Font font;
//};
//
//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
//
//    NumberButton button1(ButtonValue::Un, sf::Vector2f(100.f, 100.f));
//    NumberButton button2(ButtonValue::Deux, sf::Vector2f(200.f, 100.f));
//    NumberButton button3(ButtonValue::Trois, sf::Vector2f(300.f, 100.f));
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//            {
//                sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
//
//                if (button1.isClicked(mousePosition))
//                {
//                    std::cout << "Button 1 clicked. Value: " << static_cast<int>(button1.getValue()) << std::endl;
//                }
//                else if (button2.isClicked(mousePosition))
//                {
//                    std::cout << "Button 2 clicked. Value: " << static_cast<int>(button2.getValue()) << std::endl;
//                }
//                else if (button3.isClicked(mousePosition))
//                {
//                    std::cout << "Button 3 clicked. Value: " << static_cast<int>(button3.getValue()) << std::endl;
//                }
//            }
//        }
//
//        window.clear();
//
//        button1.draw(window);
//        button2.draw(window);
//        button3.draw(window);
//
//        window.display();
//    }
//
//    return 0;
//}