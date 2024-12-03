#ifndef GRILLE_H
#define GRILLE_H

#include <vector>

using std::vector;

class Grille {
private:
    vector<vector<bool>> grille;
    int lignes;
    int colonnes;

public:
    // Constructeur
    Grille(const vector<vector<int>>& grilleEntree, int l, int L);

    // Méthodes
    bool getEtatCellule(int ligne, int colonne) const;
    void afficherGrille() const;
    const vector<vector<bool>>& getGrille() const;
    int getLignes() const;
    int getColonnes() const;
};

#endif // GRILLE_H