#include <iostream>
#include <string>
#include "Stack.h"
#include "Calculator.h"

using namespace std;

int main() {
    Calculator calc;
    cout << calc.math("2+3") << endl;
    cout << calc.math("2+3*3") << endl;
    cout << calc.math("5^3+2") << endl;
    try {
        cout << calc.math("(1.5 + 2.25) * 3.0 ^ 2.0 - 10.5 / 2.5 + (4.75 - 1.25) ^ 2.0 / 2.0") << endl;
    } catch (const char* msg) {
        cout << "Error: " << msg << '\n';
    }
    

    return 0;
}