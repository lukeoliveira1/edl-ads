#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;

        Node (int value) : value(value), next(nullptr) {}
        
        void alterarNode(int value) {
            this->value = value;
        }

        int obterValor() {
            return this->value;
        }
};

class ListaEncadeada {
    public:
        int size;
        Node* head;

        ListaEncadeada () : size(0), head(nullptr) {}

        void inserirElemento(int valor, int posicao) {
            if (posicao < 0 || posicao > size) {
                cout << "Posição inválida!" << endl;
                return;
            } else {
                Node* novoNode = new Node(valor);

                if (posicao == 0) {
                    novoNode->next = head;
                    head = novoNode;
                    size++;
                    return;
                }

                Node* atualDaPosicao = head;

                for (int i = 0; i < posicao - 1; i++) {
                    atualDaPosicao = atualDaPosicao->next;
                    // vai até a posição desejada (D)
                }

                // deixar o atualDaPosicao entre o atualDaPosicao e o atualDaPosicao->next
                novoNode->next = atualDaPosicao->next; // atualDaPosicao -> E (D -> E)
                atualDaPosicao->next = novoNode; // D -> atualDaPosicao
                // agora: D -> atualDaPosicao -> E
                size++;
            }
        }

        void removerElemento(int valor) {
            if (head == nullptr) {
                cout << "Lista vazia" << endl;
                return;
            }

            if (head->value == valor) {   
                Node* temp_remove = head;
                head = head->next;
                delete temp_remove;
                size--;
                return;
            }

            Node* temp_head = head;
            while (temp_head->next != nullptr) {
                if (temp_head->next->value == valor) {
                    Node* temp_remove = temp_head->next;
                    temp_head->next = temp_remove->next;
                    delete temp_remove;
                    size--;
                    return;
                }
                temp_head = temp_head->next;
            }

            cout << "Valor não encontrado na ListaEncadeada" << endl;
        }

        int obterTamanho() {
            return size;
        }

        void exibirListaEncadeada() {
            Node* temp_head = head;
            
            while (temp_head != nullptr) {
                cout << temp_head-> value << " ";
                temp_head = temp_head->next;
            }
            cout << endl;
        }

      
        int obterElemento(int posicao) {
            if (posicao < 0 || posicao > size) {
                cout << "Posição inválida!" << endl;
                return -1; // Valor de erro, você pode retornar outro valor adequado
            }

            Node* elementoDaPosicao = head;

            for (int i = 0; i < posicao; i++) {
                elementoDaPosicao = elementoDaPosicao->next;
            }

            return elementoDaPosicao->value;
        }

        int obterProximo(int posicao) {
            if (posicao < 0 || posicao > size) {
                cout << "Posição inválida!" << endl;
                return -1; // Valor de erro, você pode retornar outro valor adequado
            }

            Node* elementoDaPosicao = head;

            for (int i=0; i < posicao + 1; i++) {
                elementoDaPosicao = elementoDaPosicao->next;
            }

            return elementoDaPosicao->value;
        }

        void desalocarLista() {
            Node* temp_head = head;

            while (temp_head != nullptr) {
                Node* atual = temp_head;
                temp_head = temp_head->next;
                delete atual;
            }

            head = nullptr;
            size = 0;
        }

        int deletarElementoNaPosicao(int posicao) {
            if (posicao == 0 || posicao > size) {
                cout << "Posição inválida!" << endl;
                return -1;           
            } else {
                Node* anterior = head;

                for(int i=0; i < posicao - 1; i++) {
                    anterior = anterior->next; 
                    // vai até o elemento anterior do desejado
                }
                
                Node* temp = anterior->next; // temp = ANTERIOR -> (DESEJADO)
                anterior->next = temp->next; // ANTERIOR -> PRÓXIMO_DO_DELETADO
                delete temp;
                size--;
                delete anterior;
            }
        }
};

int main() {
    ListaEncadeada lista;

    lista.inserirElemento(1, 0);
    lista.inserirElemento(2, 1);
    lista.inserirElemento(3, 2);

    lista.exibirListaEncadeada(); //  1 2 3

    lista.inserirElemento(4, 1); // Insere o valor 4 na posição 1
    lista.exibirListaEncadeada(); // 1 4 2 3

    lista.removerElemento(2); // Remove o valor 2
    lista.exibirListaEncadeada(); // 1 4 3

    int valor = lista.obterElemento(2); // 3
    cout << "Valor na posicao 2: " << valor << endl;

    lista.desalocarLista(); 
    return 0;
}