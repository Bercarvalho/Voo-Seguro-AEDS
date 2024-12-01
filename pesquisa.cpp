#include "pesquisa.h"
#include "tripulacao.h"
#include "passageiro.h"
#include "reserva.h"
#include <iostream>
#include <fstream>
#include <cstring> // Para strcmp

using namespace std;

// Função para buscar passageiros pelo nome ou código
void buscarPassageiro() {
    ifstream file("passageiros.dat", ios::binary);
    if (!file) {
        cerr << "Erro ao abrir arquivo de passageiros." << endl;
        return;
    }

    int codigo;
    string nome;
    cout << "Digite o código do passageiro (ou 0 para buscar por nome): ";
    cin >> codigo;

    Passageiro passageiro;
    bool encontrado = false;

    if (codigo != 0) {
        while (file.read(reinterpret_cast<char*>(&passageiro), sizeof(Passageiro))) {
            if (passageiro.codigo == codigo) {
                encontrado = true;
                cout << "\n=== Passageiro Encontrado ===\n";
                cout << "Código: " << passageiro.codigo << endl;
                cout << "Nome: " << passageiro.nome << endl;
                cout << "Endereço: " << passageiro.endereco << endl;
                cout << "Telefone: " << passageiro.telefone << endl;
                cout << "Fidelidade: " << (passageiro.fidelidade ? "Sim" : "Não") << endl;
                break;
            }
        }
    } else {
        cout << "Digite o nome do passageiro: ";
        cin.ignore();
        getline(cin, nome);

        while (file.read(reinterpret_cast<char*>(&passageiro), sizeof(Passageiro))) {
            if (passageiro.nome == nome) {
                encontrado = true;
                cout << "\n=== Passageiro Encontrado ===\n";
                cout << "Código: " << passageiro.codigo << endl;
                cout << "Nome: " << passageiro.nome << endl;
                cout << "Endereço: " << passageiro.endereco << endl;
                cout << "Telefone: " << passageiro.telefone << endl;
                cout << "Fidelidade: " << (passageiro.fidelidade ? "Sim" : "Não") << endl;
                break;
            }
        }
    }

    if (!encontrado) {
        cout << "Passageiro não encontrado." << endl;
    }

    file.close();
}

// Função para buscar tripulantes
void buscarTripulante() {
    ifstream file("tripulacao.dat", ios::binary);
    if (!file) {
        cerr << "Erro ao abrir arquivo de tripulação." << endl;
        return;
    }

    int codigo;
    cout << "Digite o código do tripulante: ";
    cin >> codigo;

    Tripulacao tripulante;
    bool encontrado = false;

    while (file.read(reinterpret_cast<char*>(&tripulante), sizeof(Tripulacao))) {
        if (tripulante.codigo == codigo) {
            encontrado = true;
            cout << "\n=== Tripulante Encontrado ===\n";
            cout << "Código: " << tripulante.codigo << endl;
            cout << "Nome: " << tripulante.nome << endl;
            cout << "Telefone: " << tripulante.telefone << endl;
            cout << "Cargo: " << tripulante.cargo << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Tripulante não encontrado." << endl;
    }

    file.close();
}

// Função para listar voos associados a um passageiro
void listarVoosPassageiro() {
    ifstream reservasFile("reservas.dat", ios::binary);
    if (!reservasFile) {
        cerr << "Erro ao abrir arquivo de reservas." << endl;
        return;
    }

    int codigoPassageiro;
    cout << "Digite o código do passageiro: ";
    cin >> codigoPassageiro;

    Reserva reserva;
    bool encontrado = false;

    cout << "\n=== Voos do Passageiro ===\n";
    while (reservasFile.read(reinterpret_cast<char*>(&reserva), sizeof(Reserva))) {
        if (reserva.codigoPassageiro == codigoPassageiro) {
            cout << "Código do Voo: " << reserva.codigoVoo << endl;
            cout << "Número do Assento: " << reserva.numeroAssento << endl;
            cout << "---------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Nenhum voo associado ao passageiro." << endl;
    }

    reservasFile.close();
}
