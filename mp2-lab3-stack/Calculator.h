#ifndef __Calculator_H__
#define __Calculator_H__

#include <iostream>
#include "Container.h"

using namespace std;

enum TokenType {
    number, operation, openBracket, closeBracket
};

struct Token {
    TokenType type;
    string str;
    double val;
};

class Calculator
{
protected:
    string infix, postfix;
    Container<Token> inf_cont, post_cont;
public:
    Calculator() {
        infix = ""; postfix = "";
        inf_cont.clear();
        post_cont.clear();
    }
    void set_infix(string s) {
        infix = s;
    }
    string get_infix() {
        return infix;
    }
    string print_tokens() {
        string res = "";
        for (int i = 0; i < inf_cont.get_size(); i++) {
            res += inf_cont[i].str + '\n';
        }
        return res;
    }
    void infix_to_cont() {
        inf_cont.clear();
        int i = 0;
        while (i < infix.size()) {
            if (infix[i] == '(') {
                Token t;
                t.type = openBracket;
                t.str = "(";
                inf_cont.push_back(t);
            }
            if (infix[i] == ')') {
                Token t;
                t.type = openBracket;
                t.str = ")";
                inf_cont.push_back(t);
            }
            if (infix[i] == '+') {
                Token t;
                t.type = openBracket;
                t.str = "+";
                inf_cont.push_back(t);
            }
            if (infix[i] == '-') {
                Token t;
                t.type = openBracket;
                t.str = "-";
                inf_cont.push_back(t);
            }
            if (infix[i] == '*') {
                Token t;
                t.type = openBracket;
                t.str = "*";
                inf_cont.push_back(t);
            }
            if (infix[i] == '/') {
                Token t;
                t.type = openBracket;
                t.str = "/";
                inf_cont.push_back(t);
            }
            if (infix[i] >= '0' && infix[i] <= '9' || infix[i]=='.') {
                char* p;
                double val = strtod(&infix[i], &p);
                Token t;
                t.val = val;
                t.type = number;
                t.str = string(&infix[i], p);
                inf_cont.push_back(t);
                int delta = p - &infix[i];
                i += delta - 1;
            }
            i++;
        }
    }
};

#endif
