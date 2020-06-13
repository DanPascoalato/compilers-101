#include <iostream>
#include <vector>
#include <regex>
#include <map>

using namespace std;

typedef enum {
    val, def
} Symbol;

int main() {

    string line;
    smatch results;

    map<string, string> terminals;
    map<string, string> functions;

    regex varDeclarationPattern(R"(va[lr]\s(\w+)\s*=\s*(.+))");
    regex funcPattern(R"(def (\w+)\s*(.*)\s*\{\s*)");
    regex ifPattern(R"(if\s+(.*)\s*\{\s*)");
    regex whilePattern(R"(while\s+(.*)\s*\{\s*)");

    int i = 0;

    while(i <= 2) {
        getline(cin, line);

        if (regex_match(line, results, funcPattern)) {
            cout << "Nome da Func: " << results[1];
            cout << "vargs: " << results[2];
            terminals[results[1]] = results[2];
        } else if (regex_match(line, results, varDeclarationPattern)) {
            functions[results[1]] = results[2];
        } else if (regex_match(line, results, ifPattern)) {
            string condition_expr = results[1];
        } else if (regex_match(line, results, whilePattern)) {
            string condition_expr = results[1];
            cout << condition_expr;
        }
        i++;

    }


    return 0;
}