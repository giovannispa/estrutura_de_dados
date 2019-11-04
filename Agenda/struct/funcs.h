struct agenda {
	char nome[40];
	int  idade;
	char email[40];
	char telefone[15];
};
struct agenda contato[5];

int  i    = 0;
int  cont = 0;
char resp;
FILE *file;

void abreArquivo() {
	file = fopen("agenda.txt","w");
}

void fechaArquivo() {
	fclose(file);
}

void load(){
	
    char ascii = 178;
    printf("\n");
    
    for(int i = 0;i<50;i++){
        printf("%c%",ascii);
        Sleep(150);
    }
}

void limpaTela() {
	system("cls");
}

bool ehVazia() {
	if(cont == 0){
		printf("Nenhum dado pode ser retornado!!\n");
		printf("A agenda esta vazia!!\n");
		Sleep(1000);
		return true;
	} else {
		return false;
	}
}

void inserir() {
	if(cont == 5) {
		printf("Nao e permitido mais de 5 cadastros na agenda!");
		Sleep(500);
		limpaTela();
	} else {
		do {
			printf("Informe o nome do contato: ");
			fflush(stdin);
			gets(contato[i].nome);
			printf("Idade: ");
			scanf("%d",&contato[i].idade);
			printf("E-mail: ");
			fflush(stdin);
			gets(contato[i].email);
			printf("Telefone: ");
			fflush(stdin);
			gets(contato[i].telefone);
			
			abreArquivo();
			fprintf(file,"###################################\n");
			fprintf(file,"Nome do contato: %s\n",contato[i].nome);
			fprintf(file,"Idade: %d\n",contato[i].idade);
			fprintf(file,"E-mail: %s\n",contato[i].email);
			fprintf(file,"Telefone: %s\n",contato[i].telefone);
			fprintf(file,"###################################\n");
			fechaArquivo();
			
			i++;
			cont++;
			
			while(toupper(resp)!='N'){
				printf("Deseja informar outro contato? <S/N>\n");
				resp = getche();
				while(!(toupper(resp)=='S' || toupper(resp)=='N')) {
					printf("\nOpcao invalida!!\n ");
					printf("Por favor informe S ou N:\n ");
					resp = getche();	
				}
			}
			
			printf("\n");
		} while(toupper(resp)=='S' && cont < 5);
		
			printf("\nAgurde enquanto cadastramos o contato no sistema!!");
			load();
			limpaTela();
	}
}

void imprimir_todos() {
	if(!ehVazia()){
		for(i=0; i < cont; i++) {
			printf("###################################\n");
			printf("Nome do contato: %s\n",contato[i].nome);
			printf("Idade: %d\n",contato[i].idade);
			printf("E-mail: %s\n",contato[i].email);
			printf("Telefone: %s\n",contato[i].telefone);
			printf("###################################\n");
	}
	
	printf("\n");
	}
	
}

void imprimir_especifico() {
	if(!ehVazia()){
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
			case 1:
				printf("Digite o nome para consulta: ");
				fflush(stdin);
				gets(consultaChar);
		
				for(i = 0; i < cont; i++) {
					if(strcmp(consultaChar, contato[i].nome) == 0) {
						printf("###################################\n");
						printf("Nome do contato: %s\n",contato[i].nome);
						printf("Idade: %d\n",contato[i].idade);
						printf("E-mail: %s\n",contato[i].email);
						printf("Telefone: %s\n",contato[i].telefone);
						printf("###################################\n");
					}
					printf("\n");
				}
				
				if(i==cont){
					if(strcmp(consultaChar,contato[i].nome)!=0){
						printf("Contano nao existe!\n ");
					}
				}
				break;
			case 2:
				printf("Digite a idade para consulta: ");
				scanf("%d",&consultaInt);
				
				for(i = 0; i < cont; i++) {
					if(consultaInt == contato[i].idade) {
						printf("###################################\n");
						printf("Nome do contato: %s\n",contato[i].nome);
						printf("Idade: %d\n",contato[i].idade);
						printf("E-mail: %s\n",contato[i].email);
						printf("Telefone: %s\n",contato[i].telefone);
						printf("###################################\n");
					}
			
					printf("\n");
				}
				
				if(i==cont){
						if(contato[i].idade != consultaInt){
							printf("\nContano nao existe!\n ");
						}
					}
				break;
			case 3:
				printf("Digite o e-mail para consulta: ");
				fflush(stdin);
				gets(consultaChar);
				
				for(i = 0; i < cont; i++) {
					if(strcmp(consultaChar, contato[i].email) == 0) {
						printf("###################################\n");
						printf("Nome do contato: %s\n",contato[i].nome);
						printf("Idade: %d\n",contato[i].idade);
						printf("E-mail: %s\n",contato[i].email);
						printf("Telefone: %s\n",contato[i].telefone);
						printf("###################################\n");
					}
					
					printf("\n");
				}
				
				if(i==cont){
					if(strcmp(consultaChar,contato[i].email)!=0){
						printf("Contano nao existe!\n ");
					}
				}
				break;
			case 4:
				printf("Digite o telefone para consulta: ");
				fflush(stdin);
				gets(consultaChar);
				
				for(i = 0; i < cont; i++) {
					if(strcmp(consultaChar, contato[i].telefone) == 0) {
						printf("###################################\n");
						printf("Nome do contato: %s\n",contato[i].nome);
						printf("Idade: %d\n",contato[i].idade);
						printf("E-mail: %s\n",contato[i].email);
						printf("Telefone: %s\n",contato[i].telefone);
						printf("###################################\n");
					}
					
					printf("\n");
				}
				
				if(i==cont){
					if(strcmp(consultaChar,contato[i].telefone)!=0){
						printf("Contano nao existe!\n ");
					}
				}
				break;
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
	}
}

void alterar() {
	if(!ehVazia()){
		char alterarChar[40];
		printf("Informe o nome para alteracao: ");
		scanf("%s",&alterarChar);
		
		for(i = 0; i < cont; i++) {
			if(strcmp(alterarChar, contato[i].nome) == 0) {
				printf("Informe o nome do contato: ");
				fflush(stdin);
				gets(contato[i].nome);
				printf("Idade: ");
				scanf("%d",&contato[i].idade);
				printf("E-mail: ");
				fflush(stdin);
				gets(contato[i].email);
				printf("Telefone: ");
				fflush(stdin);
				gets(contato[i].telefone);
				break;
			}
			printf("\n");
		}
	}
}

void remover() {
	int j;
	if(!ehVazia()){
		char removerChar[40];	
		printf("Informe o nome para remocao: ");
		fflush(stdin);
		gets(removerChar);
		
		for(i=0; i < cont; i++) {
			for(j=i; j < cont; j++){
				if(strcmp(removerChar, contato[i].nome) == 0) {
					strcpy(contato[j].nome, contato[j+1].nome );
					contato[j].idade = 0;	
					strcpy(contato[j].email, contato[j+1].email );
					strcpy(contato[j].telefone, contato[j+1].email );		
				}
			}
		}
		cont--;
	}
}
