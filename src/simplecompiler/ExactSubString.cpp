#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, string> fn_variables;


int count_substr(string expr, string substr) {
    unsigned int expr_len = expr.length();
    unsigned int substr_len = substr.length();
    int counter = 0;

    if (substr_len > expr_len) {
        return 0;
    }
    else {
        // O(n)
        for (unsigned int i = 0, j = substr_len; i+j <= expr_len; i++) {
            // O(m)
            auto tmp = expr.substr(i, j);
            if (tmp == substr) {
                counter++;
            }
        }
    }

    // O(n * m)
    return counter;
}


int main() {
    string expr;
    string substr;

    cout << "Original expr: ";
    getline(cin, expr);

    cout << "Substring: ";
    getline(cin, substr);

    cout << count_substr(expr, substr) << endl;
    return 0;
}