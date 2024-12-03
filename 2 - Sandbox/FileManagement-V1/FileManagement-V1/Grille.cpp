#include "Grille.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::out_of_range;

Grille::Grille(const vector<vector<int>>& grilleEntree, int l, int L)
    : lignes(l), colonnes(L) {
    // Redimensionner la grille
    grille.resize(lignes, vector<bool>(colonnes, false));

    // Convertir les int en bool
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            grille[i][j] = (grilleEntree[i][j] == 1);
        }
    }
}

bool Grille::getEtatCellule(int ligne, int colonne) const {
    if (ligne >= 0 && ligne < lignes && colonne >= 0 && colonne < colonnes) {
        return grille[ligne][colonne];
    }
    throw out_of_range("Position invalide");
}

void Grille::afficherGrille() const {
    for (const auto& ligne : grille) {
        for (bool cellule : ligne) {
            cout << (cellule ? "1 " : "0 ");  // Utilisons 1 et 0 pour tester
        }
        cout << endl;
    }
}

const vector<vector<bool>>& Grille::getGrille() const {
    return grille;
}

int Grille::getLignes() const {
    return lignes;
}

int Grille::getColonnes() const {
    return colonnes;
}