#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include "Cellule.h"

using namespace std;

class Grille {
private:
    vector<vector<Cellule>> grille;
    int lignes;
    int colonnes;

public:
    Grille() : lignes(0), colonnes(0) {}
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