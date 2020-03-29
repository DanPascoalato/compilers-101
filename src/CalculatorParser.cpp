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

        explicit Node(double value) : Node(nullptr, value, nullptr) { }

};

class Operation {

    public:
        char op;
        Node* left;
        Node* right;

    Operation(Node* left, char op, Node *right) {
        this->op = op;
        this->left = left;
        this->right = right;
    }

    Operation(Node* left, char op) : Operation(left, op, nullptr) { }

    explicit Operation(char op) : Operation(nullptr, op, nullptr) { }

};

vector<Operation*> sort(vector<Operation*> operations) {
    vector<Operation*> sorted;
    sorted.push_back(operations[3]);
    sorted.push_back(operations[2]);
    sorted.push_back(operations[1]);
    sorted.push_back(operations[4]);
    sorted.push_back(operations[0]);
    return sorted;
}

Node* compute(Node* left, char op, Node* right) {
    double result;
    switch (op) {
        case '+': result = left->value + right->value; break;
        case '-': result = left->value - right->value; break;
        case '*': result = left->value * right->value; break;
        case '/': result = left->value / right->value; break;
        case '^': result = pow(left->value, right->value); break;
        default: result = 0.0;
    }
    return new Node(left->left, result, right->right);
}

int main() {
    string input = "20 + 32 * 47 * 2 ^ 10 + 130";
    string buffer = "";

    vector<Operation*> operations;
    vector<Node*> nodes;

    Node* node = nullptr;
    Operation* operation = nullptr;

    for(int i = 0, j = 0; i <= input.length(); i++) {
        char chr = input[i];

        if(isdigit(chr)) {
            buffer += chr;
        }
        else if(is_math_operator(chr) || is_eol(chr)) {
            node = new Node(node, stod(buffer), nullptr);
            operation = new Operation(node, chr);

            if (!operations.empty()) {
                operations[j - 1]->right = node;
                nodes[j-1]->right = node;
                node->left = nodes[j-1];
            }

            nodes.push_back(node);
            operations.push_back(operation);
            buffer = "";
            j++;
        }
    }

    vector<Operation*> sortedOps = sort(operations);
    double result = 0.0;

    for (int i = 0; i < sortedOps.size(); i++) {
        Node *left = sortedOps[i]->left;
        Node *right = sortedOps[i]->right;

        Node *resultNode = compute(left, sortedOps[i]->op, right);
        resultNode->left->right = resultNode;
        resultNode->right->left = resultNode;

        result += resultNode->value;
        cout << "Result: " << result << endl;
    }
}


bool is_eol(char chr) {
    return chr == '\0';
}

bool is_math_operator(char chr){
    return chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '^';
}