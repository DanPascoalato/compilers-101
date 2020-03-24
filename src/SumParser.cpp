#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_math_operator(char);
bool is_eol(char);



class Node {
    int value;

    public:
        Node(int value) {
            this->value = value;
        }
};

class MathOperation {

    public:
        char op;
        Node* left;
        Node* right;

    MathOperation(Node *left, char op, Node *right) {
        this->left = left;
        this->op = op;
        this->right = right;
    }

};

int main() {
    string input = "20 + 32 * 47 * 2^10 + 130";
    string buffer = "";
    vector<MathOperation*> ops;

    long acc = 0;
    for(int i = 0, j = 0; i <= input.length(); i++){
        char chr = input[i];

        if(isdigit(chr)){
            buffer += chr;
        }
        else if(is_math_operator(chr)){
            Node* left = new Node(stoi(buffer));
            Node* right = NULL;

            if (!ops.empty()) {
                ops[j-1]->right = left;
            }

            ops.push_back(new MathOperation(left, chr, right));
            j++;
            buffer = "";
        }
        else if(is_eol(chr)) {
            Node* node = new Node(stoi(buffer));
            ops[j-1]->right = node;
        }
    }

}


bool is_eol(char chr) {
    return chr == '\0';
}

bool is_math_operator(char chr){
    return chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '^';
}