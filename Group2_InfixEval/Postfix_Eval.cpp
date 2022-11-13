#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int calc(int o1, int o2, char c)
{
    if (c == '+') { return o1 + o2; }
    if (c == '-') { return o1 - o2; }
    if (c == '*') { return o1 * o2; }
    if (c == '/') { 
        if (o2 == 0) { throw "divide by zero."; }
        else { return o1 / o2; }
    }
    if (c == '%') { return o1 % o2; }
    if (c == '^') { return (int)pow((double)o1, o2); }
    if (c == '<') {
        if (o1 < o2) { return 1; }
        else { return 0; }
    }
    if (c == '>') {
        if (o1 > o2) { return 1; }
        else { return 0; }
    }
    if (c == '=') {
        if (o1 == o2) { return 1; }
        else { return 0; }
    }
    if (c == '!') {
        if (o1 != o2) { return 1; }
        else { return 0; }
    }
    if (c == '&') {
        if (o1 != 0 && o2 != 0) { return 1; }
        else { return 0; }
    }
    if (c == '|') {
        if (o1 == 0 && o2 == 0) { return 1; }
        else { return 0; }
    }
    else return 0;
}

int evaluate(string exp)
{
    int result = 0;
    stack<int> s;
    int dig = 0;
    int i = 0;
    while (i < exp.length())
    {
        char e = exp[i];
        if (isdigit(exp[i])) {
            dig = dig * 10 + (exp[i] - '0');
        }
        else if (exp[i] == ' ') {
            s.push(dig);
            dig = 0;
        }
        else {
            int o2 = s.top();
            s.pop();
            int o1 = s.top();
            s.pop();
            result = calc(o1, o2, e);
            s.push(result);
            i++;

        }i++;
    }
    return s.top();
}

int main()
{
    string exp = "2 2 2 ^ 3 * +";
    cout << evaluate(exp) << endl;
    system("pause");
    return 0;
    
}