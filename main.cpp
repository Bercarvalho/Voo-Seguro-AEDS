#include <iostream>
#include "tripulacao.h"
#include "passageiro.h"
#include "voo.h"
#include "reserva.h"
#include "pesquisa.h"

using namespace std;

void exibirMenu() {
    cout << "\n=== Sistema de Gerenciamento de Companhia Aérea ===\n";
    cout << "1. Gerenciar Tripulação\n";
    cout << "2. Gerenciar Passageiros\n";
    cout << "3. Gerenciar Voos\n";
    cout << "4. Gerenciar Reservas\n";
    cout << "5. Pesquisar Dados\n";
    cout << "6. Sair\n";
    cout << "Escolha uma opção: ";
}

void menuTripulacao() {
    int opcao;
    do {
        cout << "\n=== Gerenciamento de Tripulação ===\n";
        cout << "1. Cadastrar Tripulante\n";
        cout << "2. Listar Tripulantes\n";
        cout << "3. Remover Tripulante\n";
        cout << "4. Limpar Todos os Registros\n";
        cout << "5. Voltar ao Menu Principal\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarTripulacao();
                break;
            case 2:
                listarTripulantes();
                break;
            case 3:
                removerTripulanteEspecifico();
                break;
            case 4:
                limparTodosRegistros();
                break;
            case 5:
                cout << "Retornando ao menu principal...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 5);
}

void menuPassageiro() {
    int opcao;
    do {
        cout << "\n=== Gerenciamento de Passageiros ===\n";
        cout << "1. Cadastrar Passageiro\n";
        cout << "2. Listar Passageiros\n";
        cout << "3. Associar Fidelidade\n";
        cout << "4. Atualizar Pontos de Fidelidade\n";
        cout << "5. Listar Passageiros com Fidelidade\n";
        cout << "6. Voltar ao Menu Principal\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarPassageiro();
                break;
            case 2:
                listarPassageiros();
                break;
            case 3:
                associarFidelidade();
                break;
            case 4:
                atualizarFidelidade();
                break;
            case 5:
                listarFidelidade();
                break;
            case 6:
                cout << "Retornando ao menu principal...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 6);
}

void menuVoos() {
    int opcao;
    do {
        cout << "\n=== Gerenciamento de Voos ===\n";
        cout << "1. Cadastrar Voo\n";
        cout << "2. Listar Voos\n";
        cout << "3. Atualizar Status de Voo\n";
        cout << "4. Voltar ao Menu Principal\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarVoo();
                break;
            case 2:
                listarVoos();
                break;
            case 3:
                atualizarStatusVoo();
                break;
            case 4:
                cout << "Retornando ao menu principal...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 4);
}

void menuReservas() {
    int opcao;
    do {
        cout << "\n=== Gerenciamento de Reservas ===\n";
        cout << "1. Criar Reserva\n";
        cout << "2. Listar Reservas\n";
        cout << "3. Liberar Reserva\n";
        cout << "4. Voltar ao Menu Principal\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                criarReserva();
                break;
            case 2:
                listarReservas();
                break;
            case 3:
                liberarReserva();
                break;
            case 4:
                cout << "Retornando ao menu principal...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 4);
}

void menuPesquisa() {
    int opcao;
    do {
        cout << "\n=== Pesquisa de Dados ===\n";
        cout << "1. Buscar Passageiro\n";
        cout << "2. Buscar Tripulante\n";
        cout << "3. Listar Voos de um Passageiro\n";
        cout << "4. Voltar ao Menu Principal\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                buscarPassageiro();
                break;
            case 2:
                buscarTripulante();
                break;
            case 3:
                listarVoosPassageiro();
                break;
            case 4:
                cout << "Retornando ao menu principal...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 4);
}

int main() {
    int opcao;
    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                menuTripulacao();
                break;
            case 2:
                menuPassageiro();
                break;
            case 3:
                menuVoos();
                break;
            case 4:
                menuReservas();
                break;
            case 5:
                menuPesquisa();
                break;
            case 6:
                cout << "Encerrando o programa. Até logo!\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 6);

    return 0;
}
