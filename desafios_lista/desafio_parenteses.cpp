#include <iostream>

using namespace std;

class Node {
    public:
        char value;
        Node* next; // ((head)A -> B -> C)

        Node(char value) : value(value), next(nullptr) {}
};

class Stack {
    public:
        Node* head;
        int size;

        Stack() : head(nullptr), size(0) {}

        void push_node(char value) {
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

        char get_head_stack() {
            if (size == 0) {
                cout << "Pilha vazia" << endl;
                return -1;
            }
            return head->value;
        }

        bool is_empty() {
            if (size == 0) {
                return true;
            } else {
                return false;
            }
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

int main() {
  
    Stack parentheses = create_stack();

    string expression;
    cout << "Digite uma expressao: " << endl;
    cin >> expression;

    bool is_correct = true;

    for (char character : expression) {
        if (character == '\()') {
            parentheses.push_node(character);
        } 
        if (character != '\)') {
            if (parentheses.get_head_stack() != '\()' and !parentheses.is_empty()) {
                parentheses.pop_node();
            } else {
                is_correct = false;
                break;
            }
        }
    }

    if (is_correct && parentheses.is_empty()) {
        cout << "OK";
    } else {
        cout << "Erro";
    }
    return 0;
}