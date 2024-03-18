//#pragma once
//#ifndef GESTIONDIALOGUE_H
//#define GESTIONDIALOGUE_H
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <vector>
//#include <string>
//
////#include "IaApparence.h"
//
//using namespace sf;
//using namespace std;
//
//class GestionDialogue
//{
//
//    public:
//        GestionDialogue();
//        void ajouterParagraphe(const vector<string> nouveauParagraphe);
//        void ligneSuivante(int& ligneActuelle, int& paragrapheActuel);
//        void lignePrecedente(int& ligneActuelle);
//        void paragrapheSuivant(int ligneActuelle, int paragrapheActuel);
//        string getCurrentLine();
//        void ajouterTexteInitial();
//        void ajouterTexteNote(bool sansNote);
//        void ajouterTexteSingletonEvident();
//        string formaterLigneTexte(string ligneTexte, int nbCaracMax = 20, int nbLigneMax = 4);
//        string avoirLigneDialogue(int& paragrapheActuel, int& ligneActuelle);
//        void affichageTest(int& paragrapheActuel, int& ligneActuelle);
//
//    private:
//        vector<vector<string>> dialogue;
//        /*int paragrapheActuel = 0;
//        int ligneActuelle=0;*/
//        bool initialisation = false;
//        vector<string> nouvelleLigne;
//
//        bool texteInitialise = false;
//};
//
//#endif // GESTIONDIALOGUE