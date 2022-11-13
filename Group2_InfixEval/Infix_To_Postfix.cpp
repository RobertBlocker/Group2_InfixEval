#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_operator(char op)
{
    return (op == '|' || op == '&' || op == '=' || op == '!' || op == '>' || op == '<' || op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '^');
}

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

string infix_to_postfix(string infix)
{
    int i = 0;
    stack<char> stack;
    string postfix;

    for (char ch : infix)
    {
        if (!is_operator(ch))
        {
            postfix = postfix + infix[i];
            i++;
        }
        else
        {
            while (!stack.empty() && precedence(infix[i]) <= precedence(stack.top()))
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(infix[i]);
            i++;
        }
    }

    while (!stack.empty())
    {
        postfix = postfix + stack.top();
        stack.pop();
    }
    postfix.erase(remove_if(postfix.begin(), postfix.end(), ::isspace), postfix.end());
    string postfix_to_eval;
    for (auto itr : postfix) {
        postfix_to_eval += itr;
        postfix_to_eval += ' ';
    }
    return postfix_to_eval;
}

int main() {
    string infix = "2+2^2*3";
//   cout << "infix expression: ";
//    getline(cin, infix);
    string postfix = infix_to_postfix(infix);
    cout << "converted to postfix: " << postfix << endl;

    system("pause");
    return 0;
}
