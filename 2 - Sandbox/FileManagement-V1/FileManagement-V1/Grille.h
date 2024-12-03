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
    // Constructeur
    Grille(const vector<vector<int>>& grilleEntree, int l, int L);

    // Méthodes d'accès
    Cellule& getCellule(int ligne, int colonne);
    const Cellule& getCellule(int ligne, int colonne) const;
    void afficherGrille() const;
    int getLignes() const;
    int getColonnes() const;
};

#endif // GRILLE_H