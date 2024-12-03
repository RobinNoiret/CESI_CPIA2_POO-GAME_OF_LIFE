#include <iostream>
#include "FileManager.h"
#include "Grille.h"

using std::cout;
using std::endl;
using std::exception;

int main() {
    file myFile("test.txt", true);
    int l, L;
    vector<vector<int>> grilleEntree;

    try {
        // Lire le fichier
        grilleEntree = myFile.readGridFile(l, L);

        // Créer la grille
        Grille grille(grilleEntree, l, L);

        // Afficher les dimensions
        cout << "Dimensions : " << l << "x" << L << endl;
        cout << "\netat initial de la grille :" << endl;
        grille.afficherGrille();

    }
    catch (const exception& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    myFile.close();
    return 0;
}