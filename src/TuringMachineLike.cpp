#include <iostream>

using namespace std;

typedef void (*fnptr)(const char*);
string output = "";

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

void store(const char* charSeq) {
    output += charSeq[0];
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
        case ',': fn = &store; break;
        case '#': fn = &print_first_10; break;
    }
    return fn;
}

class Instruction {

public:
    fnptr function;
    char op;
    const char **head_ptr;
    Instruction* _next;

    Instruction(char op, const char *head) {
        this->function = fn_select(op);
        this->op = op;
        this->head_ptr = &head;
        this->_next = nullptr;
    }

    Instruction* next(Instruction* instruction) {
        this->_next = instruction;
        return this;
    }

    void execute() {
        function(*head_ptr);
    }
};

Instruction* resolve(const char* instructions, const char* head) {
    char op = instructions[0];

    if (op == '\0') {
        return nullptr;
    }
    else {
        if (op == '[') {
            Instruction *loop_instr = resolve(++instructions, head);

            /** Inner loop **/
            Instruction *loop_next_instr = resolve(++instructions, head);
            loop_instr->next(loop_next_instr);
            /** End of the Inner Loop */

            return loop_instr;
        }
        else if (op == ']') {

            if (head[0] == '\0') {
                Instruction *next = resolve(++instructions, head);
                return next;
            }
            else {
                do { --instructions; } while (instructions[0] != '[');
                Instruction *next = resolve(++instructions, head);
                return next;
            }
        }
        else {
            Instruction *instr = new Instruction(op, head);

            //TODO: Debug why calling execute for move_right and left won't work
            if (instr->function == &move_right) {
                head++;
            } else if (instr->function == &move_left) {
                head--;
            } else {
                instr->execute();
            }

            Instruction *next = resolve(++instructions, head);
            return instr->next(next);
        }
    }
}


int main() {
    string _expr = "marrocos";
    string _instr = "+[>,]<-[+.<-]";

    const char* expr = _expr.c_str();
    const char* instr = _instr.c_str();
    const char* head = &expr[0];

    Instruction *pInstruction = resolve(instr, head);

    return 0;
}