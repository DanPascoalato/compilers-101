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

void loop_start(const char* expr) { }

void loop_end(const char* expr) { }


fnptr fn_select(char op) {
    void (*fn)(const char*);
    switch (op) {
        case '>': fn = &move_right; break;
        case '<': fn = &move_left; break;
        case '+': fn = &next_char; break;
        case '-': fn = &prev_char; break;
        case '[': fn = &loop_start; break;
        case ']': fn = &loop_end; break;
        case '.': fn = &print; break;
        case ',': break;
        case '#': fn = &print_first_10; break;
    }
    return fn;
}

class Instruction {

public:
    fnptr function;
    char op;
    Instruction* _next;

    Instruction(char op) {
        this->function = fn_select(op);
        this->op = op;
        this->_next = nullptr;
    }

    Instruction* next(Instruction* instruction) {
        this->_next = instruction;
        return this;
    }
};

int main() {
    string _expr = "marrocos";
    string _instr = "+[>]<-[+.<-]";

    const char* expr = _expr.c_str();
    const char* instr = _instr.c_str();
    const char* head = &expr[0];

    return 0;
}