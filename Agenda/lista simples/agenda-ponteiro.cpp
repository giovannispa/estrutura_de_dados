#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "funcs-ponteiro.h"

int main() {
	contato *inicio = cria_ponteiro();
	int op=-9;
	do {
		printf("Bem vindo ao sistema de agendamento\n");
		printf("Escolha 1 das opcoes a seguir:\n");
		printf("1- Inserir contatos no fim da agenda\n");
		printf("2- Inserir contatos no inicio da agenda\n");
		printf("3- Imprimir todos os contatos\n");
		printf("4- Imprimir um contato especifico\n");
		printf("5- Remover um contato\n");
		printf("6- Imprimir em ordem inversa\n");
		printf("7- Editar um contato\n");
		printf("8- Sair\n");
		scanf("%d",&op);
		
		switch(op) {
			case 1:
				inserir(inicio);
				break;
			case 2:
				inserir_inicio(inicio);
				break;
			case 3:
				imprimir_todos(inicio);
				break;
			case 4:
				imprimir_especifico(inicio);
				break;
			case 5:
				remover(inicio);
				break;
			case 6:
				imprimir_inverso(inicio);
				break;
			case 7:
				editar(inicio);
				break;
			case 8:
				printf("FIM DO PROGRAMA!!");
				break;
			default: {
				printf("Opcao invalida!!");
				printf("Por favor digite uma opcao valida\n");
				Sleep(1500);
				limpaTela();
				break;
			}
		}	
	} while(op != 8);
	return 0;
	system("pause");
}
