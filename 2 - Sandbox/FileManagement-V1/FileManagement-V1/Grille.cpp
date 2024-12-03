#include "Grille.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::out_of_range;

Grille::Grille(const vector<vector<int>>& grilleEntree, int l, int L)
    : lignes(l), colonnes(L) {
    // Redimensionner la grille
    grille.resize(lignes, vector<Cellule>(colonnes));

    // Initialiser chaque cellule
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            grille[i][j] = Cellule(grilleEntree[i][j] == 1, i, j);
        }
    }
}

Cellule& Grille::getCellule(int ligne, int colonne) {
    if (ligne >= 0 && ligne < lignes && colonne >= 0 && colonne < colonnes) {
        return grille[ligne][colonne];
    }
    throw out_of_range("Position invalide");
}

const Cellule& Grille::getCellule(int ligne, int colonne) const {
    if (ligne >= 0 && ligne < lignes && colonne >= 0 && colonne < colonnes) {
        return grille[ligne][colonne];
    }
    throw out_of_range("Position invalide");
}

void Grille::afficherGrille() const {
    for (const auto& ligne : grille) {
        for (const Cellule& cellule : ligne) {
            cout << (cellule.getEtat() ? "1 " : "0 ");
        }
        cout << endl;
    }
}

int Grille::getLignes() const {
    return lignes;
}

int Grille::getColonnes() const {
    return colonnes;
}