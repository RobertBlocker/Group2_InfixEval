#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

#include <string>

bool is_operator(char);
int precedence(char);

std::string infix_to_postfix(std::string&);

#endif