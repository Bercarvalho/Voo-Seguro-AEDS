
#include "tripulacao.h" // Inclui o header da tripulação
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Função para validar cargos permitidos
bool validarCargo(const char *cargo) {
    return strcmp(cargo, "piloto") == 0 ||
           strcmp(cargo, "copiloto") == 0 ||
           strcmp(cargo, "comissario") == 0;
}

// Função para cadastrar um tripulante
void cadastrarTripulacao() {
    Tripulacao tripulante;
    ofstream file("tripulacao.dat", ios::binary | ios::app); // Abre arquivo no modo append
    if (!file) {
        cerr << "Erro ao abrir arquivo!" << endl;
        return;
    }

    cout << "Digite o código do tripulante: ";
    cin >> tripulante.codigo;

    cout << "Digite o nome do tripulante: ";
    cin.ignore();
    cin.getline(tripulante.nome, 50);

    cout << "Digite o telefone do tripulante (11 dígitos): ";
    cin >> tripulante.telefone;

    do {
        cout << "Digite o cargo (piloto, copiloto, comissario): ";
        cin >> tripulante.cargo;
        if (!validarCargo(tripulante.cargo)) {
            cout << "Cargo inválido! Tente novamente." << endl;
        }
    } while (!validarCargo(tripulante.cargo));

    file.write(reinterpret_cast<char *>(&tripulante), sizeof(Tripulacao)); // Grava no arquivo
    cout << "Tripulante cadastrado com sucesso!" << endl;
    file.close();
}

// Função para listar todos os tripulantes
void listarTripulantes() {
    ifstream file("tripulacao.dat", ios::binary); // Abre arquivo no modo leitura
    if (!file) {
        cout << "Nenhum tripulante cadastrado." << endl;
        return;
    }

    Tripulacao tripulante;
    cout << "\n=== Lista de Tripulantes ===\n";
    while (file.read(reinterpret_cast<char *>(&tripulante), sizeof(Tripulacao))) {
        cout << "Código: " << tripulante.codigo << endl;
        cout << "Nome: " << tripulante.nome << endl;
        cout << "Telefone: " << tripulante.telefone << endl;
        cout << "Cargo: " << tripulante.cargo << endl;
        cout << "---------------------------" << endl;
    }
    file.close();
}

// Função para limpar todos os registros
void limparTodosRegistros() {
    ofstream file("tripulacao.dat", ios::binary | ios::trunc); // Apaga o conteúdo do arquivo
    if (!file) {
        cerr << "Erro ao abrir arquivo!" << endl;
        return;
    }
    cout << "Todos os registros foram removidos." << endl;
}

// Função para remover um tripulante específico
void removerTripulanteEspecifico() {
    ifstream file("tripulacao.dat", ios::binary); // Abre arquivo para leitura
    ofstream tempFile("temp.dat", ios::binary);  // Arquivo temporário
    if (!file || !tempFile) {
        cerr << "Erro ao abrir arquivo!" << endl;
        return;
    }

    int codigo;
    bool encontrado = false;
    Tripulacao tripulante;

    cout << "Digite o código do tripulante a ser removido: ";
    cin >> codigo;

    while (file.read(reinterpret_cast<char *>(&tripulante), sizeof(Tripulacao))) {
        if (tripulante.codigo != codigo) {
            tempFile.write(reinterpret_cast<char *>(&tripulante), sizeof(Tripulacao));
        } else {
            encontrado = true;
        }
    }

    file.close();
    tempFile.close();

    remove("tripulacao.dat");        // Remove o arquivo original
    rename("temp.dat", "tripulacao.dat"); // Renomeia o temporário

    if (encontrado) {
        cout << "Tripulante removido com sucesso!" << endl;
    } else {
        cout << "Tripulante não encontrado." << endl;
    }
}
