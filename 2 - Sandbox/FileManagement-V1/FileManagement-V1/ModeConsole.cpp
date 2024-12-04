#include "ModeConsole.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

ModeConsole::ModeConsole(Game& gameRef) : jeu(gameRef) {}

void ModeConsole::executer(int iterations) {
    const Grille& grille = jeu.getGrille();

    cout << "Dimensions : " << grille.getLignes() << "x" << grille.getColonnes() << endl;
    cout << "\nGeneration 0 :" << endl;
    afficherGrille();
    jeu.sauvegarderEtat(0);  // Sauvegarde de l'état initial

    for (int i = 1; i <= iterations; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        jeu.nextGeneration();
        cout << "\nGeneration " << i << " :" << endl;
        afficherGrille();
        jeu.sauvegarderEtat(i);  // Sauvegarde de chaque génération
    }

    cout << "Fin de la simulation" << endl;
    cout << "Les etats ont ete sauvegardes" << endl;
}

void ModeConsole::afficherGrille() const {
    const Grille& grille = jeu.getGrille();
    for (int i = 0; i < grille.getLignes(); i++) {
        for (int j = 0; j < grille.getColonnes(); j++) {
            cout << (grille.getCellule(i, j).getEtat() ? "1 " : "0 ");
        }
        cout << endl;
    }
}