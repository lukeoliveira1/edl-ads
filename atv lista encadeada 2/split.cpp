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

        void split(Stack &other) {
            int middle = size / 2;
            Node* current = head;
            Node* previous = nullptr;
            
            for(int i=0; i <= middle; i++) {
                previous = current; // 1 ... 2 ... 3
                current = current->next; // 2 ... 3 ... 4
            }
            
            if (previous != nullptr) {
                previous->next = nullptr; // divide as duas partes da lista
            }

            other.head = current;
            other.size = size - (middle-1);
            size = middle; 
        }
};

int main() {
    Stack stack;
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);

    Stack other;
    stack.split(other);

    cout << "Depois de dividir: \noriginal: \n";
    stack.print();
    cout << "nova: \n";
    other.print();
    return 0;
}