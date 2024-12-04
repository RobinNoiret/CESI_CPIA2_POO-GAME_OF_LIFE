#ifndef GRILLE_H
#define GRILLE_H

#include "Cellule.h"

// Includes bibliothèques
#include <vector>                       // Implémente le conteneur vector

// Namespace
using namespace std;

class Grille {
private:
    vector<vector<Cellule>> grille;     // Matrice de cellules
    int lignes;                         // nb lignes
    int colonnes;                       // nb colonnes

public:
    // Constructeurs
    Grille() : lignes(0), colonnes(0) {}
    Grille(const vector<vector<int>>& grilleEntree, int l, int L);

    // Getters
    const Cellule& getCellule(int ligne, int colonne) const;
    int getLignes() const;
    int getColonnes() const;

    // Méthodes métiers
    void calculerProchaineGeneration();

private:
    int compterVoisinsVivants(int ligne, int colonne) const;
    bool doitChanger(int ligne, int colonne) const;
};

#endif