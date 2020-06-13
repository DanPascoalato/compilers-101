#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, string> fn_variables;

enum IdentType { NUMBER, VARIABLE, OPERATOR };

class Token {
    public:
        IdentType type;
        string var;
        string op;
        int value;

        Token(string word) {
            if (word.find_first_not_of("0123456789") == string::npos) {
                this->value = stoi(word);
                this->type = NUMBER;
            }
            else if (word.find_first_not_of("+-*/:=") == string::npos) {
                this->op = word;
                this->type = OPERATOR;
            }
            else {
                this->var = word;
                this->type = VAR;
            }
        }
};

typedef vector<Token*> expr;

bool is_valid_eval(expr expression) {
    auto varname = expression[0]->var;
    vector<Token*> vargs(expression.begin()+2, expression.end());

    if (varname.length() > 8 || varname.find_first_not_of("abcdefghijklmnopqrstwxyz") != string::npos)
        return false;

    for (auto arg : vargs) {
        if (arg->type == VAR)
            if (fn_variables.find(arg->var) == fn_variables.end())
                return false;
    }

    fn_variables[varname] = "value";
    return true;
}

bool is_valid_eval(vector<expr> expressions) {
    for (auto expression: expressions) {
        if (!is_valid_eval(expression))
            return false;
    }
    return true;
}

expr str_to_expr(string expr_str) {
    vector<Token*> tokens;
    string word;

    for (auto token : expr_str) {
        if (token == ' ') {
            tokens.push_back(new Token(word));
            word = "";
        }
        else {
            word.push_back(token);
        }
    }

    if (word != "") {
        tokens.push_back(new Token(word));
    }
    return tokens;
}

int main() {
    vector<expr> expressions;
    string line;

    for (int i = 0; i < 2000; i++) {
        getline(cin, line);
        if (line.empty()) {
            break;
        }
        expr expr = str_to_expr(line);
        expressions.push_back(expr);
    }

    cout << (is_valid_eval(expressions) ? "OK" : "Compilation Error") << endl;
    return 0;
}