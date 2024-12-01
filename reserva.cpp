
#include "reserva.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Função para criar uma reserva
void criarReserva() {
    Reserva reserva;
    fstream file("reservas.dat", ios::binary | ios::in | ios::out | ios::app); // Leitura e escrita
    if (!file) {
        cerr << "Erro ao abrir arquivo!" << endl;
        return;
    }

    cout << "Digite o código do voo: ";
    cin >> reserva.codigoVoo;

    cout << "Digite o número do assento: ";
    cin >> reserva.numeroAssento;

    cout << "Digite o código do passageiro: ";
    cin >> reserva.codigoPassageiro;

    // Validar se o assento já está ocupado
    bool ocupado = false;
    Reserva reservaExistente;
    while (file.read(reinterpret_cast<char*>(&reservaExistente), sizeof(Reserva))) {
        if (reservaExistente.codigoVoo == reserva.codigoVoo &&
            reservaExistente.numeroAssento == reserva.numeroAssento) {
            ocupado = true;
            break;
        }
    }

    if (ocupado) {
        cout << "Erro: Assento já está reservado." << endl;
    } else {
        reserva.ocupado = true;
        file.clear(); // Limpa flags de leitura
        file.seekp(0, ios::end); // Move ponteiro para o final para adicionar nova reserva
        file.write(reinterpret_cast<char*>(&reserva), sizeof(Reserva));
        cout << "Reserva criada com sucesso!" << endl;
    }
    file.close();
}

// Função para listar todas as reservas
void listarReservas() {
    ifstream file("reservas.dat", ios::binary); // Apenas leitura
    if (!file) {
        cerr << "Nenhuma reserva encontrada." << endl;
        return;
    }

    Reserva reserva;
    cout << "\n=== Lista de Reservas ===\n";
    while (file.read(reinterpret_cast<char*>(&reserva), sizeof(Reserva))) {
        cout << "Código do Voo: " << reserva.codigoVoo << endl;
        cout << "Número do Assento: " << reserva.numeroAssento << endl;
        cout << "Código do Passageiro: " << reserva.codigoPassageiro << endl;
        cout << "Status: " << (reserva.ocupado ? "Ocupado" : "Livre") << endl;
        cout << "---------------------------" << endl;
    }
    file.close();
}

// Função para liberar uma reserva existente
void liberarReserva() {
    fstream file("reservas.dat", ios::binary | ios::in | ios::out); // Leitura e escrita
    if (!file) {
        cerr << "Erro ao abrir arquivo!" << endl;
        return;
    }

    int codigoVoo, numeroAssento;
    cout << "Digite o código do voo: ";
    cin >> codigoVoo;
    cout << "Digite o número do assento: ";
    cin >> numeroAssento;

    Reserva reserva;
    bool encontrado = false;

    while (file.read(reinterpret_cast<char*>(&reserva), sizeof(Reserva))) {
        if (reserva.codigoVoo == codigoVoo && reserva.numeroAssento == numeroAssento) {
            reserva.ocupado = false; // Libera o assento
            file.seekp(-sizeof(Reserva), ios::cur); // Volta ponteiro para sobrescrever
            file.write(reinterpret_cast<char*>(&reserva), sizeof(Reserva));
            encontrado = true;
            cout << "Reserva liberada com sucesso!" << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "Reserva não encontrada." << endl;
    }
    file.close();
}
