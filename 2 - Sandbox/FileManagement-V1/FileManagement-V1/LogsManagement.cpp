#include "LogsManagement.h"

// Includes bibliothèques
#include <fstream>      // Gère les opérations de lecture/écriture de fichiers
#include <sstream>      // Permet de manipuler des chaînes comme des flux
#include <ctime>        // Offre des fonctions pour manipuler la date et l'heure
#include <iomanip>      // Fournit des outils pour formater les entrées/sorties

// Namespace
using namespace std;

LogsManagement::LogsManagement(const string& nomFichierEntree) {
    // Récupérer l'heure actuelle
    time_t now = time(nullptr);
    tm localTime;
    localtime_s(&localTime, &now);

    // Formater l'horodatage (YYYYMMDD_HHMMSS)
    ostringstream timestamp;
    timestamp << put_time(&localTime, "%Y%m%d_%H%M%S");     // formater une date/heure (iomanip)

    // Extraire le nom du fichier sans l'extension
    size_t pos = nomFichierEntree.find_last_of('.');
    string baseNom = (pos != string::npos) ? nomFichierEntree.substr(0, pos) : nomFichierEntree;

    // Créer le nom du dossier de sortie avec horodatage
    dossierSortie = baseNom + "_out_" + timestamp.str();

    // Créer le dossier
    string commande = "mkdir " + dossierSortie;
    system(commande.c_str());
}

void LogsManagement::sauvegarderGeneration(const Grille& grille, int numeroGeneration) {
    // Extraire le nom de base du dossier (sans le timestamp)
    string baseNom = dossierSortie.substr(0, dossierSortie.find("_out_"));

    // Créer le nom du fichier selon le format demandé
    string nomFichier = dossierSortie + "/" + baseNom + "_" + to_string(numeroGeneration) + ".txt";

    // Ouvrir le fichier
    ofstream fichier(nomFichier);
    if (!fichier) {
        throw runtime_error("Impossible de créer le fichier de log");
    }

    // Écrire les dimensions
    fichier << grille.getLignes() << " " << grille.getColonnes() << endl;

    // Écrire la matrice
    for (int i = 0; i < grille.getLignes(); i++) {
        for (int j = 0; j < grille.getColonnes(); j++) {
            fichier << (grille.getCellule(i, j).getEtat() ? "1" : "0");
            if (j < grille.getColonnes() - 1) fichier << " ";
        }
        fichier << endl;
    }
}