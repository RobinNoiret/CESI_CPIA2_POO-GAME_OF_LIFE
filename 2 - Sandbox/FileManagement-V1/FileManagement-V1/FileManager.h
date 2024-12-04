#pragma once
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

// Includes bibliothèques
#include <iostream>		// Gère les entrées/sorties standard (cout, cin)
#include <fstream>		// Gère les opérations de lecture/écriture de fichiers
#include <string>		// Fournit la classe string pour manipuler les chaînes de caractères
#include <vector>		// Implémente le conteneur vector
#include <sstream>		// Permet de manipuler des chaînes comme des flux (conversion de texte)

// Namespace
using namespace std;

class file {
private:
	string name;		// Nom du fichier à manip
	bool openMode;		// Mode d'ouverture : true = lecture & false = écriture
	ifstream fluxin;	// Flux pour la lecture du fichier
	ofstream fluxout;	// Flux pour l'écriture dans le fichier

public:
	// Constructeur & Destructeur
	file(string name, bool openMode);
	~file();

	// Getters
	string getName();
	string getOpenMode();
	string read();
	vector<vector<int>> readGridFile(int& l, int& L);

	void write(string towrite);
	void close();
};
#endif