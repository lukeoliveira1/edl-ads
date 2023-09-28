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

        void print() {
            Node* current = head;
            while(current != nullptr) {
                cout << current->value << endl;
                current = current->next;
            }
        }

        void removeRepeatedElements() {
            Node* current = head;

            while(current != nullptr) {
                Node* runner = current;

                while(runner->next != nullptr) {

                    if(runner->next->value == current->value) { // A B C (A e B repetidos)
                        Node* nodeToRemove = runner->next;
                        runner->next = runner->next->next; // A -> C  removemos B da pilha
                        delete nodeToRemove;
                        size++;
                    } else {
                        runner = runner->next;
                    }
                }
                current = current->next;
            }
        }
        
};

int main() {
    Stack stack;
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.print();

    stack.removeRepeatedElements();

    cout << "depois de remover: \n";
    stack.print();

    return 0;
}
