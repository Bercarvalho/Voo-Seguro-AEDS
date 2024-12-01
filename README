# Sistema de Gerenciamento de Voos - Companhia Aérea Voo Seguro

Bem-vindo ao repositório do **Sistema de Gerenciamento de Voos da Voo Seguro**!  
Este projeto visa informatizar a gestão de voos, reservas e tripulação, substituindo os antigos métodos manuais (planilhas e cadernos) por uma solução eficiente e automatizada, desenvolvida em **C++**.

---

## Sobre a Voo Seguro ✈️
A **Voo Seguro** é uma companhia aérea comprometida com a satisfação e fidelização de seus passageiros. Operando em diversos aeroportos no Brasil, sua equipe de tripulação é composta por **pilotos**, **copilotos** e **comissários**.  
Este sistema foi criado para resolver problemas recorrentes, como:
- Reservas duplicadas.
- Falta de controle sobre a disponibilidade de voos e assentos.
- Gestão ineficaz de tripulação.

---

## Funcionalidades do Sistema 🛠️
O sistema permite gerenciar os seguintes aspectos:

### 1. Cadastro de Passageiros
- Informações cadastradas: 
  - **Código** (gerado automaticamente ou fornecido).
  - **Nome**, **endereço**, **telefone**, **fidelidade** (sim/não), e **pontos de fidelidade**.
- Restrições:
  - Não permitir dois passageiros com o mesmo código.

### 2. Cadastro de Tripulação
- Informações cadastradas:
  - **Código** (gerado automaticamente ou fornecido).
  - **Nome**, **telefone**, e **cargo** (piloto, copiloto, comissário).
- Restrições:
  - Cada membro deve possuir um cargo específico.
  - Não permitir dois membros com o mesmo código.

### 3. Cadastro de Voos
- Informações cadastradas:
  - **Código do voo**, **data**, **hora**, **origem**, **destino**, **tarifa**, **tripulação** e **avião**.
- Regras:
  - Um voo só pode ser marcado como ativo se houver **ao menos um piloto e um copiloto**.

### 4. Cadastro de Assentos
- Permite cadastrar assentos para cada voo, indicando seu número e status (**ocupado** ou **livre**).

### 5. Gerenciamento de Reservas
- Realizar reservas de assentos:
  - Garantir que o passageiro e o voo estejam previamente cadastrados.
  - Somente voos com **status ativo** e **assentos disponíveis** podem receber reservas.
  - Evitar reservas duplicadas para o mesmo assento.
- Cancelar reservas:
  - Liberar o assento e atualizar seu status.
  - Calcular o valor total pago, se necessário, de acordo com a tarifa do voo.

### 6. Pesquisa
- Busca de passageiros e tripulantes pelo **nome** ou **código**.
- Listagem de todos os voos de um passageiro específico.

### 7. Programa de Fidelidade
- Cada voo concede **10 pontos de fidelidade** ao passageiro.
- Acúmulo de pontos ao longo de múltiplos voos.

---

## Estrutura do Projeto 📂
O sistema foi desenvolvido em **C++** utilizando boas práticas de programação.  

### Diretórios Principais:
- **src/**: Código-fonte do sistema.
- **include/**: Arquivos de cabeçalho.
- **docs/**: Documentação adicional.
- **tests/**: Scripts de teste.

---

## Como Executar 🚀
1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/voo-seguro.git
        
