#include <iostream>

using namespace std;

void fn_select(char instruction) {
    switch (instruction) {
        case '>': break;
        case '<': break;
        case '+': break;
        case '-': break;
        case '(': break;
        case ')': break;
        case '.': break;
        case ',': break;
        case '#': break;
    }
}

void move_right(char* charSeq) {
    charSeq++;
}

void move_left(char* charSeq) {
    charSeq--;
}

void next_char(char* charSeq) {
    (*charSeq)++;
}

void prev_char(char* charSeq) {
    (*charSeq)--;
}

int main() {
    string expr = "marrocos";
    string instructions = "+[>,]<-[+.<-]";

    return 0;
}