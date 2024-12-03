// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//






#include <vector>
#include <iostream>
#include <string>

using namespace std;

//class abstraite
class Mode {
	void virtual executer(int iterations) {
		iterations = 0;
	}

};


class ModeConsole : Mode {
private:
	Game& jeu;
	string file;
protected:

public:
	ModeConsole(Game& jeu, string file);

	void executer(int iterations) override {

	}
};


class ModeGraphique : Mode {
private:
	Game& jeu;
	// element SFML
protected:

public:
	void executer(int iterations)override {

	}
};


class Game {
private:
	Grille grille;
	int iterations;
protected:

public:
	void etatInitial(string file) {

	}
	
	int getGrille(...) {

	}

};


class Grille {
private:
	int Longu, Larg;
	vector<vector<Cellule>> cellules;
protected:


public:

	Grille() {};
	// Grille(int Longu, int Larg, cellules ini) {};
	int getLongu() {
		return Longu;
	}

	int getLarg() {
		return Larg;
	}



	void setLongu(int l) {

	}

	void setLarg(int L) {

	}

	void setCellules(...){

	}

	void Afficher(){
	
	}

	int nbVoisinVivants(int x, int y) {

	}

	~Grille();
};


class Cellule {
private:
	int Colonnes, Lignes;
	bool etat;
protected:


public:

	Cellule();
	Cellule(int Colonnes, int Lignes, bool etat);

	int getColonnes() {
		return Colonnes;
	}

	int getLignes() {
		return Lignes;
	}

	bool getEtat() {
		return etat;
	}

	void setColonnes(int Colonnes) {

	}

	void setLignes(int Lignes) {

	}

	void setEtat(bool etat) {

	}


	////
	~Cellule();
	//// 

};






int main()
{

   cout << "Hello World!\n";
   cout << "feur" << endl;
}





























// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
