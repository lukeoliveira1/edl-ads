#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next; // ((head)A -> B -> C(tail))

        Node (int value) : value(value), next(nullptr) {}
};

class Queue {
    public:
        Node* head;
        Node* tail;
        int size;

        Queue () : head(nullptr), tail(nullptr), size(0) {}

        void push_queue(int value) {
            Node* node = new Node(value);
            
            if (size == 0) {
                head = node;// A
                tail = node; // A
            } else {
                tail->next = node; // (A -> B)
                tail = node; // tail = B
            }
            
            size++;
        }

        void pop_queue() {
             if (size == 0) {
                return;
            } else {
                Node* node_to_be_removed;
                node_to_be_removed = head; // node_to_be_removed = A
                head = head->next; // head = B (A -> B)
                delete node_to_be_removed;
                size--;
            }
        }

        void delete_queue() {
            while(size < 0) {
                pop_queue();
            }
        }

        int get_head_queue() {
            if (size == 0) {
                cout << "Fila vazia" << endl;  
                return -1;
            }
            return head->value;
        }

        int get_tail_queue() {
            if (size == 0) {
                cout << "Fila vazia" << endl;  
                return -1;
            }
            return tail->value;
        }

        int get_size_queue() {
            return size;
        }

        void print_queue() {
            int aux = 0;
            Node* temp_head = head; // A

            cout << "Queue: " << endl;
            while (aux < size) {
                cout << temp_head->value << " ";
                temp_head = temp_head->next; // temp_head = B (A -> B)
                aux++;
            }
        }
};

Queue create_queue() {
    Queue queue;
    return queue;
};

void test_queue() {
    Queue queue = create_queue();
    queue.push_queue(5);
    queue.push_queue(4);
    queue.push_queue(3);
    queue.push_queue(2);
    queue.push_queue(1);
    
    queue.pop_queue();

    queue.print_queue();

    cout << "Head: " << queue.get_head_queue() << endl;
    cout << "Tail: " << queue.get_tail_queue() << endl;

    queue.pop_queue();
    queue.pop_queue();

    queue.print_queue();

    queue.delete_queue();
};

int main() {

    test_queue();

    return 0;
};