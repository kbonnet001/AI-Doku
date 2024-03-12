#include "IaApparence.h"

IaApparence::IaApparence()
{
    //
}

void IaApparence::afficherIA(RenderWindow& window)
{
    dessinerIa(window);
    configurationDialogue();
    window.draw(boiteDialogue);
    dialogue.drawTexte(window);
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
    loadVideo("Images/hello0.png");
    Sprite sprite(texture);
    sprite.setScale(dimensionSprite); 
    sprite.setPosition(positionSprite);

    window.draw(sprite);
}

void IaApparence::configurationDialogue()
{
    // Pour la boite de dialogue
    boiteDialogue.setFillColor(couleurTurquoiseClair);
    boiteDialogue.setOutlineColor(Color::Black);
    boiteDialogue.setOutlineThickness(2.0f);
    boiteDialogue.setPosition(Vector2f(144.f, 54.f));
    boiteDialogue.setSize(Vector2f(200.43, 102));

    // Pour le texte
    dialogue.ConfigurationTexte(15, gestionDialogue.avoirLigneDialogue(paragrapheActuel, ligneActuelle), Vector2f(155.f, 66.f));
}

//void IaApparence::miseAJourDialogue()
//{
//    dialogue.nouveauTexte(gestionDialogue.avoirLigneDialogue(paragrapheActuel, ligneActuelle));
//    cout << "configuration iaapparence mise à jour" << endl;
//    cout << gestionDialogue.avoirLigneDialogue(paragrapheActuel, ligneActuelle) << endl;
//}

GestionDialogue IaApparence::avoirGestionDialogue()
{
    return gestionDialogue;
}

void IaApparence::ligneSuivante()
{
    gestionDialogue.ligneSuivante(ligneActuelle,paragrapheActuel);
}

void IaApparence::lignePrecedente()
{
    gestionDialogue.lignePrecedente(ligneActuelle);
}