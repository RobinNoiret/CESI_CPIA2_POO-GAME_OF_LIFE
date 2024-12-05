#ifndef LOGS_MANAGEMENT_H
#define LOGS_MANAGEMENT_H

#include "Grille.h"

// Includes bibliothèques
#include <string>           // Fournit la classe string pour manipuler les chaînes de caractères

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

    // Méthodes métier
    void sauvegarderGeneration(const Grille& grille, int numeroGeneration);
    bool estStable(int generation);
};

#endif