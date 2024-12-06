#include "Game.h"
#include <iostream>

using namespace std;


int main() {
    try {
        // Demande du fichier source
        string filePath;
        cout << "Entrez le nom du fichier source : ";
        cin >> filePath;

        // Création du jeu
        Game jeu(filePath);

        // Choix du mode
        int choixMode;
        cout << "\nChoisissez le mode :" << endl;
        cout << "1. Mode Console" << endl;
        cout << "2. Mode Graphique" << endl;
        cout << "Votre choix : ";
        cin >> choixMode;

        // Lancement du mode choisi
        switch (choixMode) {
        case 1:
            jeu.GameModeConsole();
            break;
        case 2:
            jeu.GameModeGraphique();
            break;
        default:
            cout << "Mode invalide" << endl;
            break;
        }
    }
    catch (const exception& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    return 0;
}
