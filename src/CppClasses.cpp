#include <iostream>
#include <cstdint>

enum TokenType {
    TEXTO=1,
    INTEIRO=2,
    REAL=3
};

union Value {
    int i;
    double r;
    char *t;
};


class Token {
    public:
        TokenType tokenType;
        Value value;
};

using namespace std;

int main() {

    Token token;
    token.tokenType = TEXTO;
    token.value.i = 10;
    token.value.r = 3.14;

    cout << token.tokenType << endl;

}

