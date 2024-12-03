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

private:
    int compterVoisinsVivants(int ligne, int colonne) const;
    bool appliquerRegles(int ligne, int colonne, int nbVoisinsVivants) const;

public:
    // Constructeur
    Grille(const vector<vector<int>>& grilleEntree, int l, int L);

    // Méthodes d'accès
    Cellule& getCellule(int ligne, int colonne);
    const Cellule& getCellule(int ligne, int colonne) const;
    void afficherGrille() const;
    int getLignes() const;
    int getColonnes() const;
    void calculerProchaineGeneration();
};

#endif // GRILLE_H