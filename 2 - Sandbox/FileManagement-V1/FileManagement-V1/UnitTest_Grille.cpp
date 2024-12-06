#include <cassert>
#include "Grille.h"
#include <iostream>
#include <vector>
using namespace std;

/*
void testConstructeurGrille() {
    cout << "===============================" << endl;
    cout << "Test du constructeur de Grille" << endl;
    cout << "===============================" << endl;

    cout << "On cree une grille avec les paramètres suivants :" << endl;
    cout << "- Dimensions : 2 lignes, 3 colonnes" << endl;
    cout << "- Valeurs des cellules : {{1, 0, 1}, {0, 1, 0}}" << endl;
    vector<vector<int>> grilleEntree = { {1, 0, 1}, {0, 1, 0} };
    Grille g(grilleEntree, 2, 3);

    cout << "Le resultat du get est :" << endl;
    cout << "- Lignes : " << g.getLignes() << endl;
    cout << "- Colonnes : " << g.getColonnes() << endl;
    cout << "- Cellule (0, 0) : " << g.getCellule(0, 0).getEtat() << endl;
    cout << "- Cellule (0, 1) : " << g.getCellule(0, 1).getEtat() << endl;
    cout << "- Cellule (1, 0) : " << g.getCellule(1, 0).getEtat() << endl;
    cout << "- Cellule (1, 1) : " << g.getCellule(1, 1).getEtat() << endl;

    assert(g.getLignes() == 2);
    assert(g.getColonnes() == 3);
    assert(g.getCellule(0, 0).getEtat() == true);
    assert(g.getCellule(0, 1).getEtat() == false);
    assert(g.getCellule(1, 0).getEtat() == false);
    assert(g.getCellule(1, 1).getEtat() == true);

    cout << "Le test est valide" << endl;
}

void testAccesseursGrille() {
    cout << "===============================" << endl;
    cout << "Test des accesseurs de Grille" << endl;
    cout << "===============================" << endl;

    cout << "On cree une grille par defaut" << endl;
    Grille g;
    cout << "Le resultat du get est :" << endl;
    cout << "- Lignes : " << g.getLignes() << endl;
    cout << "- Colonnes : " << g.getColonnes() << endl;
    cout << "- Mode torique : " << g.getTorique() << endl;
    assert(g.getLignes() == 0);
    assert(g.getColonnes() == 0);
    assert(g.getTorique() == false);
    cout << "Le test est valide" << endl;

    cout << "On active le mode torique" << endl;
    g.setTorique(true);
    cout << "Le nouveau resultat du get est :" << endl;
    cout << "- Mode torique : " << g.getTorique() << endl;
    assert(g.getTorique() == true);
    cout << "Le test est valide" << endl;
}

void testComptageVoisinsGrille() {
    cout << "===============================" << endl;
    cout << "Test du comptage des voisins" << endl;
    cout << "===============================" << endl;

    cout << "On cree une grille avec les paramètres suivants :" << endl;
    cout << "- Dimensions : 3 lignes, 3 colonnes" << endl;
    cout << "- Valeurs des cellules : {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}}" << endl;
    vector<vector<int>> grilleEntree = { {1, 0, 1}, {0, 1, 0}, {1, 0, 1} };
    Grille g(grilleEntree, 3, 3);

    cout << "On compte les voisins pour chaque cellule :" << endl;
    cout << "- Cellule (0, 0) : " << g.compterVoisinsVivants(0, 0) << endl;
    cout << "- Cellule (0, 1) : " << g.compterVoisinsVivants(0, 1) << endl;
    cout << "- Cellule (1, 1) : " << g.compterVoisinsVivants(1, 1) << endl;

    assert(g.compterVoisinsVivants(0, 0) == 1);
    assert(g.compterVoisinsVivants(0, 1) == 3);
    assert(g.compterVoisinsVivants(1, 1) == 4);

    cout << "Le test est valide" << endl;
}

void testCalculProchaineGeneration() {
    cout << "===============================" << endl;
    cout << "Test du calcul de la prochaine generation" << endl;
    cout << "===============================" << endl;

    cout << "On cree une grille avec les paramètres suivants :" << endl;
    cout << "- Dimensions : 3 lignes, 3 colonnes" << endl;
    cout << "- Valeurs des cellules : {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}}" << endl;
    vector<vector<int>> grilleEntree = { {1, 0, 1}, {0, 1, 0}, {1, 0, 1} };
    Grille g(grilleEntree, 3, 3);

    cout << "Etat initial de la grille :" << endl;
    for (int i = 0; i < g.getLignes(); i++) {
        for (int j = 0; j < g.getColonnes(); j++) {
            cout << g.getCellule(i, j).getEtat() << " ";
        }
        cout << endl;
    }

    cout << "Calcul de la prochaine generation" << endl;
    g.calculerProchaineGeneration();

    cout << "Nouvel etat de la grille :" << endl;
    for (int i = 0; i < g.getLignes(); i++) {
        for (int j = 0; j < g.getColonnes(); j++) {
            cout << g.getCellule(i, j).getEtat() << " ";
        }
        cout << endl;
    }

    assert(g.getCellule(0, 0).getEtat() == false);
    assert(g.getCellule(0, 1).getEtat() == true);
    assert(g.getCellule(0, 2).getEtat() == false);
    assert(g.getCellule(1, 0).getEtat() == true);
    assert(g.getCellule(1, 1).getEtat() == false);
    assert(g.getCellule(1, 2).getEtat() == true);
    assert(g.getCellule(2, 0).getEtat() == false);
    assert(g.getCellule(2, 1).getEtat() == true);
    assert(g.getCellule(2, 2).getEtat() == false);

    cout << "Le test est valide" << endl;
}

int main() {
    testConstructeurGrille();
    testAccesseursGrille();
    testComptageVoisinsGrille();
    testCalculProchaineGeneration();
    cout << " " << endl;
    cout << "===============================" << endl;
    cout << "Tous les tests ont reussi !" << endl;
    cout << " " << endl;
    return 0;
}
*/