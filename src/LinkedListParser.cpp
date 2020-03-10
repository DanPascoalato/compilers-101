#include <iostream>

using namespace std;

union Value {
    int intValue;
    double doubleValue;
    char *charValue;
};

class Node {
    public:
        Value value;
        Node* next;

    private:
        Node() {
            value = Value();
        }

    public:
        Node(int intValue, Node* nextNode) {
            Node();
            value.intValue = intValue;
            next = nextNode;
        }

        Node (double doubleValue, Node* nextNode) {
            Node();
            value.doubleValue = doubleValue;
            next = nextNode;
        }

        Node (char charValue, Node* nextNode) {
            Node();
            value.charValue = &charValue;
            next = nextNode;
        }

};



int main() {

    Node node = Node(123, NULL);
    cout << "Token -> Value -> i: " << node.value.intValue << endl;
//    cout << "Token -> Value -> r: " << node.value.doubleValue << endl;
//    cout << "Token -> Value -> t: " << *node.value.charValue << endl;
}