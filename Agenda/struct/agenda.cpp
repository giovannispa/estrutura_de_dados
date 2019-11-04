#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "funcs.h"

int main() {
	int op=-9;
	do {
		printf("Bem vindo ao sistema de agendamento\n");
		printf("Escolha 1 das opcoes a seguir:\n");
		printf("1- Inserir contatos\n");
		printf("2- Imprimir todos os contatos\n");
		printf("3- Imprimir um contato especifico\n");
		printf("4- Alterar um contato\n");
		printf("5- Remover um contato\n");
		printf("6- Sair\n");
		scanf("%d",&op);
		
		switch(op) {
			case 1:
				inserir();
				break;
			case 2:
				imprimir_todos();
				break;
			case 3:
				imprimir_especifico();
				break;
			case 4:
				alterar();
				break;
			case 5:
				remover();
				break;
			case 6:
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
	} while(op != 6);
	return 0;
	system("pause");
}
