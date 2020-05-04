#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

#define MAX 3000

using namespace std;


vector<string> split_expr(string expr) {
    vector<string> words;
    string word = "";

    for (auto token : expr) {
        if (token == ' ') {
            cout << word << endl;
            words.push_back(word);
            word = "";
        }
        else{
            word.push_back(token);
        }
    }

    words.push_back(word);
    return words;
}


int main() {

    string expr;
    
    while(getline(cin, expr, '\n')) {
        const char *str = expr.c_str();
        const vector<string> tokens = split_expr(str);
        cout << endl;
    }

    return 0;
}