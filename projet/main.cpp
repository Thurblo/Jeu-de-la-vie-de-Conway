#include <iostream>
#include <string>
#include "Game.h"
#include "Console.h"
#include "GridLoadSave.h"
//#include "UI.h"

using namespace std;

int main() {
    Console console;
    GridLoadSave gls;
    int choixMode = 0;

    cout << "========================================" << endl;
    cout << "              JEU DE LA VIE             " << endl;
    cout << "========================================" << endl;
    cout << "1. Mode Console (Fichiers)" << endl;
    cout << "2. Mode Graphique " << endl;
    cout << "----------------------------------------" << endl;
    cout << "Veuillez choisir un mode (1 ou 2) : ";

	while (!(cin >> choixMode) || (choixMode != 1 && choixMode != 2)) {
        cout << "Entrée invalide. Veuillez entrer 1 ou 2 : ";
       
	}
   
    if (choixMode == 1) {
        console.run(gls);
    }
    else {
        //graphiqueMode 
    }





    return 0;
    
}