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

    Token(TokenType tt, int integerValue) {
        tokenType = tt;
        value = Value();
        value.i = integerValue;
    }

    Token(TokenType tt, double doubleValue) {
        tokenType = tt;
        value = Value();
        value.r = doubleValue;
    }

    Token(TokenType tt, char tValue) {
        tokenType = tt;
        value = Value();
        value.t = &tValue;
    }

};

using namespace std;


int main() {
    Token intToken = Token(INTEIRO, 10);
    cout << "Token -> Value -> i: " << intToken.value.i << endl;

    Token doubleToken = Token(REAL, 3.14);
    cout << "Token -> Value -> r: " << doubleToken.value.r << endl;

    Token charToken = Token(TEXTO, 'z');
    cout << "Token -> Value -> t: " << *charToken.value.t << endl;
}

