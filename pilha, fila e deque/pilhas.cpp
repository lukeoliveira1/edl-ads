#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next; // ((head)A -> B -> C)

        Node(int value) : value(value), next(nullptr) {}
};

class Stack {
    public:
        Node* head;
        int size;

        Stack() : head(nullptr), size(0) {}

        void push_node(int value) {
            Node* node = new Node(value);
            node->next = head; // A -> B
            head = node; // head = A
            size++;
        }

        void pop_node() {
            if (size == 0 || head == nullptr) {
                cout << "Pilha vazia" << endl;
                return;
            } else {
                Node* node_to_be_removed;
                node_to_be_removed = head; // node_to_be_removed = A
                head = head->next; // head = B
                delete node_to_be_removed;
                size--;
            }
        }

        void delete_stack() {
           while (head != nullptr) {
                pop_node();
            }
        }

        int get_size_stack() {
            return size;
        }

        int get_head_stack() {
            if (size == 0) {
                cout << "Pilha vazia" << endl;
                return -1;
            }
            return head->value;
        }

        void print_stack() {
            if (head == nullptr) {
                cout << "Pilha vazia." << endl;
                return;
            }
            int aux = 0;
            Node* temp_head = head; // A

            cout << "Stack: " << endl;
            while(aux < size) {
                cout << temp_head->value << endl;
                temp_head = temp_head->next; // temp_head = B (A -> B)
                aux++;
            }
        }
};

Stack create_stack() {
    return Stack();
};

void test_stack() {
    Stack stack = create_stack();
    stack.push_node(5);
    stack.push_node(4);
    stack.push_node(3);
    stack.push_node(2);
    stack.push_node(1);
    
    stack.pop_node();

    cout << stack.get_head_stack() << endl;

    stack.pop_node();
    stack.pop_node();

    stack.print_stack();

    stack.delete_stack();

    cout << stack.get_head_stack() << endl;;

    stack.pop_node();
};

int main() {
  
    test_stack();
    
    return 0;
}