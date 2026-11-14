#ifndef __Calculator_H__
#define __Calculator_H__

#include <iostream>
#include "Container.h"
#include "Stack.h"

using namespace std;

enum TokenType {
    number, operation, openBracket, closeBracket
};

struct Token {
    TokenType type;
    string str;
    double val;
    int priority;
};

class Calculator
{
protected:
    string infix, postfix;
    Container<Token> inf_cont, post_cont;
    Stack<Token> oper;
    Stack<double> num;
public:
    Calculator() {
        infix = ""; postfix = "";
        inf_cont.clear();
        post_cont.clear();
    }
    void set_infix(string s) {
        num.clean();
        oper.clean();
        inf_cont.clear();
        post_cont.clear();

        bool res = true;
        Stack<char> st(1000);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push('(');
            if (s[i] == ')') {
                if (st.isEmpty() == true) {
                    res = false;
                    break;
                }
                else {
                    st.pop();
                }
            }
        }
        if (res) {
            if (st.isEmpty()) {
                res = true;
            }
            else {
                res = false;
            }
        }

        if (res == false) throw "error";

        infix = "(" + s + ")";
        
    }
    string get_infix() {
        return infix;
    }
    string print_inf_tokens() {
        string res = "";
        for (int i = 0; i < inf_cont.get_size(); i++) {
            res += inf_cont[i].str;
        }
        return res;
    }
    string print_post_tokens() {
        string res = "";
        for (int i = 0; i < post_cont.get_size(); i++) {
            res += post_cont[i].str;
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
                t.priority = 0;
                inf_cont.push_back(t);
            }
            else if (infix[i] == ')') {
                Token t;
                t.type = closeBracket;
                t.str = ")";
                t.priority = 0;
                inf_cont.push_back(t);
            }
            else if (infix[i] == '+') {
                Token t;
                t.type = operation;
                t.str = "+";
                t.priority = 1;
                inf_cont.push_back(t);
            }
            else if (infix[i] == '-') {
                Token t;
                t.type = operation;
                t.str = "-";
                t.priority = 1;
                inf_cont.push_back(t);
            }
            else if (infix[i] == '*') {
                Token t;
                t.type = operation;
                t.str = "*";
                t.priority = 2;
                inf_cont.push_back(t);
            }
            else if (infix[i] == '/') {
                Token t;
                t.type = operation;
                t.str = "/";
                t.priority = 2;
                inf_cont.push_back(t);
            }
            else if (infix[i] == '^') {
                Token t;
                t.type = operation;
                t.str = "^";
                t.priority = 3;
                inf_cont.push_back(t);
            }
            else if (infix[i] >= '0' && infix[i] <= '9' || infix[i]=='.') {
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
    void inf_to_post() {
        oper.clean();
        for (int i = 0; i < inf_cont.get_size(); i++) {
            if (inf_cont[i].type == openBracket) {
                oper.push(inf_cont[i]);
                continue;
            }
            if (inf_cont[i].type == number) {
                post_cont.push_back(inf_cont[i]);
                continue;
            }
            if (inf_cont[i].type == closeBracket) {
                while (oper.top().type != openBracket) {
                    post_cont.push_back(oper.pop());
                }
                oper.pop();
                continue;
            }
            if (inf_cont[i].type == operation) {
                while (inf_cont[i].priority <= oper.top().priority) {
                    post_cont.push_back(oper.pop());
                }
                oper.push(inf_cont[i]);
                continue;
            }
        }
    }

    double calc_postfix() {
        num.clean();
        for (int i = 0; i < post_cont.get_size(); i++) {
            if (post_cont[i].type == number) {
                num.push(post_cont[i].val);
                continue;
            }
            if (post_cont[i].type == operation) {
                double temp2 = num.pop();
                double temp1 = num.pop();
                double res;
                if (post_cont[i].str == "+") {
                    res = temp1 + temp2;
                }
                if (post_cont[i].str == "-") {
                    res = temp1 - temp2;
                }
                if (post_cont[i].str == "*") {
                    res = temp1 * temp2;
                }
                if (post_cont[i].str == "/") {
                    if (temp2 == 0) {
                        throw "error";
                    }
                    res = temp1 / temp2;
                }
                if (post_cont[i].str == "^") {
                    res = pow(temp1, temp2);
                }
                num.push(res);
                continue;
            }
        }
        double res = num.pop();
        if (num.get_size() != -1) {
            throw "error";
        }
        return res;
    }

    double math(string s) {
        this->set_infix(s);
        this->infix_to_cont();
        this->inf_to_post();
        return this->calc_postfix();
    }
};

#endif
