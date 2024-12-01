#ifndef PESQUISA_H
#define PESQUISA_H

#include <string>

/**
 * Função para buscar passageiros pelo nome ou código.
 * Exibe as informações do passageiro caso encontrado.
 */
void buscarPassageiro();

/**
 * Função para buscar membros da tripulação pelo nome ou código.
 * Exibe as informações do tripulante caso encontrado.
 */
void buscarTripulante();

/**
 * Função para listar todos os voos associados a um passageiro.
 * Busca por código do passageiro e exibe os voos associados.
 */
void listarVoosPassageiro();

#endif // PESQUISA_H
