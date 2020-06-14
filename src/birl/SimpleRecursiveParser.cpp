#include <iostream>
#include <regex>
#include <map>

typedef enum {val, def} Symbol;

using namespace std;


string line;

void next_line() {
    getline(cin, line);
}

void expect_block() {
    //TODO: to be implemented
}

void expect_statement() {
    regex constPattern(R"((val)\s(\w+)\s*=\s*(.+))");
    regex funcPattern(R"((def) (\w+)\s*(.*)\s*)");
    regex exitPattern(R"(exit)");

    smatch results;

    if (regex_match(line, results, constPattern)) {
        string symbol = results[1];
        string identifier = results[2];
        string value = results[3];
    } else if (regex_match(line, results, funcPattern)) {
        string symbol = results[1];
        string identifier = results[2];
        string vargs = results[3];
        expect_block();
    } else if (regex_match(line, results, exitPattern)) {
        return;
    }

    next_line();
    expect_statement();
}


int main() {
    next_line();
    expect_statement();
    return 0;
}