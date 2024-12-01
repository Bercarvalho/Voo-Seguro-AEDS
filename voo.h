#ifndef VOO_H
#define VOO_H

#include <string>
#include <vector>

// Estrutura para representar um voo
struct Voo {
    int codigo;                 // Código único do voo
    std::string data;           // Data do voo (dd/mm/aaaa)
    std::string hora;           // Hora do voo (hh:mm)
    std::string origem;         // Origem do voo
    std::string destino;        // Destino do voo
    int codigoAviao;            // Código do avião
    std::vector<int> tripulacao; // Códigos da tripulação (piloto, copiloto, comissários)
    float tarifa;               // Tarifa do voo
    bool ativo;                 // Status do voo (ativo/inativo)
};

// Declarações das funções do módulo voos

/**
 * Função para cadastrar um novo voo.
 * Valida tripulação e salva os dados no arquivo binário.
 */
void cadastrarVoo();

/**
 * Função para listar todos os voos cadastrados.
 * Lê os registros do arquivo binário e exibe no console.
 */
void listarVoos();

/**
 * Função para ativar ou inativar um voo.
 * Atualiza o status do voo com base na tripulação mínima.
 */
void atualizarStatusVoo();

#endif // VOO_H
