#include<stdio.h>
#include<windows.h>
#include<string.h>
int Menu(){
	int resp;
	printf("O que deseja ver?\n[1] Lista de quartos\t[2] Cadastrar hospede(s)\t[3] Liberar quarto\t[4] Consultar quarto\t[0] Para sair do programa\t\n");
	scanf("%d", &resp);
	printf("\n");
	return resp;
}
void main(){
	SetConsoleOutputCP(CP_UTF8);
    char nomes[30][5][50];
	char situacao[20];
	strcpy(situacao, "Livre");
	int opcao, status[30] = {0};
	int nums[30] = {0};
	do{
		opcao = Menu();
		if(opcao == 1){
			for(int i = 0; i < 30;i++){
				if(status[i] == 0){
					printf("Quarto %d = Livre\n", i+1);
				}
				else{
					printf("Quarto %d = Ocupado\n", i+1);
				}
				}
				printf("\n");
			}
			else if (opcao == 2){
            	printf("Qual quarto será hospedado?\n");
            	int quarto;
            	scanf("%d", &quarto);
            	if(quarto >= 1 && quarto <= 30){
            		if(status[quarto-1] == 0){
            			printf("Quantas pessoas? (máx. 5)\n");
            			int qnt;
            			scanf("%d", &qnt);
            			if(qnt > 0 && qnt <= 5){
            				status[quarto-1] = 1;
            				nums[quarto-1] = qnt;
            				for(int i = 0; i < qnt; i++){
            					printf("Nome do hospede\n");
            					scanf(" %[^\n]", nomes[quarto-1][i]);
							}
							printf("Quarto cadastrado\n\n");
						}
						else{
							printf("Quantidade inválida\n\n");
						}
						}
						else{
							printf("Quarto já está ocupado\n\n");
					}
				}
				else{
					printf("Invalido\n");
				}
        	}
			else if (opcao == 3){
            printf("Qual quarto deseja liberar?\n");
            int quarto;
            scanf("%d", &quarto);
            if(quarto >= 1 && quarto <= 30){
            	if(status[quarto-1] == 1){
            		status[quarto-1] = 0;
            		nums[quarto-1] = 0;
            		printf("Quarto liberado\n\n");
				}
				else{
					printf("O quarto já está livre\n\n");
				}
			}
			else{
				printf("Invalido\n");
			}
        	}
        	else if (opcao == 4){
        		printf("Qual quarto deseja consultar?\n");
        		int quarto;
        		scanf("%d", &quarto);
        		if(quarto >= 1 && quarto <= 30){
        			if(status[quarto-1] == 0){
        				printf("O quarto está livre\n\n");
					}
					else{
						printf("O quarto está ocupado\n");
						printf("Quantidade de hospedes: %d\n", nums[quarto-1]);
						printf("Nome:\n");
						for(int i = 0; i < nums[quarto-1]; i++){
							printf("- %s\n", nomes[quarto-1][i]);
						}
						printf("\n");
					}
				}
			}
			else if (opcao != 0){
            printf("Opcao invalida! Tente novamente.\n\n");
        	}
	}
	while(opcao != 0);
	return 0;
}