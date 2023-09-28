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
  
    Stack pilha_par = create_stack();

    Stack pilha_impar = create_stack();

    int n;
    cout << "Quantos numeros voce deseja digitar?" << endl;
    cin >> n;

    int number;

    for (int i=0; i < n; i++) {
        cout << "Digite o numero: " << endl;
        cin >> number;

        if (number % 2 == 0) {
            pilha_par.push_node(number);
        } else {
            pilha_impar.push_node(number);
        }
    }
    
    cout << "Numeros pares invertidos: " << endl;

    for (int i=0; pilha_par.get_size_stack(); i++) {
        cout << pilha_par.get_head_stack() << endl;
        pilha_par.pop_node();
    }

    cout << "Numeros impares invertidos: " << endl;
    
    for (int i=0; pilha_impar.get_size_stack(); i++) {
        cout << pilha_impar.get_head_stack() << endl;
        pilha_impar.pop_node();
    }    
    return 0;
}