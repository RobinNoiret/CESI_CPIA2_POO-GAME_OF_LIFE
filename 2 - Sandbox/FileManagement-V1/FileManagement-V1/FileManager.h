#pragma once
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

// Includes bibliothèques
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Namespace STD
using namespace std;

// Class file
class file {
private:
	string name;
	bool openMode; //1 pour lecture et 0 pour �criture
	ifstream fluxin;
	ofstream fluxout;

public:
	file(string name, bool openMode);
	~file();

	string getName();
	string getOpenMode();

	string read();
	vector<vector<int>> readGridFile(int& l, int& L);

	void write(string towrite);
	void close();



};
#endif