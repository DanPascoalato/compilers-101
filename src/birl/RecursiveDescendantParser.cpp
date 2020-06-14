#include <iostream>
#include <vector>
#include <regex>
#include <map>

using namespace std;

typedef enum {
    val, def
} Symbol;

string next_line() {
    string line;
    getline(cin, line);
    return line;
}

int main() {
    smatch results;
    map<string, string> terminals;
    map<string, string> functions;

    regex varDeclarationPattern(R"(va[lr]\s(\w+)\s*=\s*(.+))");
    regex funcPattern(R"(def (\w+)\s*(.*)\s*\{\s*)");
    regex ifPattern(R"(if\s+(.*)\s*\{\s*)");
    regex whilePattern(R"(while\s+(.*)\s*\{\s*)");
    regex returnPattern(R"(return\s+(\w+))");

    string line = next_line();
    if (regex_match(line, results, funcPattern)) {
        terminals[results[1]] = results[2];
    } else if (regex_match(line, results, varDeclarationPattern)) {
        functions[results[1]] = results[2];
    } else if (regex_match(line, results, ifPattern)) {
        string condition_expr = results[1];
    } else if (regex_match(line, results, whilePattern)) {
        string condition_expr = results[1];
        cout << condition_expr;
    } else { }

    return 0;
}
