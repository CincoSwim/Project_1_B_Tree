#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "disk.h"
#include "BTreeNode.h"
using namespace std;

int main() {


    bool quitProgram = false;
    BTree tree(8);
    int term = 0;

    while (quitProgram == false){
        cout << endl;
        cout << "Input Action - (A)dd, (L)ookup, (R)emove, (D)ump, (Q)uit: ";

        char inputCMD;
        cin  >> setw(1) >> inputCMD;
        char input = toupper(inputCMD);
        //char input = 'A';
        switch (input) {
            case 'A':
                cin.clear();
                while (cin.get()!= '\n'){continue;}
                cout << "Enter Term for Insertion: ";
                term = 0;
                term = 17;
                //term.resize(64);
                tree.AddTerm(term);
                tree.AddTerm(23);
                break;

            case 'L':
                cin.clear();
                while (cin.get()!= '\n'){continue;}
                cout << "Enter Search Term: ";
                //term = "";
                //getline (cin, term);
               // term.resize(64);
                tree.search(term);
                break;

            case 'R':
                cin.clear();
                while (cin.get()!= '\n'){continue;}
                cout << "Enter Term for Removal: ";
                //term = "";
               // getline (cin, term);
                //term.resize(64);
                tree.RemoveTerm(term);
                break;

            case 'D':
                tree.traverse();
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
