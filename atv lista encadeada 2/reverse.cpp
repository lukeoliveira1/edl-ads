#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node (int value) : value(value), next(nullptr) {}
};

class Stack {
    public:
        int size;
        Node* head;

        Stack () : size(0), head(nullptr) {}

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            size++;
        }

        void pop() {
            Node* nodeToRemove = head;
            head = head->next;
            delete nodeToRemove;
            size--;
        }

        void print() {
            Node* current = head;

            while(current != nullptr) {
                cout << current->value << endl;
                current = current->next;
            }
        }

        void reverse() {
            Stack reverse;
            Node* current = head;
            // currentStack = 1 2 3
            while(current != nullptr) {
                reverse.push(current->value); 
                current = current->next;
            }
            // reverse = 3 2 1
            current = head;
            while(reverse.size != 0) {
                current->value = reverse.head->value;
                reverse.pop();
                current = current->next;
            }
        }

};
int main() {
 Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.print();

    stack.reverse();

    cout << "depois de reverter: \n";
    stack.print();

    return 0;
}