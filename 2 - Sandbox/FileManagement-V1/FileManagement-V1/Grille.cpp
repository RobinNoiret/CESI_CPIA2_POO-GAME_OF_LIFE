#include "Grille.h"

// Include Bibliothèque
#include <stdexcept>    // Fournit les classes standards pour la gestion des exceptions

// Namespace
using namespace std;

Grille::Grille(const vector<vector<int>>& grilleEntree, int l, int L)
    : lignes(l), colonnes(L), estTorique(false) {
    grille.resize(lignes, vector<Cellule>(colonnes));

    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            grille[i][j] = Cellule(grilleEntree[i][j] == 1, i, j);
        }
    }
}

const Cellule& Grille::getCellule(int ligne, int colonne) const {
    if (ligne >= 0 && ligne < lignes && colonne >= 0 && colonne < colonnes) {
        return grille[ligne][colonne];
    }
    throw out_of_range("Position invalide");        // Exception (stdexcept)
}

int Grille::getLignes() const {
    return lignes;
}

int Grille::getColonnes() const {
    return colonnes;
}

int Grille::compterVoisinsVivants(int ligne, int colonne) const {
    int nbVoisinsVivants = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int ligneVoisin = getVoisinLigne(ligne, i);
            int colonneVoisin = getVoisinColonne(colonne, j);

            if (!estTorique && (ligneVoisin < 0 || ligneVoisin >= lignes ||
                colonneVoisin < 0 || colonneVoisin >= colonnes)) {
                continue;
            }

            if (grille[ligneVoisin][colonneVoisin].getEtat()) {
                nbVoisinsVivants++;
            }
        }
    }
    return nbVoisinsVivants;
}

bool Grille::doitChanger(int ligne, int colonne) const {
    int voisinsVivants = compterVoisinsVivants(ligne, colonne);
    bool etatActuel = grille[ligne][colonne].getEtat();

    if (etatActuel) {
        return voisinsVivants < 2 || voisinsVivants > 3;
    }
    else {
        return voisinsVivants == 3;
    }
}

void Grille::calculerProchaineGeneration() {
    vector<vector<bool>> doitChangerEtat(lignes, vector<bool>(colonnes, false));

    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            doitChangerEtat[i][j] = doitChanger(i, j);
        }
    }

    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            if (doitChangerEtat[i][j]) {
                grille[i][j].changeEtat();
            }
        }
    }
}

int Grille::getVoisinLigne(int ligne, int offset) const {
    if (estTorique) {
        return (ligne + offset + lignes) % lignes;
    }
    return ligne + offset;
}

int Grille::getVoisinColonne(int colonne, int offset) const {
    if (estTorique) {
        return (colonne + offset + colonnes) % colonnes;
    }
    return colonne + offset;
}

void Grille::setTorique(bool torique) {
    estTorique = torique;
}

bool Grille::getTorique() const {
    return estTorique;
}