#include <iostream>
#include <vector>

enum TokenType {
    TEXT=1,
    INTEGER=2,
    FLOAT=3
};

// Only one of the following can be assigned at the same time
union Value {
    int d;
    double f;
    char *t;
};

class Token {

    public:
        TokenType tokenType;
        Value value;

    private:
        Token(TokenType tt) {
            value = Value();
            tokenType = tt;
        }

    public:
        Token(TokenType tt, int integerValue) : Token(tt) { value.d = integerValue; }
        Token(TokenType tt, double doubleValue) : Token(tt) { value.f = doubleValue; }
        Token(TokenType tt, char* tValue) : Token(tt) { value.t = tValue; }
};

using namespace std;

void print(Token* token) {

    switch(token->tokenType) {
        case TokenType::INTEGER:
            cout << "Token (int): " << token->value.d << endl;
            break;
        case TokenType::FLOAT:
            cout << "Token (float): " << token->value.f << endl;
            break;
        case TokenType::TEXT:
            cout << "Token (str): " << token->value.t << endl;
            break;
    }
}

int main() {
    char charSequence[] = "lorem ipsum";

    vector<Token*> tokens = {
        new Token(TEXT, charSequence),
        new Token(INTEGER, 10),
        new Token(FLOAT, 3.14)
    };

    for (Token* token : tokens) {
        print(token);
    }
}

