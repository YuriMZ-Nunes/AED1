/*
1. Escreva um trecho de codigo para fazer a criacao dos novos tipos de dados conforme
solicitado abaixo:
• Horario: composto de hora, minutos e segundos.
• Data: composto de dia, mes e ano.
• Compromisso: composto de uma data, horario e texto que descreve o compromisso.

*/

#include <stdio.h>

typedef struct{
	int hora, minutos, segundos;
}horario;

typedef struct{
	int dia, mes, ano;
}data;

typedef struct{
	data dataCompromisso;
	horario horaCompromisso;
	char desctricao[100];
}compromisso;

int main()
{
	
}