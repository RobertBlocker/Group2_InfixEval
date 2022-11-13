#include <iostream>
#include <stack>
#include <string>

using namespace std;

/** Returns if character is an operator.
    @param op: operator for operation
    @return: {true} if character is operator; {false} otherwise
*/
bool is_operator(char op)
{
    return (op == '|' || op == '&' || op == '=' || op == '!' || op == '>' || op == '<' || op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '^');
}

/** Returns the precedence of an operator.
    @param op: operator to return its precedence
    @return: precedence
    @throws exception: operator unsupported
*/
int precedence(char op) {

    if (op == '|') {
        return 1;
    }
    else if (op == '&') {
        return 2;
    }
    else if (op == '=' || op == '!') {
        return 3;
    }
    else if (op == '>' || op == '<') {
        return 6;
    }
    else if (op == '+' || op == '-') {
        return 5;
    }
    else if (op == '/' || op == '*' || op == '%') {
        return 6;
    }
    else if (op == '^') {
        return 7;
    }
    throw exception("Unsupported operator");
    return 0;
}

/** Converts an infix expression to postfix expression.
    @param infix_exp: infix expression to convert
    @return: postfix expression converted from the infix expression
*/
string infix_to_postfix(string& infix_exp)
{
    int i = 0;
    stack<char> stack;
    string postfix;

    for (char ch : infix_exp) {
        //if open parenthesis is found
        if (ch == '(') { stack.push(ch); }
        //if closing parenthesis
        else if (ch == ')') {
            // Add each operator to the postfix expression string.
            // Pop all operators from the stack, until an opening parenthesis is seen on top of the stack.
            while (stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            //pop opening '('
            stack.pop();
        }

        //find numbers
        if (!is_operator(ch)) {
            postfix = postfix + ch;
            i++;
        }

        //else statement to push operators onto stack and add operators to postfix expression
        else {
            while (!stack.empty() && precedence(ch) <= precedence(stack.top()))
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(ch);
            i++;
        }
    }

    while (!stack.empty()) {
        postfix = postfix + stack.top();
        stack.pop();
    }
    //Take all whitespace from string and remove
    postfix.erase(remove_if(postfix.begin(), postfix.end(), ::isspace), postfix.end());
    string postfix_to_eval;
    //New string that adds space between all char and return string
    for (auto itr : postfix) {
        postfix_to_eval += itr;
        postfix_to_eval += ' ';
    }
    return postfix_to_eval;
}

int main() {
    string infix_exp = "2+2^2*3+(5-3)";
//    cout << "infix expression: ";
//    getline(cin, infix_exp);
    string postfix = infix_to_postfix(infix_exp);
    cout << "converted to postfix: " << postfix << endl;

    system("pause");
    return 0;
}
