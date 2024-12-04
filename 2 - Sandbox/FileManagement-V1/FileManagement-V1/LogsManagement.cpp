#include "LogsManagement.h"

// Includes biblioth�ques
#include <fstream>      // G�re les op�rations de lecture/�criture de fichiers
#include <sstream>      // Permet de manipuler des cha�nes comme des flux
#include <ctime>        // Offre des fonctions pour manipuler la date et l'heure
#include <iomanip>      // Fournit des outils pour formater les entr�es/sorties

// Namespace
using namespace std;

LogsManagement::LogsManagement(const string& nomFichierEntree) {
    // R�cup�rer l'heure actuelle
    time_t now = time(nullptr);
    tm localTime;
    localtime_s(&localTime, &now);

    // Formater l'horodatage (YYYYMMDD_HHMMSS)
    ostringstream timestamp;
    timestamp << put_time(&localTime, "%Y%m%d_%H%M%S");     // formater une date/heure (iomanip)

    // Extraire le nom du fichier sans l'extension
    size_t pos = nomFichierEntree.find_last_of('.');
    string baseNom = (pos != string::npos) ? nomFichierEntree.substr(0, pos) : nomFichierEntree;

    // Cr�er le nom du dossier de sortie avec horodatage
    dossierSortie = baseNom + "_out_" + timestamp.str();

    // Cr�er le dossier
    string commande = "mkdir " + dossierSortie;
    system(commande.c_str());
}

void LogsManagement::sauvegarderGeneration(const Grille& grille, int numeroGeneration) {
    // Extraire le nom de base du dossier (sans le timestamp)
    string baseNom = dossierSortie.substr(0, dossierSortie.find("_out_"));

    // Cr�er le nom du fichier selon le format demand�
    string nomFichier = dossierSortie + "/" + baseNom + "_" + to_string(numeroGeneration) + ".txt";

    // Ouvrir le fichier
    ofstream fichier(nomFichier);
    if (!fichier) {
        throw runtime_error("Impossible de cr�er le fichier de log");
    }

    // �crire les dimensions
    fichier << grille.getLignes() << " " << grille.getColonnes() << endl;

    // �crire la matrice
    for (int i = 0; i < grille.getLignes(); i++) {
        for (int j = 0; j < grille.getColonnes(); j++) {
            fichier << (grille.getCellule(i, j).getEtat() ? "1" : "0");
            if (j < grille.getColonnes() - 1) fichier << " ";
        }
        fichier << endl;
    }
}