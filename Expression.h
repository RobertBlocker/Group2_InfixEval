#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stack>
#include <string>

class Expression {
public:

    // Class-member functions
    int precedence(char);
    int eval(std::string);

private:

    std::stack<int> vals;
    std::stack<std::string> ops;
};

#endif