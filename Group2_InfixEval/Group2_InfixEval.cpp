#include "Infix_To_Postfix.h"
#include "Postfix_Eval.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin) {
        cout << "The input file does not exist." << endl;
        system("pause");
        return -1;
    }
    
    string exp;

    while(getline(fin, exp)) {
        cout << exp << endl;
        int eval = evaluate(infix_to_postfix(exp));

        fout << eval << endl;
    }

    fin.close();
    fout.close();
    
    return 0;
}