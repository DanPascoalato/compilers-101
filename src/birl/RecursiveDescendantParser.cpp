#include <iostream>
#include <vector>
#include <regex>
#include <map>

using namespace std;

string line;
regex varDeclarationPattern(R"((va[lr])\s(\w+)\s*=\s*(.+))");
regex funcPattern(R"((def) (\w+)\s*(.*)\s*\{\s*)");
regex ifPattern(R"((if)\s+(.*)\s*\{\s*)");
regex whilePattern(R"((while)\s+(.*)\s*\{\s*)");
regex returnPattern(R"((return)\s+(\w+))");

typedef enum {val, def} Symbol;

void next_line() {
    getline(cin, line);
}


bool verify_identifier(string id) {
    regex identifier(R"([A-z][a-z0-9]*)");
    smatch results;
    return regex_match(line, results, varDeclarationPattern);
}

// each line is a block
void block() {
    smatch results;

    if (regex_match(line, results, varDeclarationPattern)) {
        string symbol = results[1];
        string identifier = results[2];
        string vargs = results[3];



    } else if (regex_match(line, results, ifPattern)) {
        string symbol = results[1];
        string condition_expr = results[2];
    } else if (regex_match(line, results, whilePattern)) {
        string symbol = results[1];
        string condition_expr = results[2];
    } else if (regex_match(line, results, funcPattern)) {
        string symbol = results[1];
        string identifier = results[2];
        string vargs = results[3];
    }

}

int main() {
    next_line();
    block();
    return 0;
}
