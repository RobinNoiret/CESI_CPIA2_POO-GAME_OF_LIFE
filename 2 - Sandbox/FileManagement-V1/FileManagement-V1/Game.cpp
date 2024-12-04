#include "Game.h"
#include "ModeConsole.h"
#include "FileManager.h"
#include "ModeGraphique.h"

// Include Bibliothèque
#include <iostream>     // Gère les entrées/sorties standard (cout, cin)

// Namespace
using namespace std;

Game::Game(const std::string& file){
    nomFichier = file;
    logs = LogsManagement(file);
    iterations = 0;

    // Lecture du fichier d'entrée
    class file fileManager(file, true);
    int l, L;
    vector<vector<int>> grilleEntree = fileManager.readGridFile(l, L);

    // Création de la grille
    grille = Grille(grilleEntree, l, L);

    fileManager.close();
}

void Game::GameModeConsole() {
    ModeConsole mode(*this);
    cout << "Entrez le nombre d'iterations souhaite : ";
    cin >> iterations;
    mode.executer(iterations);
}

void Game::GameModeGraphique() {
    cout << "Entrez le nombre d'iterations souhaite : ";
    cin >> iterations;

    ModeGraphique mode(*this);
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