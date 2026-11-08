#include <iostream>
#include <string>
#include "Stack.h"
#include "Calculator.h"

using namespace std;

int main() {
    string str = "((a+b)*4/(2-1)";
    Stack<char> stack(100);
    bool res = true;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            stack.push('(');
        }
        else if (str[i] == ')') {
            if (stack.isEmpty()) {
                res = false;
                break;
            }
            stack.pop();
        }
    }

    if (!stack.isEmpty()) res = false;

    cout << res << endl;


    cout << "Calculator" << endl;
    Calculator calc;
    calc.set_infix("(5 + 2.2 * 4.21) + 21 / 3.3");
    calc.infix_to_cont();
    cout << calc.print_tokens();

    return 0;
}