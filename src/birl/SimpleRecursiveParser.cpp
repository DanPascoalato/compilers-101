#include <iostream>
#include <regex>
#include <map>

void expect_statement();

using namespace std;


string line;

void next_line() {
    getline(cin, line);
}


bool expect_start_block() {
    regex start_block(R"(.*\{\s*)");
    smatch results;
    return regex_match(line, results, start_block);
}

bool expect_end_block() {
    regex end_block(R"(\s*\}\s*)");
    smatch results;
    return regex_match(line, results, end_block);
}

void expect_block() {
    expect_start_block();
    next_line();
    expect_statement();
    expect_end_block();
}

void expect_statement() {
    regex constPattern(R"((val)\s(\w+)\s*=\s*(.+))");
    regex funcPattern(R"((def) (\w+)\s*(.*)\s*)");
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
    }
    else {
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