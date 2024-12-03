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

int Grille::compterVoisinsVivants(int ligne, int colonne) const {
    int nbVoisinsVivants = 0;

    // Parcourir les 8 cases voisines
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // Ignorer la cellule elle-même
            if (i == 0 && j == 0) continue;

            // Calculer les coordonnées du voisin
            int ligneVoisin = ligne + i;
            int colonneVoisin = colonne + j;

            // Vérifier si le voisin est dans la grille
            if (ligneVoisin >= 0 && ligneVoisin < lignes && colonneVoisin >= 0 && colonneVoisin < colonnes) {
                if (grille[ligneVoisin][colonneVoisin].getEtat()) {
                    nbVoisinsVivants++;
                }
            }
        }
    }

    return nbVoisinsVivants;
}

bool Grille::appliquerRegles(int ligne, int colonne, int nbVoisinsVivants) const {
    bool etatActuel = grille[ligne][colonne].getEtat();

    if (etatActuel) {
        // Cellule vivante
        return nbVoisinsVivants == 2 || nbVoisinsVivants == 3;
    }
    else {
        // Cellule morte
        return nbVoisinsVivants == 3;
    }
}

void Grille::calculerProchaineGeneration() {
    // Créer une grille temporaire pour savoir quelles cellules doivent changer d'état
    vector<vector<bool>> doitChanger(lignes, vector<bool>(colonnes, false));

    // Déterminer quelles cellules doivent changer d'état
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            int voisinsVivants = compterVoisinsVivants(i, j);
            bool etatActuel = grille[i][j].getEtat();

            if (etatActuel) {
                // Cellule vivante
                if (voisinsVivants < 2 || voisinsVivants > 3) {
                    doitChanger[i][j] = true;  // La cellule doit mourir
                }
            }
            else {
                // Cellule morte
                if (voisinsVivants == 3) {
                    doitChanger[i][j] = true;  // La cellule doit naître
                }
            }
        }
    }

    // Appliquer les changements d'état
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            if (doitChanger[i][j]) {
                grille[i][j].changeEtat();
            }
        }
    }
}