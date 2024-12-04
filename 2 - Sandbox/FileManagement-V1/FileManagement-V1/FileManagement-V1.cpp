#include "Game.h"
#include <iostream>     // Gère les entrées/sorties standard (cout, cin)

using namespace std;

int main() {
    try {
        string filePath;
        cout << "Entrez le nom du fichier source : ";
        cin >> filePath;

        // Créer le jeu avec le fichier spécifié
        Game jeu(filePath);

        // Lancer le mode console
        jeu.GameModeConsole();

    }
    catch (const exception& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    return 0;
}