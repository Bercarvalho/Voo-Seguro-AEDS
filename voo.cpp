#include "voo.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Função para cadastrar um voo
void cadastrarVoo() {
    Voo voo;
    ofstream file("voos.dat", ios::binary | ios::app); // Abre arquivo para adicionar
    if (!file) {
        cerr << "Erro ao abrir arquivo!" << endl;
        return;
    }

    cout << "Digite o código do voo: ";
    cin >> voo.codigo;

    cin.ignore();
    cout << "Digite a data do voo (dd/mm/aaaa): ";
    getline(cin, voo.data);

    cout << "Digite a hora do voo (hh:mm): ";
    getline(cin, voo.hora);

    cout << "Digite a origem do voo: ";
    getline(cin, voo.origem);

    cout << "Digite o destino do voo: ";
    getline(cin, voo.destino);

    cout << "Digite o código do avião: ";
    cin >> voo.codigoAviao;

    // Adicionando tripulação
    int codigoTripulante;
    cout << "Digite os códigos da tripulação (piloto, copiloto, comissários). Digite -1 para encerrar: ";
    while (true) {
        cin >> codigoTripulante;
        if (codigoTripulante == -1) break;
        voo.tripulacao.push_back(codigoTripulante);
    }

    cout << "Digite a tarifa do voo: ";
    cin >> voo.tarifa;

    // Validando status do voo
    if (voo.tripulacao.size() >= 2) { // Pelo menos piloto e copiloto
        voo.ativo = true;
    } else {
        voo.ativo = false;
        cout << "A tripulação é insuficiente. O voo será marcado como inativo." << endl;
    }

    // Salvando o voo no arquivo
    file.write(reinterpret_cast<char*>(&voo), sizeof(Voo));
    cout << "Voo cadastrado com sucesso!" << endl;
    file.close();
}

// Função para listar todos os voos
void listarVoos() {
    ifstream file("voos.dat", ios::binary); // Abre arquivo para leitura
    if (!file) {
        cout << "Nenhum voo cadastrado." << endl;
        return;
    }

    Voo voo;
    cout << "\n=== Lista de Voos ===\n";
    while (file.read(reinterpret_cast<char*>(&voo), sizeof(Voo)))
