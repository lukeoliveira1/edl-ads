#include <iostream>

using namespace std;

class Node {
    public:
        char value;
        // double chained
        Node* next; // A -> B -> C
        Node* previous; // A <- B <- C

        Node (char value) : value(value), next(nullptr), previous(nullptr) {}
};

class Deque {
    public:
        Node* head;
        Node* tail;
        int size;

        Deque () : head(nullptr), tail(nullptr), size(0) {}

        void push_head_deque(int value) {
            Node* node = new Node(value);

            if (size == 0) {
                head = node; // A
                tail = node; // A
            } else {
                node->next = head; // B -> A
                head->previous = node; // B <- A
                head = node; // head = B
            }

            size++;
        }

        void push_tail_deque(int value) {
            Node* node = new Node(value);

            if (size == 0) {
                head = node; // A
                tail = node; // A
            } else {
                node->previous = tail; // A <- B
                tail->next = node; // A -> B
                tail = node; // tail = B
            }

            size++;
        }

        void pop_head_deque() {
            if (size == 0) {
                return;  
            }
            Node* node_to_be_removed = head; // node_to_be_removed = A
            head = head->next; // head = B (A -> B)
            head->previous = nullptr;  // (nullptr <- B)
            delete node_to_be_removed;
            size--;
        }

        void pop_tail_deque() {
            if (size == 0) {
                return;  
            }
            Node* node_to_be_removed = tail; // node_to_be_removed = B
            tail = tail->previous; // tail = A (A <- B)
            tail->next = nullptr;  // (A -> nullptr)
            delete node_to_be_removed;
            size--;
        }

        char get_head_deque() {
            if (size == 0) {
                cout << "Deque vazio" << endl;  
                return '\0';
            }
            return head->value;
        }

        char get_tail_deque() {
            if (size == 0) {
                cout << "Deque vazio" << endl;  
                return '\0';           
            }
            return tail->value;
        }

        int get_size_deque() {
            return size;
        }

        bool is_empty() {
            return size == 0;
        }

        void print_deque() {
            int aux = 0;
            Node* temp_head = head;

            cout << "Deque: " << endl;
            while (aux < size) {
                cout << temp_head->value << " ";
                temp_head = temp_head->next; // temp_head = B (A -> B)
                aux++;
            }
        }

        bool eh_simetrico() {
            int middle_deque = size / 2;
            string from_head_to_the_middle = "";
            string from_tail_to_the_middle = "";

            Node* temp_head = head; // temp_head = A
            Node* temp_tail = tail; // temp_tail = D

            for(int i=0; i < middle_deque; i++) {
                from_head_to_the_middle += temp_head->value;
                from_tail_to_the_middle += temp_tail->value;

                temp_head = temp_head->next; // temp_head = A
                temp_tail = temp_tail->previous; // temp_tail = C (C <- D)
            }

            return from_head_to_the_middle == from_tail_to_the_middle;
        }
};

Deque create_deque() {
    Deque deque;
    return deque;
};

void test_is_even_symmetric() {
    Deque deque = create_deque();

    deque.push_head_deque('A');
    deque.push_head_deque('B');
    deque.push_head_deque('A');
    deque.push_head_deque('A');
    deque.push_head_deque('B');
    deque.push_head_deque('A');

    cout << "Eh simetrico? " << deque.eh_simetrico() << endl;
    deque.print_deque();
};

void test_is_odd_symmetric() {
    Deque deque = create_deque();

    deque.push_head_deque('X');
    deque.push_head_deque('Y');
    deque.push_head_deque('Z');
    deque.push_head_deque('Y');
    deque.push_head_deque('X');

    cout << "Eh simetrico? " << deque.eh_simetrico() << endl;
    deque.print_deque();
};

void test_is_not_symmetric() {
    Deque deque = create_deque();

    deque.push_head_deque('A');
    deque.push_head_deque('B');
    deque.push_head_deque('C');
    deque.push_head_deque('X');
    deque.push_head_deque('Y');
    deque.push_head_deque('A');

    cout << "Eh simetrico? " << deque.eh_simetrico() << endl;
    deque.print_deque();
};

void test_deque() {
    Deque deque = create_deque();

    cout << "O deque esta vazio? " << (deque.is_empty() ? "Sim" : "Nao") << endl;

    deque.push_head_deque('A');
    deque.push_tail_deque('B');
    deque.push_head_deque('C');
    deque.push_tail_deque('D');

    cout << "Tamanho do deque: " << deque.get_size_deque() << endl;

    cout << "Head do deque: " << deque.get_head_deque() << endl;
    cout << "Tail do deque: " << deque.get_tail_deque() << endl;

    deque.pop_head_deque();
    deque.pop_tail_deque();

    cout << "Tamanho do deque: " << deque.get_size_deque() << endl;

    cout << "O deque esta vazio? " << (deque.is_empty() ? "Sim" : "Nao") << endl;

    bool isSymmetric = deque.eh_simetrico();
    cout << "O deque eh simetrico? " << (isSymmetric ? "Sim" : "Nao") << endl;
};

int main() {
   
    test_is_even_symmetric();
    test_is_odd_symmetric();
    test_is_not_symmetric();
    test_deque();
    
    return 0;
}