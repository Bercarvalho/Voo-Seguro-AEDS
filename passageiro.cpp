#include "passageiro.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Cadastrar um passageiro
void cadastrarPassageiro() {
    Passageiro passageiro;
    ofstream file("passageiros.dat", ios::binary | ios::app); // Abre arquivo para adicionar
    if (!file) {
        cerr << "Erro ao abrir arquivo!" << endl;
        return;
    }

    cout << "Digite o código do passageiro: ";
    cin >> passageiro.codigo;

    cin.ignore();
    cout << "Digite o nome do passageiro: ";
    getline(cin, passageiro.nome);

    cout << "Digite o endereço do passageiro: ";
    getline(cin, passageiro.endereco);

    cout << "Digite o telefone do passageiro (11 dígitos): ";
    cin >> passageiro.telefone;

    passageiro.fidelidade = false;    // Fidelidade inicial é false
    passageiro.pontosFidelidade = 0; // Sem pontos inicialmente

    file.write(reinterpret_cast<char*>(&passageiro), sizeof(Passageiro));
    cout << "Passageiro cadastrado com sucesso!" << endl;
    file.close();
}

// Listar todos os passageiros
void listarPassageiros() {
    ifstream file("passageiros.dat", ios::binary); // Abre arquivo para leitura
    if (!file) {
        cout << "Nenhum passageiro cadastrado." << endl;
        return;
    }

    Passageiro passageiro;
    cout << "\n=== Lista de Passageiros ===\n";
    while (file.read(reinterpret_cast<char*>(&passageiro), sizeof(Passageiro))) {
        cout << "Código: " << passageiro.codigo << endl;
        cout << "Nome: " << passageiro.nome << endl;
        cout << "Endereço: " << passageiro.endereco << endl;
        cout << "Telefone: " << passageiro.telefone << endl;
        cout << "Fidelidade: " << (passageiro.fidelidade ? "Sim" : "Não") << endl;
        cout << "Pontos Fidelidade: " << passageiro.pontosFidelidade << endl;
        cout << "---------------------------" << endl;
    }
    file.close();
}

// Associar fidelidade a um passageiro
void associarFidelidade() {
    fstream file("passageiros.dat", ios::binary | ios::in | ios::out); // Leitura e escrita
    if (!file) {
        cerr << "Erro ao abrir arquivo!" << endl;
        return;
    }

    int codigo;
    cout << "Digite o código do passageiro para associar fidelidade: ";
    cin >> codigo;

    Passageiro passageiro;
    bool encontrado = false;

    while (file.read(reinterpret_cast<char*>(&passageiro), sizeof(Passageiro))) {
        if (passageiro.codigo == codigo) {
            passageiro.fidelidade = true;
            file.seekp(-sizeof(Passageiro), ios::cur); // Volta o ponteiro para sobrescrever
            file.write(reinterpret_cast<char*>(&passageiro), sizeof(Passageiro));
            encontrado = true;
            cout << "Fidelidade associada com sucesso!" << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Passageiro não encontrado." << endl;
    }
    file.close();
}

// Atualizar pontos de fidelidade
void atualizarFidelidade() {
    fstream file("passageiros.dat", ios::binary | ios::in | ios::out); // Leitura e escrita
    if (!file) {
        cerr << "Erro ao abrir arquivo!" << endl;
        return;
    }

    int codigo;
    cout << "Digite o código do passageiro para atualizar pontos: ";
    cin >> codigo;

    Passageiro passageiro;
    bool encontrado = false;

    while (file.read(reinterpret_cast<char*>(&passageiro), sizeof(Passageiro))) {
        if (passageiro.codigo == codigo) {
            int novosPontos;
            cout << "Digite os novos pontos de fidelidade: ";
            cin >> novosPontos;
            passageiro.pontosFidelidade = novosPontos;

            file.seekp(-sizeof(Passageiro), ios::cur); // Volta o ponteiro para sobrescrever
            file.write(reinterpret_cast<char*>(&passageiro), sizeof(Passageiro));
            encontrado = true;
            cout << "Pontos atualizados com sucesso!" << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Passageiro não encontrado." << endl;
    }
    file.close();
}

// Listar passageiros com fidelidade
void listarFidelidade() {
    ifstream file("passageiros.dat", ios::binary); // Apenas leitura
    if (!file) {
        cerr << "Erro ao abrir arquivo!" << endl;
        return;
    }

    Passageiro passageiro;
    bool encontrado = false;

    cout << "\n=== Passageiros com Fidelidade ===\n";
    while (file.read(reinterpret_cast<char*>(&passageiro), sizeof(Passageiro))) {
        if (passageiro.fidelidade) {
            cout << "Código: " << passageiro.codigo << endl;
            cout << "Nome: " << passageiro.nome << endl;
            cout << "Pontos Fidelidade: " << passageiro.pontosFidelidade << endl;
            cout << "---------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Nenhum passageiro com fidelidade ativa." << endl;
    }
    file.close();
}
