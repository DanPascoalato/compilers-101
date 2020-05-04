#include <iostream>
#include <vector>

#define MAX 3000

using namespace std;


bool eval_is_vallid(vector<string> tokens) {
    return true;
}

vector<string> split_expr(string expr) {
    vector<string> words;
    string word;

    for (auto token : expr) {
        if (token == ' ') {
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
        int is_valid_expr = eval_is_vallid(tokens);

        if (is_valid_expr)
            cout << "OK" << endl;
        else
            cout << "Compilation Error" << endl;
    }
    return 0;
}