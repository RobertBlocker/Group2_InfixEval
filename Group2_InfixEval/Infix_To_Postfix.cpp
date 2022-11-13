#include <iostream>
#include <stack>
#include <string>

using namespace std;

int is_operator(char op)
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

    if (infix.size() == 0)
    {
        return "";
    }
    while (infix[i] != '\0') {

        if (!is_operator(infix[i])) {
            postfix = postfix + infix[i] + ' ';
            i++;
        }
        else
        {
            while (!stack.empty() && precedence(infix[i]) <= precedence(stack.top()))
            {
                postfix += stack.top();
                postfix += ' ';
                stack.pop();
            }
            stack.push(infix[i]);
            i++;
        }
    }
    while (!stack.empty())
    {
        postfix = postfix + stack.top() + ' ';
        stack.pop();
    }
    return postfix;
}

int main()
{
    string infix = "2+2^2*3";
//   cout << "infix expression: ";
//    getline(cin, infix);
    string postfix = infix_to_postfix(infix);
    cout << "converted to postfix: " << postfix << endl;

    system("pause");
    return 0;

}

//if (!is_operator(infix[i])) {
//    while (!is_operator(infix[i + 1])) {
//        postfix = postfix + infix[i];
//        i++;
//    }
//    postfix += ' ';
//}