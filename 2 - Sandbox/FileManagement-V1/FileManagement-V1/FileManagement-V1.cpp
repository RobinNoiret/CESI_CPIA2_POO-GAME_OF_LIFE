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
        cout << "\nEtat initial de la grille :" << endl;
        grille.afficherGrille();

        // Test d'accès à une cellule spécifique
        cout << "\nEtat de la cellule (0,0) : "
            << (grille.getCellule(0, 0).getEtat() ? "1" : "0") << endl;

        // Test modification via accesseur
        grille.getCellule(0, 0).changeEtat();

        // Afficher après modifications
        cout << "\nEtat apres modifications :" << endl;
        grille.afficherGrille();

        // Test d'accès à une cellule spécifique
        cout << "\nEtat de la cellule (0,0) : "
            << (grille.getCellule(0, 0).getEtat() ? "1" : "0") << endl;
    }
    catch (const exception& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    myFile.close();
    return 0;
}