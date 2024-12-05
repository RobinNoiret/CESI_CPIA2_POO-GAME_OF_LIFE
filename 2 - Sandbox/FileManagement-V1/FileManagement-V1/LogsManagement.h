#ifndef LOGS_MANAGEMENT_H
#define LOGS_MANAGEMENT_H

#include "Grille.h"

// Includes biblioth�ques
#include <string>           // Fournit la classe string pour manipuler les cha�nes de caract�res

// Namespace
using namespace std;

class LogsManagement {
private:
    string dossierSortie;   // Nom du dossier de log
    bool comparerFichiers(const string& fichier1, const string& fichier2);

public:
    // Constructeurs
    LogsManagement() = default;
    LogsManagement(const string& nomFichierEntree);

    // M�thodes m�tier
    void sauvegarderGeneration(const Grille& grille, int numeroGeneration);
    bool estStable(int generation);
};

#endif