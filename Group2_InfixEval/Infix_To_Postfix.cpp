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
    
    return 0;
}

/** Converts an infix expression to postfix expression.
    @param infix_exp: infix expression to convert
    @return: postfix expression converted from the infix expression
*/
string infix_to_postfix(string& infix_exp) {
    //int i = 0;
    stack<char> stack;
    string postfix;

    for (int i = 0; i < infix_exp.size(); i++) {
        //if open parenthesis is found
        if (infix_exp[i] == '(') { stack.push(infix_exp[i]); }
        //if closing parenthesis
        else if (infix_exp[i] == ')') {
            // Add each operator to the postfix expression string.
            // Pop all operators from the stack, until an opening parenthesis is seen on top of the stack.
            while (stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
                i++;
            }
            //pop opening '('
            stack.pop();
        }

        //find numbers
        if (!is_operator(infix_exp[i])) {
            postfix += infix_exp[i];

        }

        //else statement to push operators onto stack and add operators to postfix expression
        else {
            while (!stack.empty() && stack.top() != '(' && precedence(infix_exp[i]) <= precedence(stack.top())) {
                postfix += stack.top();
                stack.pop();
            }

            /* If the current operator is two characters long we:
               1) skip the char after the first one is recognized (| is guaranteed to be follow by another |, so use | to represent || skipping the second |) 
               2) or by using a different symbol to recognize it (< can be < or <=, so we use # to represent it and $ for >=)
               We increment i to skip the next character, if the next character creates a two character long operator
            */
            if (infix_exp[i] == '>') {
                i++;
                if (infix_exp[i] == '=') { stack.push('$');  }
                else {
                    stack.push('>');
                    i--;
                }
                
            }
            else if (infix_exp[i] == '<') {
                i++;
                if (infix_exp[i] == '=') { stack.push('#');  }
                else {
                    stack.push('<');
                    i--;
                }
            }
            else if (infix_exp[i] == '=') {                
                stack.push('=');
                i++;
            }
            else if (infix_exp[i] == '!') {
                stack.push('!');
                i++;
            }
            else if (infix_exp[i] == '&') {               
                stack.push('&');
                i++;
            }
            else if (infix_exp[i] == '|') {
                stack.push('|');
                i++;
            }
            else {
                stack.push(infix_exp[i]);

            }
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    //Take all whitespace from string and remove
    postfix.erase(remove_if(postfix.begin(), postfix.end(), ::isspace), postfix.end());
    //Remove any occurrence of '(' or ')' while keeping format correct
    postfix.erase(remove(postfix.begin(), postfix.end(), '('), postfix.end());
    postfix.erase(remove(postfix.begin(), postfix.end(), ')'), postfix.end());
    string postfix_to_eval;
    //New string that adds space between all char and return string
    for (auto itr : postfix) {
        postfix_to_eval += itr;
        postfix_to_eval += ' ';
    }
    return postfix_to_eval;
}

int main() {
    string infix_exp = "88 + 5 * 4 ";
//    cout << "infix expression: ";
//    getline(cin, infix_exp);
    string postfix = infix_to_postfix(infix_exp);
    cout << "converted to postfix: " << postfix << endl;

    system("pause");
    return 0;
}
