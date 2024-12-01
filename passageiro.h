
#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string>

using namespace std;
// Estrutura para representar um passageiro
struct Passageiro {
    int codigo;            // Código único do passageiro
    string nome;      // Nome do passageiro
    string endereco;  // Endereço do passageiro
    string telefone;  // Telefone do passageiro
    bool fidelidade;       // Indica se o passageiro está no programa de fidelidade
    int pontosFidelidade;  // Pontos acumulados de fidelidade
};

// Declarações das funções do módulo passageiro

/**
 * Função para cadastrar um novo passageiro.
 * Salva os dados no arquivo binário e valida código único.
 */
void cadastrarPassageiro();

/**
 * Função para listar todos os passageiros cadastrados.
 * Lê os registros do arquivo binário e exibe no console.
 */
void listarPassageiros();

/**
 * Função para associar fidelidade a um passageiro.
 * Atualiza o status de fidelidade no arquivo binário.
 */
void associarFidelidade();

/**
 * Função para atualizar pontos de fidelidade de um passageiro.
 * Atualiza os pontos acumulados no arquivo binário.
 */
void atualizarFidelidade();

/**
 * Função para exibir passageiros no programa de fidelidade.
 * Filtra e lista passageiros com fidelidade ativa.
 */
void listarFidelidade();

#endif // PASSAGEIRO_H
