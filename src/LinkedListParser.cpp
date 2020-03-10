#include <iostream>

using namespace std;

union Value {
    int intValue;
    double doubleValue;
    string* strValue;
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

        Node (string* strValue, Node* nextNode) {
            Node();
            value.strValue = strValue;
            next = nextNode;
        }

};



int main() {

    string stringValue = "demo string value";
    Node third  = Node(&stringValue, NULL);
    Node second = Node(3.1416, &third);
    Node first = Node(2, &second);

    for (Node* head = &first; head != NULL; head = head->next) {
        cout << "Int Value: " << head->value.intValue << endl;
        cout << "Double Value: " << head->value.doubleValue << endl;
        cout << "String Value: " << head->value.strValue << endl;
        //TODO: implement lookup on String value
        cout << endl;
    }

}