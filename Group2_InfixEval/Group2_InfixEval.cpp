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
    string eval;

    while(getline(fin, exp)) {
        cout << exp << endl;
        //eval = evaluate(infix_to_postfix(exp));

        fout << eval << endl;
    }

    fin.close();
    fout.close();
    
    return 0;
}