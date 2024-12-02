#include <iostream>
#include "FileManager.h"

int main() {
    file myFile("test.txt", true);  // true pour mode lecture

    int l, L;
    vector<vector<int>> grid;

    try {
        grid = myFile.readGridFile(l, L);

        // Afficher les résultats
        cout << "l = " << l << endl;
        cout << "L = " << L << endl;
        cout << "\nGrille :" << endl;

        for (const auto& row : grid) {
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
    catch (const exception& e) {
        cout << "Erreur : " << e.what() << endl;
    }

    myFile.close();
    return 0;
}