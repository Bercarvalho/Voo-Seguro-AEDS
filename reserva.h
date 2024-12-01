#ifndef RESERVA_H
#define RESERVA_H

#include <string>

// Estrutura para representar uma reserva
struct Reserva {
    int codigoVoo;       // Código do voo associado à reserva
    int numeroAssento;   // Número do assento reservado
    int codigoPassageiro; // Código do passageiro associado à reserva
    bool ocupado;        // Status do assento (ocupado/livre)
};

// Declarações das funções do módulo reserva

/**
 * Função para criar uma nova reserva.
 * Valida disponibilidade de assento e status do voo.
 */
void criarReserva();

/**
 * Função para listar todas as reservas cadastradas.
 * Lê os registros do arquivo binário e exibe no console.
 */
void listarReservas();

/**
 * Função para liberar um assento de uma reserva existente.
 * Atualiza o status do assento para livre.
 */
void liberarReserva();

#endif // RESERVA_H
