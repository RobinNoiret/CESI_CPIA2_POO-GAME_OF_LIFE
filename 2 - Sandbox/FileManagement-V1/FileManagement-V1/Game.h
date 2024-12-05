#ifndef GAME_H
#define GAME_H

#include "Grille.h"
#include "LogsManagement.h"

// Includes biblioth�ques
#include <string>           // Fournit la classe string pour manipuler les cha�nes de caract�res

// Namespace
using namespace std;

class Game {
private:
    Grille grille;          // Grille du jeu
    int iterations;         // Nombre d'it�rations � simuler
    string nomFichier; // Nom du fichier d'entr�e
    LogsManagement logs;    // gestionnaire de logs

public:
    // Constructeur
    Game(const string& file);

    // M�thodes des modes
    void GameModeConsole();
    void GameModeGraphique();

    // M�thodes m�tiers
    void demanderModeGrille();
    void nextGeneration();
    const Grille& getGrille() const;
    void sauvegarderEtat(int numeroGeneration);
    bool estStable(int generation);
};

#endif