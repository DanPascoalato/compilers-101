#include <iostream>

using namespace std;

union Value {
    int intValue;
    double doubleValue;
    char* strValue;
};

class Node {
    public:
        enum {INT, DOUBLE, TEXT} tag;
        Value value;
        Node* next;

    private:
        Node(Node* nextNode) {
            this->value = Value();
            this->next = nextNode;
        }

    public:
        Node(int value, Node* next) : Node(next) {
            this->tag = INT;
            this->value = {.intValue=value};
        }
        Node (double value, Node* next) : Node(next) {
            this->tag = DOUBLE;
            this->value = {.doubleValue=value};
        }
        Node (char* value, Node* next) : Node(next) {
            this->tag = TEXT;
            this->value = {.strValue=value};
        }
};

void print(Node* node) {
    switch (node->tag) {
        case Node::INT: cout    << "Integer Value: " << node->value.intValue << endl; break;
        case Node::DOUBLE: cout << "Double  Value: " << node->value.doubleValue << endl; break;
        case Node::TEXT: cout   << "String  Value: " << node->value.strValue << endl; break;
    }
}

int main() {
    char charSequence[] = "demo string value";
    Node* third  = new Node(charSequence, nullptr);
    Node* second = new Node(3.1416, third);
    Node* first = new Node(1, second);

    for (Node* head = first; head != nullptr; head = head->next)
        print(head);
}
