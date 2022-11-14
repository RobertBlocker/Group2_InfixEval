#include <stack>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

/** Calculates for a single operator.
    @param left_op: left operands for operation
    @param right_op: right operands for operation
    @param sign: 
    @return: int for evaluated operation
*/
int calc(int left_op, int right_op, char sign)
{
    if (sign == '+') { return left_op + right_op; }
    if (sign == '-') { return left_op - right_op; }
    if (sign == '*') { return left_op * right_op; }
    if (sign == '/') { 
        if (right_op == 0) { throw "divide by zero."; }
        else { return left_op / right_op; }
    }
    if (sign == '%') { return left_op % right_op; }
    if (sign == '^') { return (int)pow((double)left_op, right_op); }
    if (sign == '<') {
        if (left_op < right_op) { return 1; }
        else { return 0; }
    }
    if (sign == '>') {
        if (left_op > right_op) { return 1; }
        else { return 0; }
    }
    if (sign == '$') {
        if (left_op >= right_op) { return 1; }
        else { return 0; }
    }
    if (sign == '#') {
        if (left_op <= right_op) { return 1; }
        else { return 0; }
    }
    if (sign == '=') {
        if (left_op == right_op) { return 1; }
        else { return 0; }
    }
    if (sign == '!') {
        if (left_op != right_op) { return 1; }
        else { return 0; }
    }
    if (sign == '&') {
        if (left_op != 0 && right_op != 0) { return 1; }
        else { return 0; }
    }
    if (sign == '|') {
        if (left_op == 0 && right_op == 0) { return 1; }
        else { return 0; }
    }
    else return 0;
}

/** Evaluates the postfix expression string to an integer.
    @param exp: the string of expression to be evaluated
    @return: integer of evaluated string
*/
int evaluate(string exp)
{
    int result = 0;
    stack<int> stack;
    int num = 0;
    int i = 0;

    while (i < exp.length())
    {
        char curr = exp[i];


        if (isdigit(exp[i])) {
            num = num * 10 + (exp[i] - '0');
        }
        else if (exp[i] == ' ') {
            stack.push(num);
            num = 0;
        }
        else {
            int right_op = stack.top();
            stack.pop();
            int left_op = stack.top();
            stack.pop();
            result = calc(left_op, right_op, curr);
            stack.push(result);
            i++;

        }i++; 
    }
    return stack.top();
}
