#include <iostream>

using namespace std;

typedef void (*fnptr)(const char*);

void move_right(const char* charSeq) {
    charSeq++;
}

void move_left(const char* charSeq) {
    charSeq--;
}

void next_char(const char* charSeq) {
    char *buffer = const_cast<char *>(charSeq);
    (*buffer)++;
}

void prev_char(const char* charSeq) {
    char *buffer = const_cast<char *>(charSeq);
    (*buffer)--;
}

void print(const char* charSeq) {
    cout << charSeq;
}

void print_first_10(const char* charSeq) {
    char buffer[11];
    strncpy(buffer, charSeq, 10);
    cout << buffer << endl;
}

fnptr fn_select(char op) {
    void (*fn)(const char*);
    switch (op) {
        case '>': fn = &move_right; break;
        case '<': fn = &move_left; break;
        case '+': fn = &next_char; break;
        case '-': fn = &prev_char; break;
        case '(': break;
        case ')': break;
        case '.': fn = &print; break;
        case ',': break;
        case '#': fn = &print_first_10; break;
    }
    return fn;
}

int main() {
    string expr = "marrocos";
    string instructions = "+[>,]<-[+.<-]";

    fnptr fnptr = fn_select('#');
    fnptr(expr.c_str());

    return 0;
}