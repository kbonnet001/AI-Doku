#include "Texte.h"

Texte::Texte()
{
    // Défaut
}

void Texte::ConfigurationTexteBouton(int police, string ecriture, Vector2f position, RectangleShape bouton)
{
    // Permet de défnir la configuration du texte
    // On charge d'abord la font
    ChargerFont();
    // On configure ensuite le texte
    texte.setFont(font);
    texte.setCharacterSize(police);
    texte.setFillColor(couleur);
    texte.setString(ecriture);
    // On centre finalement le texte sur le bouton
    CentrerTexte(position, bouton);
}

void Texte::ChargerFont()
{
    // Permet de charge la font
    if (!font.loadFromFile("res/Poppins-Regular.ttf"))
    {
        // Gestion de l'erreur si le chargement de la police échoue
        std::cerr << "Erreur lors du chargement de la police." << std::endl;
    }
}

void Texte::CentrerTexte(Vector2f position, RectangleShape bouton)
{
    // Permet de center un texte au centre d'un bouton donné ainsi que de la position du bouton
    FloatRect textBounds = texte.getLocalBounds();
    texte.setOrigin(textBounds.left + textBounds.width / 2.f, textBounds.top + textBounds.height / 2.f);
    texte.setPosition(position.x + bouton.getSize().x / 2.f, position.y + bouton.getSize().y / 2.f);
}

void Texte::drawTexte(RenderWindow& window)
{
    // Permet de dessiner le texte sur le window
    window.draw(texte);
}

void Texte::changerCouleur(Color nouvelleCouleur)
{
    couleur = nouvelleCouleur;
}

string Texte::avoirTexteTest()
{
    return texte.getString().toAnsiString();
}

void Texte::ConfigurationTexte(int police, string ecriture, Vector2f position)
{
    // Permet de défnir la configuration du texte
    // On charge d'abord la font
    ChargerFont();
    // On configure ensuite le texte
    texte.setFont(font);
    texte.setCharacterSize(police);
    texte.setFillColor(couleur);
    texte.setString(ecriture);
    texte.setPosition(position.x, position.y);
}

void Texte::nouveauTexte(string nouveauTexte)
{
    texte.setString(nouveauTexte);
}