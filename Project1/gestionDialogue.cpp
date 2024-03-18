//#include "GestionDialogue.h"
//
//GestionDialogue::GestionDialogue()
//{
//    // Gestion du dialogue
//    // Plus précisément, la ligne où l'on se trouve, ce qu'il faut écrire
//    // On ne se préoccupe pas ici de l'affichage, de la mise en forme !
//    // Pour ça, aller dans iaApparence
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
////    // Passer à la ligne suivante
////    if (ligneActuelle < dialogue[paragrapheActuel].size() - 1)
////    {
////        ++ligneActuelle;
////    }
////    else if (ligneActuelle == dialogue[paragrapheActuel].size())
////    {
////        // on est à la dernière ligne du paragraphe, il faut changer de paragraphe
////        paragrapheSuivant(ligneActuelle, paragrapheActuel);
////    }
////}
//
////void GestionDialogue::lignePrecedente(int& ligneActuelle)
////{
////    // Revenir à la ligne précédente
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
////    // On fait la prochaine action de résolution
////}
//
////string GestionDialogue::getCurrentLine() 
////{
////    // Récupérer la ligne de dialogue actuelle
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
////    // Le nombre de caractère d'une ligne est limité à 20
////    // Le nombre de ligne pour une boite de dialogue est de 4 (3 retours à la ligne max)
////    // Soit un total de 20*4 = 60 caractères pour une boite de dialogue
////    string texteFormate;
////    int tailleLigneActuelle = 0;
////    int numeroLigneActuelle = 0;
////
////    for (char c : ligneTexte) 
////    {
////        // Vérifie si le caractère est une espace ou un retour à la ligne
////        if (c == ' ' || c == '\n') 
////        {
////            // Vérifie si l'ajout du prochain mot dépassera la limite de la ligne
////            if (tailleLigneActuelle + 1 > nbCaracMax) 
////            {
////                // Vérifie si l'ajout du prochain mot dépassera la limite du nombre de lignes
////                if (numeroLigneActuelle + 1 < nbLigneMax) 
////                {
////                    texteFormate += '\n'; // Ajoute un retour à la ligne
////                    tailleLigneActuelle = 0; // Réinitialise la longueur de la ligne
////                    numeroLigneActuelle++; // Incrémente le nombre de lignes
////                }
////                else {
////                    break; // Sort de la boucle si le nombre maximum de lignes est atteint
////                }
////            }
////        }
////        // Ajoute le caractère à la chaîne formatée
////        texteFormate += c;
////        // Incrémente la longueur de la ligne
////        tailleLigneActuelle++;
////    }
////
////    return texteFormate;
////}
////
////
////void GestionDialogue::ajouterTexteInitial()
////{
////    // Texte de base à mettre dans le dialogue de l'IA
////    // A mettre même si l'utilisateur ne souhaite pas lire 
////    // pour pouvoir revenir en arrière au cas où
////    nouvelleLigne.clear();
////
////    nouvelleLigne.push_back(formaterLigneTexte("Bonjour, je m'appelle AiDoku !"));
////    nouvelleLigne.push_back(formaterLigneTexte("Je suis une jeune IA capable de résoudre des sudokus."));
////    nouvelleLigne.push_back(formaterLigneTexte("Tu es bloqués dans une grille ? Montre la moi et je t'aiderai à la résoudre."));
////    nouvelleLigne.push_back(formaterLigneTexte("Pour commencer, entre ton sudoku incomplet dans la grille ci-dessous."));
////    nouvelleLigne.push_back(formaterLigneTexte("Lorsque tu as terminé, appuies sur 'Valider'."));
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
////        nouvelleLigne.push_back(formaterLigneTexte("Commençons par prendre des notes."));
////        // explications complémentaires
////        nouvelleLigne.push_back(formaterLigneTexte("Lorsque l'on commence une grille de sudoku, on commence généralement par cette étape."));
////        nouvelleLigne.push_back(formaterLigneTexte("Pour chaque case vide, on regarde quels sont les possibilités."));
////        nouvelleLigne.push_back(formaterLigneTexte("Comme cela fait beaucoup de chose à retenir, on les écrit en petit."));
////        nouvelleLigne.push_back(formaterLigneTexte("On a ainsi une vision globale du jeu !"));
////
////        ajouterParagraphe(nouvelleLigne);
////    }
////
////    // Pour une mise à jour des notes
////    else
////    {
////        nouvelleLigne.push_back(formaterLigneTexte("On peut alors mettre à jour les notes."));
////        // explications complémentaires
////        //if (positionCase.size() < 13)
////        //{
////        //    ajouterLigne(formaterLigneTexte("Plus précisément, les notes ont changés dans les cases suivantes :"));
////        //}
////        //// Si il y a eu trop de changement, pb pour l'affichage, on ne donne que les premiers
////        //else
////        //{
////        //    ajouterLigne(formaterLigneTexte("Les notes ont changés dans de nombreuses cases !"));
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
////    // Texte de base à mettre dans le dialogue de l'IA
////    // A mettre même si l'utilisateur ne souhaite pas lire 
////    // pour pouvoir revenir en arrière au cas où
////    nouvelleLigne.clear();
////    nouvelleLigne.push_back(formaterLigneTexte("Grâce à ces notes, ont ensuite écrire les chiffres des singletons évidents"));
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