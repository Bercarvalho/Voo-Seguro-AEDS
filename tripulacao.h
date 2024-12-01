
#ifndef TRIPULACAO_H
#define TRIPULACAO_H

// Estrutura para representar um tripulante
struct Tripulacao {
    int codigo;       // Código único do tripulante
    char nome[50];    // Nome do tripulante
    char telefone[15]; // Telefone com 11 dígitos
    char cargo[15];   // Cargo do tripulante ("piloto", "copiloto", "comissario")
};

// Declarações das funções do módulo tripulação

/**
 * Função para cadastrar um novo tripulante no sistema.
 * Realiza validação de cargo e salva os dados em um arquivo binário.
 */
void cadastrarTripulacao();

/**
 * Função para listar todos os tripulantes cadastrados no sistema.
 * Lê os registros do arquivo binário e exibe no console.
 */
void listarTripulantes();

/**
 * Função para limpar todos os registros de tripulantes.
 * Exclui permanentemente os dados do arquivo binário.
 */
void limparTodosRegistros();

/**
 * Função para remover um tripulante específico do sistema.
 * Remove o registro com base no código fornecido, preservando os demais registros.
 */
void removerTripulanteEspecifico();

#endif // TRIPULACAO_H
