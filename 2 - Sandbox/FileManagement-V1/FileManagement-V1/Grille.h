#ifndef GRILLE_H
#define GRILLE_H

#include "Cellule.h"

// Includes biblioth�ques
#include <vector>                       // Impl�mente le conteneur vector

// Namespace
using namespace std;

class Grille {
private:
    vector<vector<Cellule>> grille;     // Matrice de cellules
    int lignes;                         // nb lignes
    int colonnes;                       // nb colonnes
    bool estTorique;                    // Mode torique activ� ou non

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

    // M�thodes m�tiers
    void calculerProchaineGeneration();
    /*int compterVoisinsVivants(int ligne, int colonne) const;*/        // Uniquement pour les tests unitaires

private:
    int compterVoisinsVivants(int ligne, int colonne) const;            // Le bon du programme
    bool doitChanger(int ligne, int colonne) const;
    int getVoisinLigne(int ligne, int offset) const;
    int getVoisinColonne(int colonne, int offset) const;
};

#endif