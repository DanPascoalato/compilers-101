#include <iostream>
#include <stack>
#define MAX 3000

using namespace std;

typedef void (*fnptr)(char**);
string output = "";

void move_right(char** charSeq) {
    ++(*charSeq);
}

void move_left(char** charSeq) {
    --(*charSeq);
}

void next_char(char** charSeq) {
    ++(**charSeq);
}

void prev_char(char** charSeq) {
    --(**charSeq);
}

void print(char** charSeq) {
    output.push_back(**charSeq);
}

void store(char** charSeq) {

}

void loop_start(char** expr) { }

void loop_end(char** expr) { }

fnptr fn_select(char op) {
    void (*fn)(char**);
    switch (op) {
        case '>': fn = &move_right; break;
        case '<': fn = &move_left; break;
        case '+': fn = &next_char; break;
        case '-': fn = &prev_char; break;
        case '[': fn = &loop_start; break;
        case ']': fn = &loop_end; break;
        case '.': fn = &print; break;
        case ',': fn = &store; break;
//        case '#': fn = &print_first_10; break;
    }
    return fn;
}

void execute(char* expr, char* instr) {

    stack<fnptr> fn_stack;

    for (int i = 0, loop_index = 0; instr[i] != '\0'; i++) {
        char op = instr[i];
        fnptr fn = fn_select(op);

        if (fn == &loop_start) {
            loop_index = i;
            continue;
        }
        if (fn == &loop_end) {
            if (*expr != 0) {
                i = loop_index;
            }
            continue;
        }

        fn(&expr);
    }


}




int main() {
    string _expr = "marrocos";
    string _instr = "+[>,]<-[+.<-]";

    char expr[MAX];
    char instr[MAX];

    strncpy(expr, _expr.c_str(), _expr.size()+1);
    strncpy(instr, _instr.c_str(), _instr.size()+1);
    execute(expr, instr);
    cout << output << endl;

    return 0;
}