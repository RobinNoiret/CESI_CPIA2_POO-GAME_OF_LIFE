#ifndef GAME_H
#define GAME_H

#include "Grille.h"
#include "LogsManagement.h"
#include <string>

class Game {
private:
    Grille grille;
    int iterations;
    std::string nomFichier;
    LogsManagement logs;  // Ajout du gestionnaire de logs

public:
    Game(const std::string& file);
    void GameModeConsole();
    //void GameModeGraphique();
    void nextGeneration();
    const Grille& getGrille() const;
    void sauvegarderEtat(int numeroGeneration); // Nouvelle méthode
};

#endif