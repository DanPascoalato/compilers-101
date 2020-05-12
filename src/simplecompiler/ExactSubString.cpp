#include <iostream>

using namespace std;

int count_substr(string expr, string substr) {
    unsigned int expr_len = expr.length();
    unsigned int substr_len = substr.length();
    int counter = 0;

    if (substr_len > expr_len) {
        return 0;
    }
    else {
        for (unsigned int i = 0, j = substr_len; i + j <= expr_len; i++) {
            auto tmp = expr.substr(i, j);
            if (tmp == substr) counter++;
        }
    }

    return counter;
}


int main() {
    string expr, substr;

    cout << "Original expr: "; getline(cin, expr);
    cout << "Substring: "; getline(cin, substr);

    cout << count_substr(expr, substr) << endl;
    return 0;
}