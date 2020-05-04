#include <iostream>
#include "libs/tinyexpr.h"

using namespace std;

int main() {
    string expr;

    cout << "Evaluate Expr: ";
    getline(cin, expr);
    double expr_value = te_interp(expr.c_str(), nullptr);

    cout << "Result: " << expr_value << endl;
}