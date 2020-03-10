#include <iostream>

enum TokenType {
    TEXTO=1,
    INTEIRO=2,
    REAL=3
};


// Only one of the following can be assigned at the same time
union Value {
    int i;
    double r;
    char *t;
};


class Token {
    public:
        TokenType tokenType;
        Value value;

    private:
        Token() {
            value = Value();
        }

    public:
        Token(TokenType tt, int integerValue) {
            Token();
            tokenType = tt;
            value.i = integerValue;
        }

        Token(TokenType tt, double doubleValue) {
            Token();
            tokenType = tt;
            value.r = doubleValue;
        }

        Token(TokenType tt, char* tValue) {
            Token();
            tokenType = tt;
            value.t = tValue;
        }

};

using namespace std;


int main() {
    Token intToken = Token(INTEIRO, 10);
    cout << "Token -> Value -> i: " << intToken.value.i << endl;

    Token doubleToken = Token(REAL, 3.14);
    cout << "Token -> Value -> r: " << doubleToken.value.r << endl;

    //TODO: Refactoring the Token when the value is text
    // Token charToken = Token(TEXTO, 'z');
    // cout << "Token -> Value -> t: " << *charToken.value.t << endl;
}

