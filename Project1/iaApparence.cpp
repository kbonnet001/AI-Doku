#include "IaApparence.h"

IaApparence::IaApparence()
{
    // Gestion du dialogue
    // Plus pr�cis�ment, la ligne o� l'on se trouve, ce qu'il faut �crire
    // On ne se pr�occupe pas ici de l'affichage, de la mise en forme !
    // Pour �a, aller dans iaApparence

    if (etatDialogue == EtatDialogue::Initial)
    {
        ajouterTexteInitial();
    }
}

void IaApparence::afficherIA(RenderWindow& window)
{
    dessinerIa(window);
    configurationDialogue();
    window.draw(boiteDialogue);
    ligneDialogue.drawTexte(window);
}


bool IaApparence::loadVideo(string cheminVideo)
{
    if (!texture.loadFromFile(cheminVideo)) {
        std::cerr << "Erreur lors du chargement de l'animation GIF." << std::endl;
        return false; // Indique que le chargement a �chou�
    }
    return true; // Indique que le chargement a r�ussi
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
    ligneDialogue.ConfigurationTexte(15, dialogue[paragrapheActuel][ligneActuelle], Vector2f(155.f, 66.f));
}

void IaApparence::ligneSuivante()
{
    // Passer � la ligne suivante
    if (ligneActuelle < dialogue[paragrapheActuel].size() - 1)
    {
        ++ligneActuelle;
        cout << "ligne Actuelle : " << ligneActuelle << " dialogue[paragrapheActuel].size()" << dialogue[paragrapheActuel].size() - 1 << endl;

    }
    else if (ligneActuelle == dialogue[paragrapheActuel].size()-1 && etatDialogue!=EtatDialogue::Initial)
    {
        cout << "�galit� youpi" << endl;
        // on est � la derni�re ligne du paragraphe, il faut changer de paragraphe
        paragrapheSuivant();
    }
}

void IaApparence::lignePrecedente()
{
    // Revenir � la ligne pr�c�dente
    if (ligneActuelle > 0)
    {
        --ligneActuelle;
    }
}

void IaApparence::paragrapheSuivant()
{
    if (etatDialogue != EtatDialogue::Initial)
    {
        // Quand on clique, on veut acc�der � la prochaine utilisation de strat�gie
        cout << "dialogue.size() : " << dialogue.size()<<endl;
        ajouterTexte();
        cout << "omg du texte a �t� ajout�" << endl;
        cout << "dialogue.size() : " << dialogue.size() << endl;
    }
    ligneActuelle = 0;
    paragrapheActuel += 1;
}

string IaApparence::formaterLigneTexte(string ligneTexte, int nbCaracMax, int nbLigneMax)
{
    // Le nombre de caract�re d'une ligne est limit� � 20
    // Le nombre de ligne pour une boite de dialogue est de 4 (3 retours � la ligne max)
    // Soit un total de 20*4 = 60 caract�res pour une boite de dialogue
    string texteFormate;
    int tailleLigneActuelle = 0;
    int numeroLigneActuelle = 0;

    for (char c : ligneTexte)
    {
        // V�rifie si le caract�re est une espace ou un retour � la ligne
        if (c == ' ' || c == '\n')
        {
            // V�rifie si l'ajout du prochain mot d�passera la limite de la ligne
            if (tailleLigneActuelle + 1 > nbCaracMax)
            {
                // V�rifie si l'ajout du prochain mot d�passera la limite du nombre de lignes
                if (numeroLigneActuelle + 1 < nbLigneMax)
                {
                    texteFormate += '\n'; // Ajoute un retour � la ligne
                    tailleLigneActuelle = 0; // R�initialise la longueur de la ligne
                    numeroLigneActuelle++; // Incr�mente le nombre de lignes
                }
                else {
                    break; // Sort de la boucle si le nombre maximum de lignes est atteint
                }
            }
        }
        // Ajoute le caract�re � la cha�ne format�e
        texteFormate += c;
        // Incr�mente la longueur de la ligne
        tailleLigneActuelle++;
    }

    return texteFormate;
}

void IaApparence::ajouterTexteInitial()
{
    // Texte de base � mettre dans le dialogue de l'IA
    // A mettre m�me si l'utilisateur ne souhaite pas lire 
    // pour pouvoir revenir en arri�re au cas o�
    nouvelleLigne.clear();

    nouvelleLigne.push_back(formaterLigneTexte("Bonjour, je m'appelle AiDoku !"));
    nouvelleLigne.push_back(formaterLigneTexte("Je suis une jeune IA capable de r�soudre des sudokus."));
    nouvelleLigne.push_back(formaterLigneTexte("Tu es bloqu�s dans une grille ? Montre la moi et je t'aiderai � la r�soudre."));
    nouvelleLigne.push_back(formaterLigneTexte("Pour commencer, entre ton sudoku incomplet dans la grille ci-dessous."));
    nouvelleLigne.push_back(formaterLigneTexte("Lorsque tu as termin�, appuies sur 'Valider'."));

    ajouterParagraphe(nouvelleLigne);
}

void IaApparence::ajouterTexteNote(bool sansNote /*vector<int> positionCase*/)
{
    nouvelleLigne.clear();
    // Pour ajouter une ligne pour les notes 
    if (sansNote == true) // case vide
    {
        nouvelleLigne.push_back(formaterLigneTexte("Commen�ons par �crire des notes."));
        // explications compl�mentaires
        nouvelleLigne.push_back(formaterLigneTexte("Lorsque l'on commence une grille de sudoku, on commence par cette �tape."));
        nouvelleLigne.push_back(formaterLigneTexte("Pour chaque case vide, on regarde quelles sont les possibilit�s."));
        nouvelleLigne.push_back(formaterLigneTexte("Comme il y a beaucoup de chose � retenir, on les �crits en petit."));
        nouvelleLigne.push_back(formaterLigneTexte("On a ainsi une vision globale du jeu !"));

        ajouterParagraphe(nouvelleLigne);
    }

    // Pour une mise � jour des notes
    else
    {
        nouvelleLigne.push_back(formaterLigneTexte("On peut alors mettre � jour les notes."));
        // explications compl�mentaires
        //if (positionCase.size() < 13)
        //{
        //    ajouterLigne(formaterLigneTexte("Plus pr�cis�ment, les notes ont chang�s dans les cases suivantes :"));
        //}
        //// Si il y a eu trop de changement, pb pour l'affichage, on ne donne que les premiers
        //else
        //{
        //    ajouterLigne(formaterLigneTexte("Les notes ont chang�s dans de nombreuses cases !"));
        //    ajouterLigne(formaterLigneTexte("Voici quelques cases qui ont subi des changements : "));
        //}
        //string caseNoteModifie;
        //for (int k = 0; k < 6; k + 2)
        //{
        //    caseNoteModifie += "case (" + to_string(positionCase[k]) + "," + to_string(positionCase[k + 1]) + ") ; ";
        //}
        //ajouterLigne(formaterLigneTexte(caseNoteModifie));
    }
}

void IaApparence::ajouterTexteSingletonEvident()
{
    // Texte de base � mettre dans le dialogue de l'IA
    // A mettre m�me si l'utilisateur ne souhaite pas lire 
    // pour pouvoir revenir en arri�re au cas o�
    nouvelleLigne.clear();
    nouvelleLigne.push_back(formaterLigneTexte("Gr�ce � ces notes, ont peut ensuite �crire les chiffres des singletons �vidents"));
    nouvelleLigne.push_back(formaterLigneTexte("On met alors � jour les notes."));

    ajouterParagraphe(nouvelleLigne);
}

string IaApparence::avoirLigneDialogue(int& paragrapheActuel, int& ligneActuelle)
{
    return dialogue[paragrapheActuel][ligneActuelle];
}

void IaApparence::affichageTest(int& paragrapheActuel, int& ligneActuelle)
{
    cout << "paragraphe : " << paragrapheActuel << endl;
    cout << "ligne actuelle : " << ligneActuelle << endl;
    cout << "dialogue size : " << dialogue.size() << endl;
}

void IaApparence::ajouterParagraphe(const vector<string> nouveauParagraphe)
{
    dialogue.push_back(nouveauParagraphe);
}

void IaApparence::changerEtat(EtatDialogue nouvelleEtatDialogue)
{
    etatDialogue = nouvelleEtatDialogue;
    cout << "omg l'etat c'est : ";

    switch (nouvelleEtatDialogue) {
    case EtatDialogue::Initial:
        cout << "Initial" << endl;
        break;
    case EtatDialogue::Note:
        cout << "Note" << endl;;
        break;
    case EtatDialogue::SingletonEvident:
        cout << "SingletonEvident" << endl;
        break;
    default:
        cout << "Valeur inconnue" << endl;
    }
}

void IaApparence::ajouterTexte()
{
    // Ajouter du texte de mani�re g�n�rale
    if (etatDialogue == EtatDialogue::Note)
    {
        // --> on est a l'�tat des notes
        ajouterTexteNote(true);
    }
    else if (etatDialogue == EtatDialogue::SingletonEvident)
    {
        cout << "ajouter texte singleton evident" << endl;
        ajouterTexteSingletonEvident();
    }
}

bool IaApparence :: savoirSiFinParagraphe()
{
    cout << "ligne Actuelle : " << ligneActuelle +1 << " dialogue[paragrapheActuel].size()" << dialogue[paragrapheActuel].size()-1 << endl;
    return (ligneActuelle == dialogue[paragrapheActuel].size() - 1);
}