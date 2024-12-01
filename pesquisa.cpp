#include "pesquisa.h"
#include "passageiro.h"
#include "tripulacao.h"
#include "voo.h"
#include "reserva.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Função para buscar passageiros
void buscarPassageiro() {
    ifstream file("passageiros.dat", ios::binary); // Abre arquivo de passageiros
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
                break;
            }
        }
    }

    if (encontrado) {
        cout << "\n=== Informações do Passageiro ===\n";
        cout << "Código: " << passageiro.codigo << endl;
        cout << "Nome: " << passageiro.nome << endl;
        cout << "Endereço: " << passageiro.endereco << endl;
        cout << "Telefone: " << passageiro.telefone << endl;
        cout << "Fidelidade: " << (passageiro.fidelidade ? "Sim" : "Não") << endl;
        cout << "Pontos Fidelidade: " << passageiro.pontosFidelidade << endl;
    } else {
        cout << "Passageiro não encontrado." << endl;
    }

    file.close();
}

// Função para buscar tripulantes
void buscarTripulante() {
    ifstream file("tripulacao.dat", ios::binary); // Abre arquivo de tripulação
    if (!file) {
        cerr << "Erro ao abrir arquivo de tripulação." << endl;
        return;
    }

    int codigo;
    string nome;
    cout << "Digite o código do tripulante (ou 0 para buscar por nome): ";
    cin >> codigo;

    Tripulacao tripulante;
    bool encontrado = false;

    if (codigo != 0) {
        while (file.read(reinterpret_cast<char*>(&tripulante), sizeof(Tripulacao))) {
            if (tripulante.codigo == codigo) {
                encontrado = true;
                break;
            }
        }
    } else {
        cout << "Digite o nome do tripulante: ";
        cin.ignore();
        getline(cin, nome);

        while (file.read(reinterpret_cast<char*>(&tripulante), sizeof(Tripulacao))) {
            if (strcmp(tripulante.nome, nome.c_str()) == 0) {
                encontrado = true;
                break;
            }
        }
    }

    if (encontrado) {
        cout << "\n=== Informações do Tripulante ===\n";
        cout << "Código: " << tripulante.codigo << endl;
        cout << "Nome: " << tripulante.nome << endl;
        cout << "Telefone: " << tripulante.telefone << endl;
        cout << "Cargo: " << tripulante.cargo << endl;
    } else {
        cout << "Tripulante não encontrado." << endl;
    }

    file.close();
}

// Função para listar voos associados a um passageiro
void listarVoosPassageiro() {
    ifstream reservasFile("reservas.dat", ios::binary); // Abre arquivo de reservas
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
        cout << "Nenhum voo associado a este passageiro." << endl
