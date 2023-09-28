#include <iostream>

using namespace std;

// Lista sequencial:
// - FÁCIL ACESSO ao elemento pelo índice
// - díficl remover, adicionar elementos no meio e deslocamentos após remoção/alocação
// - NÃO dinâmico

// Lista dinâmica 
// - fácil alocação/remoção de novos elementos 
// - DIFICIL ACESSO aos elementos
// - dinâmico

// cada posição contém um ponteiro e um valor
// o ponteiro aponta para o próximo elemento da lista
// ao remover elementos é preciso desalocar memória antes para não ter vazamento de memória

struct Node {
  int data;
  Node* next;
};

Node* createNode(int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = nullptr;

  return newNode;
}

void printList(Node* head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
    // Cria uma lista vazia
    Node* head = nullptr;

    // Adiciona alguns elementos à lista
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    // Imprime a lista
    printList(head);

    // Deleta a lista
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}