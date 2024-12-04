#include "ModeConsole.h"
#include <iostream>
#include <thread>
#include <chrono>

using std::cout;
using std::endl;

ModeConsole::ModeConsole(Game& gameRef) : jeu(gameRef) {}

void ModeConsole::executer(int iterations) {
    cout << "Debut de la simulation" << endl;
    cout << "\nGeneration 0 :" << endl;
    afficherGrille();

    for (int i = 1; i <= iterations; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        jeu.nextGeneration();
        cout << "\nGeneration " << i << " :" << endl;
        afficherGrille();
    }

    cout << "Fin de la simulation" << endl;
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