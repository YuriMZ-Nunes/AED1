# Yuri de Melo Zorzoli Nunes - Turma M2

# Link do video:
https://drive.google.com/file/d/1Cs1_vix2pDmlV_6qw8WgXw0lZhgkbdwC/view?usp=sharing

------------------------------------------------------------------------------------------

# A regra de código usada foi a do DOOM 3:
https://fabiensanglard.net/fd_proxy/doom3/CodeStyleConventions.pdf

# Exercicio 1 - Turma M2:

Faça um programa que solicita do usuário o tamanho de um vetor. Crie um vetor com esse
tamanho, utilizando memória dinâmica, onde números inteiros serão armazenados. Preencha esse
vetor com números inteiros gerados com a função “int rand()” e imprima o vetor. Em seguida solicite
um número inteiro do usuário. O programa deve procurar esse número dentro do vetor e indicar se
foi encontrado ou não. Caso encontre o número esse deve ser removido do vetor e o vetor deve
encolher. Caso não encontre procure dois números que somados geram o número sendo buscado,
caso encontrado ambos devem ser impressos na tela e removidos do vetor e esse deve encolher.
Todas essas operações devem ser feitas com notação de ponteiros (aritmética de ponteiros)
e não com notação de vetores (vetor[10], por exemplo). 

# Link para o repositório onde esta a atividade:
https://github.com/YuriMZ-Nunes/AED1/tree/master/exeProva

# Link para o repositório onde esta a atividade corrigida:
https://github.com/YuriMZ-Nunes/AED1/tree/master/exeProva-correcao

# O que funciona:
    - A alocação de um vetor de inteiros do tamanho desejado.
    - Inserção de valores inteiros aleatórios dentro do vetor utilizando a função int rand().
    - Impressão do vetor completo.
    - A busca e a remoção do valor digitado pelo usuario, caso esse valor esteja no vetor.
    - Impressão do vetor corretamente após a remoção
    - Realocação do vetor após a remoção de um valor.
    - Verifica corretamente se existe dois numeros que somados resultem no valor digitado pelo usuario.

# O que não funciona:
    - A remoção dos dois valores encontrados que somados resultem no valor digitado pelo usuario.
    - Contem warnigs de variaveis não usadas.
    - Vazamento de memória.

# Lista de testes:

1º teste:
Digite o tamanho do vetor: 6
Digite um numero para a busca: 19169

2º teste:
Digite o tamanho do vetor: 9
Digite um numero para a busca: 26962

3º teste:
Digite o tamanho do vetor: 7
Digite um numero para a busca: 22058

4º teste:
Digite o tamanho do vetor: 8
Digite um numero para a busca: 26541


