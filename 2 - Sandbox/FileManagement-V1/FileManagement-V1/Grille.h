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
    bool estTorique;                    // Mode torique activé ou non

public:
    // Constructeurs
    Grille() : lignes(0), colonnes(0), estTorique(false) {}
    Grille(const vector<vector<int>>& grilleEntree, int l, int L);

    // Accesseurs
    const Cellule& getCellule(int ligne, int colonne) const;
    int getLignes() const;
    int getColonnes() const;
    void setTorique(bool torique);
    bool getTorique() const;

    // Méthodes métiers
    void calculerProchaineGeneration();

private:
    int compterVoisinsVivants(int ligne, int colonne) const;
    bool doitChanger(int ligne, int colonne) const;
    int getVoisinLigne(int ligne, int offset) const;
    int getVoisinColonne(int colonne, int offset) const;
};

#endif