#include <stdio.h>
#include <string.h>
void incluirElemento(int *codigo, char nomeProduto[][50], double *valorProduto, int cont);
void imprimirElementos(int *codigo, char nomeProduto[][50], double *valorProduto, int i);
void pesquisaCodigo(int *codigo, int i, int pesquisaCod, char nomeProduto[][50], double *valorProduto);
void alterarElementos(int *codigo, int i, int pesquisaCod, char nomeProduto[][50], double *valorProduto);
int ordenarCodigo(int *codigo, char nomeProduto[][50], double *valorProduto, int cont);
int main(){
	int codigo[5],backupCodigo[5], i,j, pesquisaCod,opcao,resp,cont=0;
	char nomeProduto[5][50],backupNome[5][50];
	double valorProduto[5], backupValor[5];
	do{
	printf("----------------------------------------------------\n");
	printf(" MENU DE OPCOES!\n");
	printf("----------------------------------------------------\n");
	printf(" 1- Incluir Produto\n 2- Listar Produtos Cadastrados\n 3- Pesquisar Produto pelo Codigo\n 4- Alterar um item pelo codigo\n 5- Fazer backup dos vetores\n 6- Restaurar elemento do backup, pelo codigo\n 7- Excluir um elemento\n 8- Ordenar por codigo\n 0- Encerrar o Programa\n");
    printf("----------------------------------------------------\n");
    printf("Escolha a Opcao: ");
	scanf("%d", &opcao);
	fflush(stdin);
    switch(opcao){
    	case 1:
    		do{
				incluirElemento(codigo,nomeProduto,valorProduto,cont);
				printf("Deseja incluir mais algum elemento? 1 = Sim! ou 2 = Nao! ");
	            scanf("%d",&resp);
	            fflush(stdin);
	            cont++;
    		}while(resp==1 and resp!=2);
    	break;
    	case 2:
    	printf("----------------------------------------------------\n");
		printf("LISTA DOS ELEMENTOS CADASTRADOS\n");
		printf("----------------------------------------------------\n");
			for(i=0;i<cont;i++){
				imprimirElementos(codigo,nomeProduto,valorProduto,i);
			}
    	break;
    	case 3:
    		printf("Digite o codigo do produto que deseja pesquisar: ");
			scanf("%d", &pesquisaCod);
			fflush(stdin);
				for(i=0;i<cont;i++){
					pesquisaCodigo(codigo,i,pesquisaCod,nomeProduto,valorProduto);
				}
    	break;
    	case 4:
    		printf("Digite o codigo do produto que deseja alterar: ");
			scanf("%d", &pesquisaCod);
			fflush(stdin);
			for(i=0;i<cont;i++){
				alterarElementos(codigo,i,pesquisaCod,nomeProduto,valorProduto);
			}
    	break;
    	case 5:
			for(i=0;i<cont;i++){
    			backupCodigo[i]=codigo[i];
    			strcpy(backupNome[i],nomeProduto[i]);
    			backupValor[i]=valorProduto[i];
			}
    	break;
    	case 6:
    		printf("Digite o codigo do produto que deseja recuperar: ");
			scanf("%d", &pesquisaCod);
			fflush(stdin);
			for(i=0;i<cont;i++){
				if(backupCodigo[i]==pesquisaCod){
					codigo[i]=backupCodigo[i];
					strcpy(nomeProduto[i],backupNome[i]);
					valorProduto[i]=backupValor[i];
					}
			}
    	break;
    	case 7:
    		printf("Digite o codigo do produto que deseja excluir: ");
			scanf("%d", &pesquisaCod);
			fflush(stdin);
			for(i=0;i<cont;i++){
				if(pesquisaCod==codigo[i]){
					for(j=i;j<cont;j++){
						codigo[j]=codigo[j+1];
						strcpy(nomeProduto[j],nomeProduto[j+1]);
						valorProduto[j]=valorProduto[j+1];
					}
				}
			}
			cont--;
    	break;
    	case 8:
    		if(ordenarCodigo(codigo,nomeProduto,valorProduto,cont)==0){
    			printf("Ordenacao Concluida!\n");
			}
    	break;
    	case 0: return 0;
	}
	printf("Deseja escolher mais alguma opcao? 1 = Sim! ");
	scanf("%d",&resp);
}while(resp==1);
}
void incluirElemento(int *codigo, char nomeProduto[][50], double *valorProduto, int cont){
	    printf("----------------------------------------\n");
		printf(" CADASTRO DE PRODUTO\n");
		printf("----------------------------------------\n");
		printf(" Digite o codigo do produto: ");
		scanf("%d", &codigo[cont]);
		fflush(stdin);
		printf(" Nome do produto: ");
		scanf("%s", &nomeProduto[cont]);
		fflush(stdin);
		printf(" Valor do produto: ");
		scanf("%lf", &valorProduto[cont]);
		fflush(stdin);
		printf("----------------------------------------\n");
}
void imprimirElementos(int *codigo, char nomeProduto[][50], double *valorProduto, int i){
	printf("Cod.Produto: %d Nome: %s Valor: %.2lf\n", codigo[i],nomeProduto[i],valorProduto[i]);
	printf("----------------------------------------------------\n");
}
void pesquisaCodigo(int *codigo, int i, int pesquisaCod, char nomeProduto[][50], double *valorProduto){
	if(codigo[i]==pesquisaCod){
		printf("----------------------------------------------------\n");
		printf("PRODUTO ENCONTRADO!\n");
		printf("----------------------------------------------------\n");
		printf("Cod.Produto: %d Nome: %s Valor: %.2lf\n", codigo[i],nomeProduto[i],valorProduto[i]);
	    printf("----------------------------------------------------\n");
	}
}
void alterarElementos(int *codigo, int i, int pesquisaCod, char nomeProduto[][50], double *valorProduto){
	int opcao;
	if(pesquisaCod==codigo[i]){
		printf("----------------------------------------------------\n");
		printf("Deseja alterar: \n1- Nome Produto\n2- Valor\n3- Ambos\n");
		printf("----------------------------------------------------\n");
			scanf("%d", &opcao);
			fflush(stdin);
			switch (opcao){
				case 1: printf("Digite o novo nome do Produto: \n");
						scanf("%s", &nomeProduto[i]);
						fflush(stdin);
						break;
				case 2: printf("Digite o novo valor:\n");
						scanf("%lf", &valorProduto[i]);
						fflush(stdin);
						break;
				case 3: printf("Digite o novo nome do Produto: \n");
						scanf("%s", &nomeProduto[i]);
						fflush(stdin);
						printf("Digite o novo valor:\n");
						scanf("%lf", &valorProduto[i]);
						fflush(stdin);
						break;
				default: printf("Código inválido!\n");
			}
	}
}
int ordenarCodigo(int *codigo, char nomeProduto[][50], double *valorProduto, int cont){
	int i, j, trocaCodigo;
	double trocaValor;
	char trocaNome[50];
		for (i=0;i<cont;i++){
			for (j=i+1;j<cont;j++){
				if (codigo[i]>codigo[j]){
					trocaCodigo = codigo[i];
					codigo[i] = codigo[j];
					codigo[j] = trocaCodigo;
					
					trocaValor = valorProduto[i];
					valorProduto[i] = valorProduto[j];
					valorProduto[j] = trocaValor;
					
					strcpy(trocaNome,nomeProduto[i]);
					strcpy(nomeProduto[i],nomeProduto[j]);
					strcpy(nomeProduto[j],trocaNome);
				}
			}
		}
return 0;
}
