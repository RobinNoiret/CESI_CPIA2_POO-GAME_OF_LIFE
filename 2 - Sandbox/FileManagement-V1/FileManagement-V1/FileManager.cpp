#include "FileManager.h"

// Namespace STD
using namespace std;

file::file(string name, bool openMode) :name(name), openMode(openMode) {
	if (this->getOpenMode() == "lecture") {
		fluxin.open(this->name.c_str(), ios::in | ios::binary);
		if (fluxin) {
			cout << "ouverture de " << this->getName() << " reussi!" << endl;
		}
		else {
			cout << "echec d'ouverture de " << this->getName() << endl;
		}
	}
	else {
		fluxout.open(this->name.c_str(), ios::app | ios::binary);
		if (fluxout) {
			cout << "ouverture de " << this->getName() << " reussi!" << endl;
		}
		else {
			cout << "echec d'ouverture de " << this->getName() << endl;
		}
	}
}

string file::getName() {
	return this->name;
}

string file::getOpenMode() {
	if (this->openMode == 1) {
		return "lecture";
	}
	else {
		return "ecriture";
	}
}

string file::read() {
	if (this->getOpenMode() == "ecriture") {
		return "impossible de lire dans ce fichier";
	}
	else {
		string line;
		string content = "";
		while (getline(fluxin, line)) {
			content += line + "\n";
		}
		return content;
	}
}

vector<vector<int>> file::readGridFile(int& l, int& L) {
	if (this->getOpenMode() != "lecture") {
		throw runtime_error("Le fichier doit être ouvert en lecture");
	}

	string line;
	vector<vector<int>> grid;

	// Lecture de l
	getline(fluxin, line);
	l = stoi(line.substr(line.find("=") + 1));

	// Lecture de L
	getline(fluxin, line);
	L = stoi(line.substr(line.find("=") + 1));

	// Ignorer la ligne vide
	getline(fluxin, line);

	// Lecture de la grille
	while (getline(fluxin, line)) {
		if (!line.empty()) {
			vector<int> row;
			istringstream iss(line);
			int value;
			while (iss >> value) {
				row.push_back(value);
			}
			grid.push_back(row);
		}
	}

	return grid;
}


void file::write(string towrite) {
	if (this->getOpenMode() == "ecriture") {
		fluxout << towrite << endl;
	}
	else {
		cout << "Impossible d'�crire dans ce fichier" << endl;
	}
}

void file::close() {
	fluxin.close();
	fluxout.close();
}

file:: ~file() {
	close();
}