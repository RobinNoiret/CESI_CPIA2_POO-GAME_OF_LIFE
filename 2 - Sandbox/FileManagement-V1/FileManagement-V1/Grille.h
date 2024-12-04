#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include "Cellule.h"

using std::vector;

class Grille {
private:
    vector<vector<Cellule>> grille;
    int lignes;
    int colonnes;

public:
    Grille() = default;
    Grille(const vector<vector<int>>& grilleEntree, int l, int L);
    void calculerProchaineGeneration();
    const Cellule& getCellule(int ligne, int colonne) const;
    int getLignes() const;
    int getColonnes() const;

private:
    int compterVoisinsVivants(int ligne, int colonne) const;
    bool doitChanger(int ligne, int colonne) const;
};

#endif