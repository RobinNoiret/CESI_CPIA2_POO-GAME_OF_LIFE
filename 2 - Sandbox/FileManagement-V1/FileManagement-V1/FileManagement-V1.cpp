#include <iostream>
#include "FileManager.h"
#include "Grille.h"

using std::cout;
using std::endl;
using std::exception;

int main() {

    string filePath;
    cout << "Entrez le nom du fichier source : ";
    cin >> filePath;


    file myFile(filePath, true);
    int l, L;
    vector<vector<int>> grilleEntree;

    try {
        // Lire le fichier
        grilleEntree = myFile.readGridFile(l, L);

        // Créer la grille
        Grille grille(grilleEntree, l, L);

        // Demander le nombre d'itérations à l'utilisateur
        int nombreIterations;
        cout << "Entrez le nombre d'iterations souhaite : ";
        cin >> nombreIterations;

        // Afficher état initial
        cout << "Dimensions : " << l << "x" << L << endl;
        cout << "\nGeneration 0 :" << endl;
        grille.afficherGrille();

        // Simuler plusieurs générations
        for (int gen = 1; gen <= nombreIterations; gen++) {

            // Calculer la génération suivante
            grille.calculerProchaineGeneration();

            // Afficher la nouvelle génération
            cout << "\nGeneration " << gen << " :" << endl;
            grille.afficherGrille();
        }

    }
    catch (const exception& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    myFile.close();
    return 0;
}