struct agenda {
	char nome[40];
	int  idade;
	char email[40];
	char telefone[15];
	struct agenda *prox;
};
typedef struct agenda contato;

void load(){
	
    char ascii = 178;
    printf("\n");
    
    for(int i = 0;i<50;i++){
        printf("%c%",ascii);
        Sleep(1);
    }
}

void limpaTela() {
	system("cls");
}


contato *cria_ponteiro() {
	contato *p=(contato*)malloc(sizeof(contato));
	
	if(!p) {
		printf("Erro!");
	}
	else {
		p->nome[0]=NULL;
		p->idade=NULL;
		p->email[0]=NULL;
		p->telefone[0]=NULL;
		p->prox=NULL;
	}
	return p;
}

bool eh_vazia(contato *inicio){
	if(inicio->prox == NULL) {
		return true;
	} else {
		return false;
	}
}

void inserir(contato *inicio) {
	
	contato *nova = cria_ponteiro();
	
	printf("Informe o nome do contato: ");
	fflush(stdin);
	gets(nova->nome);
	printf("Idade: ");
	scanf("%d",&nova->idade);
	printf("E-mail: ");
	fflush(stdin);
	gets(nova->email);
	printf("Telefone: ");
	fflush(stdin);
	gets(nova->telefone);
	
	if(inicio->prox == NULL) {
		inicio->prox = nova;
	} else {
		contato *temp;
		temp = inicio;
		while(temp->prox != NULL) {
			temp = temp->prox;
		}
		temp->prox = nova;
	}
	
	printf("\nAgurde enquanto cadastramos o contato no sistema!!");
	load();
	limpaTela();
}

void editar(contato *inicio) {
	char editar[40];
	
	printf("Informe o nome do contato para edicao: ");
	fflush(stdin);
	gets(editar);
	
	contato *temp;
	temp = inicio;
	while(temp->prox != NULL) {
		temp = temp->prox;
		if(strcmp(editar, temp->nome) == 0) {
			printf("Informe o nome do contato: ");
			fflush(stdin);
			gets(temp->nome);
			printf("Idade: ");
			scanf("%d",&temp->idade);
			printf("E-mail: ");
			fflush(stdin);
			gets(temp->email);
			printf("Telefone: ");
			fflush(stdin);
			gets(temp->telefone);
		}
	}
}

void inserir_inicio(contato *inicio) {
	
	contato *nova = cria_ponteiro();
	
	printf("Informe o nome do contato: ");
	fflush(stdin);
	gets(nova->nome);
	printf("Idade: ");
	scanf("%d",&nova->idade);
	printf("E-mail: ");
	fflush(stdin);
	gets(nova->email);
	printf("Telefone: ");
	fflush(stdin);
	gets(nova->telefone);
	
	nova->prox = inicio->prox;
	inicio->prox = nova;
	
	printf("\nAgurde enquanto cadastramos o contato no sistema!!");
	load();
	limpaTela();
}

void imprimir_todos(contato *inicio) {
	if(!eh_vazia(inicio)) {
		contato *temp;
		temp = inicio;
		while(temp->prox != NULL) {
			temp = temp->prox;
			printf("###################################\n");
			printf("Nome do contato: %s\n",temp->nome);
			printf("Idade: %d\n",temp->idade);
			printf("E-mail: %s\n",temp->email);
			printf("Telefone: %s\n",temp->telefone);
			printf("###################################\n");
		}
	} else {
		printf("A agenda esta vazia!!\n");
	}
}

void imprimir_especifico(contato *inicio) {
	if(!eh_vazia(inicio)) {
		int consultaInt;
		char consultaChar[40];
		int op=-9;
		printf("Informe o metodo de busca na agenda:\n");
		printf("1- Nome\n");
		printf("2- Idade\n");
		printf("3- E-mail\n");
		printf("4- Telefone\n");
		printf("5- Sair da funcao\n");
		scanf("%d",&op);
		
		switch(op) {
			case 1: {
		
					printf("Digite o nome para consulta: ");
					fflush(stdin);
					gets(consultaChar);
			
					contato *temp;
					temp = inicio;
					while(temp->prox != NULL) {
						temp = temp->prox;
						if(strcmp(consultaChar, temp->nome) == 0) {
							printf("###################################\n");
							printf("Nome do contato: %s\n",temp->nome);
							printf("Idade: %d\n",temp->idade);
							printf("E-mail: %s\n",temp->email);
							printf("Telefone: %s\n",temp->telefone);
							printf("###################################\n");
						}
					}
					break;
				}
			case 2: {
				
					printf("Digite a idade para consulta: ");
					scanf("%d",&consultaInt);
					
					contato *temp;
					temp = inicio;
					while(temp->prox != NULL) {
						temp = temp->prox;
						if(consultaInt == temp->idade) {
							printf("###################################\n");
							printf("Nome do contato: %s\n",temp->nome);
							printf("Idade: %d\n",temp->idade);
							printf("E-mail: %s\n",temp->email);
							printf("Telefone: %s\n",temp->telefone);
							printf("###################################\n");	
						}
					}
					break;
				}
			case 3: {
				
					printf("Digite o e-mail para consulta: ");
					fflush(stdin);
					gets(consultaChar);
					
					contato *temp;
					temp = inicio;
					while(temp->prox != NULL) {
						temp = temp->prox;
						if(strcmp(consultaChar, temp->email) == 0) {
							printf("###################################\n");
							printf("Nome do contato: %s\n",temp->nome);
							printf("Idade: %d\n",temp->idade);
							printf("E-mail: %s\n",temp->email);
							printf("Telefone: %s\n",temp->telefone);
							printf("###################################\n");
						}
					}
					break;
				}
			case 4: {
				
					printf("Digite o telefone para consulta: ");
					fflush(stdin);
					gets(consultaChar);
					
					contato *temp;
					temp = inicio;
					while(temp->prox != NULL) {
						temp = temp->prox;
						if(strcmp(consultaChar, temp->telefone) == 0) {
							printf("###################################\n");
							printf("Nome do contato: %s\n",temp->nome);
							printf("Idade: %d\n",temp->idade);
							printf("E-mail: %s\n",temp->email);
							printf("Telefone: %s\n",temp->telefone);
							printf("###################################\n");
						}
					}
					break;
				}
			case 5:
				printf("Voltando ao menu principal!!");
				Sleep(1500);
				limpaTela();
				break;
			default: {
				printf("Opcao invalida!!");
				printf("Por favor digite uma opcao valida");
				Sleep(1500);
				limpaTela();
				break;
			}
		}
	} else {
		printf("A agenda esta vazia!!\n");
	}
}

void remover(contato *inicio) {
	if(!eh_vazia(inicio)) {
		char removerChar[40];
		int qtdremover = 0;	
		printf("Informe o nome para remocao: ");
		fflush(stdin);
		gets(removerChar);
		
		contato *temp,*aux;
		temp = inicio;
		while(temp != NULL) {
			if(strcmp(removerChar, temp->nome) == 0) {
				qtdremover++;
			}
			temp = temp->prox;
		}
		if(qtdremover == 0) {
			printf("O contato nao esta inserido na agenda");
		} 
		else if(qtdremover == 1) {
			temp = inicio->prox;
			aux = inicio;
			while(aux->prox != NULL) {
				if(strcmp(removerChar, temp->nome) == 0) {
					aux->prox = temp->prox;
					free(temp);
				}
				temp = temp->prox;
				aux = aux->prox;
			}
		}
		else {
			char removerTel[40];
			printf("Foram encontrados os seguintes nomes: \n");
			temp = inicio;
			while(temp->prox != NULL) {
				temp = temp->prox;
				if(strcmp(removerChar, temp->nome) == 0) {
					printf("###################################\n");
					printf("Nome do contato: %s\n",temp->nome);
					printf("Idade: %d\n",temp->idade);
					printf("E-mail: %s\n",temp->email);
					printf("Telefone: %s\n",temp->telefone);
					printf("###################################\n");
				}
			}
			printf("Informe o telefone para a remocao:\n");
			fflush(stdin);
			gets(removerTel);
			temp = inicio->prox;
			aux = inicio;
			while(temp != NULL) {
				if(strcmp(removerTel, temp->telefone) == 0) {
					aux->prox = temp->prox;
					free(temp);
				}
				temp = temp->prox;
				aux = aux->prox;
			}	
		}
	} else {
		printf("A agenda esta vazia!!\n");
	}
}

void imprimir_inverso(contato *inicio) {
	if(!eh_vazia(inicio)) {
		contato *temp,*aux;
		temp = inicio->prox;
		aux = inicio;
		while(temp->prox != NULL) {
			temp = temp->prox;
			printf("###################################\n");
			printf("Nome do contato: %s\n",temp->nome);
			printf("Idade: %d\n",temp->idade);
			printf("E-mail: %s\n",temp->email);
			printf("Telefone: %s\n",temp->telefone);
			printf("###################################\n");
		}
		while(temp != inicio) {
			while(aux->prox != temp) {
				aux = aux->prox;
			}
			printf("###################################\n");
			printf("Nome do contato: %s\n",aux->nome);
			printf("Idade: %d\n",aux->idade);
			printf("E-mail: %s\n",aux->email);
			printf("Telefone: %s\n",aux->telefone);
			printf("###################################\n");
			temp = aux;
			aux = inicio;
		}
	} else {
		printf("A agenda esta vazia!!\n");
	}
}
