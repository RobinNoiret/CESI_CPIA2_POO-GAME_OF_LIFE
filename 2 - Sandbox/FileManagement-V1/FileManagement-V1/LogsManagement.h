#ifndef LOGS_MANAGEMENT_H
#define LOGS_MANAGEMENT_H

#include <string>
#include "Grille.h"

using namespace std;

class LogsManagement {
private:
    string dossierSortie;

public:
    // Constructeur prenant le nom du fichier d'entrée
    LogsManagement(const string& nomFichierEntree);

    // Sauvegarde une génération spécifique de la grille
    void sauvegarderGeneration(const Grille& grille, int numeroGeneration);
};

#endif