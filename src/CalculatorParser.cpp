#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool is_math_operator(char);
bool is_eol(char);


class Node {

    public:
        double value;
        Node* left;
        Node* right;

        Node(Node* left, double value, Node* right) {
            this->value = value;
            this->left = left;
            this->right = right;
        }

        Node(Node* left, double value) : Node(left, value, nullptr) { }

        Node(double value) : Node(nullptr, value, nullptr) { }

};


vector<Node*> sort(vector<Node*> operations) {
    vector<Node*> sorted;
    sorted.push_back(operations[3]);
    sorted.push_back(operations[4]);
    sorted.push_back(operations[2]);
    sorted.push_back(operations[1]);
    sorted.push_back(operations[0]);
    sorted.push_back(operations[5]);
    return sorted;
}

double compute(double left, char op, double right) {
    double result;
    switch (op) {
        case '+': result = left + right; break;
        case '-': result = left - right; break;
        case '*': result = left * right; break;
        case '/': result = left / right; break;
        case '^': result = pow(left, right); break;
        default: result = 0.0;
    }
    return result;
}

int main() {
    string input = "20 + 32 * 47 * 2 ^ 10 + 130";
    string buffer = "";
    vector<Node*> nodes;

    Node* current = nullptr;
    Node* previous = nullptr;

    for(int i = 0, j = 0; i <= input.length(); i++) {
        char chr = input[i];

        if(isdigit(chr)) {
            buffer += chr;
        }
        else if(is_math_operator(chr) || is_eol(chr)) {
            previous = current;
            current = new Node(previous, stod(buffer), nullptr);

            if (!nodes.empty()) {
                current->left = previous;
                previous->right = current;
            }

            nodes.push_back(current);
            buffer = "";
            j++;
        }
    }

    vector<Node*> sortedNodes = sort(nodes);
    cout << "Hello" << endl;
}


bool is_eol(char chr) {
    return chr == '\0';
}

bool is_math_operator(char chr){
    return chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '^';
}