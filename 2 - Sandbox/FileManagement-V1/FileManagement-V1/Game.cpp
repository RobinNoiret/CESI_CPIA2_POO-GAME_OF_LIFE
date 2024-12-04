#include "Game.h"
#include "ModeConsole.h"
#include "FileManager.h"
#include <iostream>

using namespace std;

Game::Game(const std::string& file)
    : nomFichier(file),
    logs(file),
    iterations(0) {  // Initialisation de iterations
    class file fileManager(file, true);
    int l, L;
    vector<vector<int>> grilleEntree = fileManager.readGridFile(l, L);
    grille = Grille(grilleEntree, l, L);
    fileManager.close();
}

void Game::GameModeConsole() {
    ModeConsole mode(*this);
    cout << "Entrez le nombre d'iterations souhaite : ";
    cin >> iterations;
    mode.executer(iterations);
}

void Game::nextGeneration() {
    grille.calculerProchaineGeneration();
}

void Game::sauvegarderEtat(int numeroGeneration) {
    logs.sauvegarderGeneration(grille, numeroGeneration);
}

const Grille& Game::getGrille() const {
    return grille;
}