//#include "GestionDialogue.h"
//
//GestionDialogue::GestionDialogue()
//{
//    // Gestion du dialogue
//    // Plus pr�cis�ment, la ligne o� l'on se trouve, ce qu'il faut �crire
//    // On ne se pr�occupe pas ici de l'affichage, de la mise en forme !
//    // Pour �a, aller dans iaApparence
//
//    if (texteInitialise == false)
//    {
//        ajouterTexteInitial();
//    }
//}
//
////void GestionDialogue :: ajouterParagraphe(const vector<string> nouveauParagraphe)
////{
////    dialogue.push_back(nouveauParagraphe);
////}
//
////void GestionDialogue::ligneSuivante(int& ligneActuelle, int& paragrapheActuel)
////{
////    // Passer � la ligne suivante
////    if (ligneActuelle < dialogue[paragrapheActuel].size() - 1)
////    {
////        ++ligneActuelle;
////    }
////    else if (ligneActuelle == dialogue[paragrapheActuel].size())
////    {
////        // on est � la derni�re ligne du paragraphe, il faut changer de paragraphe
////        paragrapheSuivant(ligneActuelle, paragrapheActuel);
////    }
////}
//
////void GestionDialogue::lignePrecedente(int& ligneActuelle)
////{
////    // Revenir � la ligne pr�c�dente
////    if (ligneActuelle > 0)
////    {
////        --ligneActuelle;
////    }
////}
//
////void GestionDialogue::paragrapheSuivant(int ligneActuelle, int paragrapheActuel)
////{
////    // Passer au paragraphe suivant
////    paragrapheActuel += 1;
////    ligneActuelle = 0;
////
////    // On fait la prochaine action de r�solution
////}
//
////string GestionDialogue::getCurrentLine() 
////{
////    // R�cup�rer la ligne de dialogue actuelle
////    if (ligneActuelle >= 0 && ligneActuelle < dialogue.size()) {
////        return dialogue[paragrapheActuel][ligneActuelle];
////    }
////    else {
////        return "Fin du dialogue.";
////    }
////}
//
////string GestionDialogue::formaterLigneTexte(string ligneTexte, int nbCaracMax, int nbLigneMax)
////{
////    // Le nombre de caract�re d'une ligne est limit� � 20
////    // Le nombre de ligne pour une boite de dialogue est de 4 (3 retours � la ligne max)
////    // Soit un total de 20*4 = 60 caract�res pour une boite de dialogue
////    string texteFormate;
////    int tailleLigneActuelle = 0;
////    int numeroLigneActuelle = 0;
////
////    for (char c : ligneTexte) 
////    {
////        // V�rifie si le caract�re est une espace ou un retour � la ligne
////        if (c == ' ' || c == '\n') 
////        {
////            // V�rifie si l'ajout du prochain mot d�passera la limite de la ligne
////            if (tailleLigneActuelle + 1 > nbCaracMax) 
////            {
////                // V�rifie si l'ajout du prochain mot d�passera la limite du nombre de lignes
////                if (numeroLigneActuelle + 1 < nbLigneMax) 
////                {
////                    texteFormate += '\n'; // Ajoute un retour � la ligne
////                    tailleLigneActuelle = 0; // R�initialise la longueur de la ligne
////                    numeroLigneActuelle++; // Incr�mente le nombre de lignes
////                }
////                else {
////                    break; // Sort de la boucle si le nombre maximum de lignes est atteint
////                }
////            }
////        }
////        // Ajoute le caract�re � la cha�ne format�e
////        texteFormate += c;
////        // Incr�mente la longueur de la ligne
////        tailleLigneActuelle++;
////    }
////
////    return texteFormate;
////}
////
////
////void GestionDialogue::ajouterTexteInitial()
////{
////    // Texte de base � mettre dans le dialogue de l'IA
////    // A mettre m�me si l'utilisateur ne souhaite pas lire 
////    // pour pouvoir revenir en arri�re au cas o�
////    nouvelleLigne.clear();
////
////    nouvelleLigne.push_back(formaterLigneTexte("Bonjour, je m'appelle AiDoku !"));
////    nouvelleLigne.push_back(formaterLigneTexte("Je suis une jeune IA capable de r�soudre des sudokus."));
////    nouvelleLigne.push_back(formaterLigneTexte("Tu es bloqu�s dans une grille ? Montre la moi et je t'aiderai � la r�soudre."));
////    nouvelleLigne.push_back(formaterLigneTexte("Pour commencer, entre ton sudoku incomplet dans la grille ci-dessous."));
////    nouvelleLigne.push_back(formaterLigneTexte("Lorsque tu as termin�, appuies sur 'Valider'."));
////
////    ajouterParagraphe(nouvelleLigne);
////}
////
////void GestionDialogue::ajouterTexteNote(bool sansNote /*vector<int> positionCase*/)
////{
////    nouvelleLigne.clear();
////    // Pour ajouter une ligne pour les notes 
////    if (sansNote==true) // case vide
////    {
////        nouvelleLigne.push_back(formaterLigneTexte("Commen�ons par prendre des notes."));
////        // explications compl�mentaires
////        nouvelleLigne.push_back(formaterLigneTexte("Lorsque l'on commence une grille de sudoku, on commence g�n�ralement par cette �tape."));
////        nouvelleLigne.push_back(formaterLigneTexte("Pour chaque case vide, on regarde quels sont les possibilit�s."));
////        nouvelleLigne.push_back(formaterLigneTexte("Comme cela fait beaucoup de chose � retenir, on les �crit en petit."));
////        nouvelleLigne.push_back(formaterLigneTexte("On a ainsi une vision globale du jeu !"));
////
////        ajouterParagraphe(nouvelleLigne);
////    }
////
////    // Pour une mise � jour des notes
////    else
////    {
////        nouvelleLigne.push_back(formaterLigneTexte("On peut alors mettre � jour les notes."));
////        // explications compl�mentaires
////        //if (positionCase.size() < 13)
////        //{
////        //    ajouterLigne(formaterLigneTexte("Plus pr�cis�ment, les notes ont chang�s dans les cases suivantes :"));
////        //}
////        //// Si il y a eu trop de changement, pb pour l'affichage, on ne donne que les premiers
////        //else
////        //{
////        //    ajouterLigne(formaterLigneTexte("Les notes ont chang�s dans de nombreuses cases !"));
////        //    ajouterLigne(formaterLigneTexte("Voici quelques cases qui ont subi des changements : "));
////        //}
////        //string caseNoteModifie;
////        //for (int k = 0; k < 6; k + 2)
////        //{
////        //    caseNoteModifie += "case (" + to_string(positionCase[k]) + "," + to_string(positionCase[k + 1]) + ") ; ";
////        //}
////        //ajouterLigne(formaterLigneTexte(caseNoteModifie));
////    }
////}
////
////void GestionDialogue::ajouterTexteSingletonEvident()
////{
////    // Texte de base � mettre dans le dialogue de l'IA
////    // A mettre m�me si l'utilisateur ne souhaite pas lire 
////    // pour pouvoir revenir en arri�re au cas o�
////    nouvelleLigne.clear();
////    nouvelleLigne.push_back(formaterLigneTexte("Gr�ce � ces notes, ont ensuite �crire les chiffres des singletons �vidents"));
////}
////
////string GestionDialogue::avoirLigneDialogue(int& paragrapheActuel, int& ligneActuelle)
////{
////    return dialogue[paragrapheActuel][ligneActuelle];
////}
////
////void GestionDialogue::affichageTest(int& paragrapheActuel,int& ligneActuelle)
////{
////    cout << "paragraphe : " << paragrapheActuel << endl;
////    cout << "ligne actuelle : " << ligneActuelle << endl;
////    cout << "dialogue size : " << dialogue.size() << endl;
////}