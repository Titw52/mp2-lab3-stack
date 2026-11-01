#include <iostream>
#include <string>
#include "Stack.h"

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
    return 0;
}