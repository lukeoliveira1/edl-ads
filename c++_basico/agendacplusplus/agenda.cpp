// Crie um programa em C++ que permita ao usuário realizar as seguintes operações em uma agenda telefônica armazenada em um arquivo TXT chamado "agenda.txt": O usuário informa o nome e o número de telefone do contato, e o programa adiciona essa informação ao arquivo.
// O programa lê o arquivo "agenda.txt" e exibe todos os contatos (nome e telefone) na tela.
// O usuário informa o nome de um contato, e o programa busca essa informação no arquivo e exibe o número de telefone correspondente, se encontrado. Realizar a busca pelo nome também.

// 1 - Cadastrar novos contatos na agenda;
// 2 - Buscar contato pelo telefone;
// 3 - Buscar contato pelo nome;

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void add_contact(const std::string &name, const std::string &phone)
{
    std::ofstream arquivo("agenda.txt", std::ios::app); // Abre o arquivo em modo escrita (sobrescreve)

    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo!\n";
        return;
    }

    arquivo << "Nome: " << name << ", Telefone: " << phone << "\n";

    arquivo.close();
    cout << "Contato adicionado com sucesso!" << std::endl;
}

void search_by_phone(const std::string &phone)
{
    std::ifstream arquivo("agenda.txt"); // Abre o arquivo em modo leitura

    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo!\n";
        return;
    }

    std::string linha;
    bool found = false;
    while (std::getline(arquivo, linha))
    {
        if (linha.find(phone) != std::string::npos)
        {
            std::cout << "Contato encontrado: " << linha << std::endl;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "Contato nao encontrado." << std::endl;
    }

    arquivo.close();
}

void search_by_name(const std::string &name)
{
    std::ifstream arquivo("agenda.txt"); // Abre o arquivo em modo leitura

    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo!\n";
        return;
    }

    std::string linha;
    bool found = false;
    while (std::getline(arquivo, linha))
    {
        if (linha.find(name) != std::string::npos)
        {
            std::cout << "Contato encontrado: " << linha << std::endl;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "Contato nao encontrado." << std::endl;
    }

    arquivo.close();
}

int main()
{
    int option;

    while (option != 0)
    {

        cout << "Agenda C++;" << endl;
        cout << "1 - Cadastrar novos contatos na agenda;" << endl;
        cout << "2 - Buscar contato pelo telefone;" << endl;
        cout << "3 - Buscar contato pelo nome;" << endl;
        cout << "0 - Sair;" << endl;

        cout << "Escolha uma opcao: ";
        cin >> option;
        cin.ignore(); // Ignora o caractere de nova linha após a escolha

        switch (option)
        {
        case 1:
        {
            string name, phone;
            cout << "Digite o nome: ";
            cin >> name;
            cout << "Digite o telefone: ";
            cin >> phone;
            add_contact(name, phone);
            break;
        }
        case 2:
        {
            string phone;
            cout << "Digite o telefone: ";
            cin >> phone;
            search_by_phone(phone);
            break;
        }
        case 3:
        {

            string name;
            cout << "Digite o nome: ";
            cin >> name;
            search_by_name(name);
            break;
        }
        case 4:
            cout << "Saindo..." << endl;
            return 0;
        }
    }
}