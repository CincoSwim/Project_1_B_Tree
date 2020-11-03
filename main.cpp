#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "disk.h"
using namespace std;

int main() {
    bool quitProgram = false;

    while (quitProgram == false){
        cout << endl;
        cout << "Input Action - (A)dd, (L)ookup, (R)emove, (D)ump, (Q)uit: ";

        char inputCMD;
        cin  >> setw(1) >> inputCMD;
        char input = toupper(inputCMD);

        switch (input) {
            case 'A':

                break;

            case 'L':

                break;

            case 'R':

                break;

            case 'D':

                break;

            case 'Q':
                cout << "Quitting Program";
                quitProgram = true;
                break;

            default:
                cout << "No action done, please check input.";

        }
    }
    return 0;
}
