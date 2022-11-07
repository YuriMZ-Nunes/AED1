# Yuri de Melo Zorzoli Nunes - Turma M2

# Link do video:
https://drive.google.com/file/d/1mkMcjMf0Hn2gCCurky3UiZSFBt1_fD44/view?usp=share_link

------------------------------------------------------------------------------------------

# A regra de código usada foi a do DOOM 3:
https://fabiensanglard.net/fd_proxy/doom3/CodeStyleConventions.pdf

# Exercicio 3 - Turma M2:

Construção de uma árvore binária de busca onde o usuário que decide quando, onde e qual rotação utilizar. 

# Link para o repositório onde esta a atividade feita em sala de aula:
https://github.com/YuriMZ-Nunes/AED1/tree/master/exeProva3

# Link para o repositório onde esta a atividade corrigida:
https://github.com/YuriMZ-Nunes/AED1/tree/master/exeProva3-correcao

# O que funciona pós correção:
    - Inserção de dados na ordem correta segundo as regras da árvore
    - Rotação para ambos os lados em qualquer nó escolhido
    - Remoção do nó escolhido
    - Busca de um nó
    - Nenhum warning e nenhum leak de memória 

# O que foi feito em aula:
    - Inserção de dados na ordem correta segundo as regras da árvore
    - Rotação á esquerda quando havia apenas 3 nós

# Lista de testes:

- 1º teste:
    - Inserir na ordem: 30, 50 e 60
    - Listar
    - Rotação á esquerda no nó 30
    - Listar
    - Inserir na ordem: 55 e 54
    - Listar
    - Rotação á direita no nó 60
    - Listar 
    - Buscar nó 60
    - Excluir nó 60
    - Listar
    - Sair

- 2º teste:
    - Inserir na ordem: 50, 35, 60, 20, 48, 56, 76, 37, 67, 98 e 85;
    - Listar
    - Rotação á esquerda no nó 60
    - Listar
    - Excluir nó 76
    - Listar
    - Rotação á direita no nó 50
    - Listar
    - Sair
