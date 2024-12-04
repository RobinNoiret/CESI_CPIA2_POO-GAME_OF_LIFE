#include "Game.h"
#include "ModeConsole.h"
#include "FileManager.h"
#include <iostream>

using namespace std;

Game::Game(const std::string& filename) {
    file myFile(filename, true);
    int l, L;
    vector<vector<int>> grilleEntree = myFile.readGridFile(l, L);
    grille = Grille(grilleEntree, l, L);
    myFile.close();
}

void Game::GameModeConsole() {
    ModeConsole mode(*this);
    cout << "Entrez le nombre d'iterations souhaite : ";
    cin >> iterations;
    mode.executer(iterations);
}

void Game::GameModeGraphique() {
    // À implémenter plus tard
}

void Game::nextGeneration() {
    grille.calculerProchaineGeneration();
}

const Grille& Game::getGrille() const {
    return grille;
}