#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de mem�ria
#include <locale.h> //bibilioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca das strings

int registro() //Fun��o para cadastrar os usuarios no sistema
{
	printf("RRR	Coloque as informa��es para registrar um nome	RRR\n\n");
	
	//Inicio da Cria��o de variaveis
	char arquivo[20];
	char nome[25];
	char sobrenome [50];
	char cpf[12];
	char profissao[50];
	//Fim da cria��o de variaveis
	
	printf("Informe seu CPF:\n"); //Coletando informa��o do usuario
	scanf("%s", cpf); //%s para lembrar a string/Armazenar a informa��o que o usuario passou
	
	strcpy(arquivo, cpf); //Responsavel por copiar as informa��es da string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); //abrir arquivo e escrever(write)
	fprintf(file, cpf); // Salvar o arquivo criado
	fclose(file); //Fechar o arquivo
	
	//Inicio
	file=fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	//Fim, utilizado para criar um espa�o entre uma informa��o e outra que armazenamos no arquivo
	
	printf("Informe o seu nome:\n");
	scanf("%s", nome);
	
	file=fopen(arquivo, "a"); //Abrir o arquivo e adicionar/alterar uma informa��o nele (add/alter)
	fprintf(file, nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file," ");
	fclose(file);
	
	printf("Informe o seu sobrenome e ultimo nome:\n");
	scanf("%s", sobrenome);
	
	file=fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Por favor informe sua profiss�o, caso n�o possua digite N/A:\n");
	scanf("%s", profissao);
	
	file=fopen(arquivo, "a");
	fprintf(file, profissao);
	fclose(file);
	
	printf("\nCadastrado com sucesso! Retornando ao menu...\n");
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("CCC	Para consultar os nomes registrados no sistema:	CCC\n\n");
	
	char cpf[12];
	char conteudo[199];
	
	printf("Informe o CPF:");
	scanf("%s", cpf);
	
	FILE *file;
	file=fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Nenhum arquivo localizado com essas informa��es.\n");
	}
	
	while(fgets(conteudo, 199, file) != NULL)
	{
		printf("\n Localizado as seguintes informa��es para o CPF informado:\n\n");
		printf("%s", conteudo);
		printf ("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int excluir()
{
	char cpf[300];
	
	printf("Informe o CPF do us�ario a ser excluido:");
	scanf("%s", cpf);
	
	remove( cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Us�ario excluido do sistema!\n");
		system("pause");
	}
}

int teste_main()
{
	printf("!!!	Este � um teste de inser��o de main, concluido, n�o � uma op��o valida.	!!!\n\n");
	system("pause");
}

int main()
{
	
	int opcao=0; //Definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{	
	
	system ("cls"); //limpar a tela
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
	printf("###  Cart�rio da E.B.A.C. ###\n\n"); //inicio do menu
	printf("Escolha a op��o que deseja consultar:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Gerenciar nomes\n");
	printf("\t3 - Excluir nomes\n"); 
	printf("\t4 - Sair do sistema\n\n"); //fim do menu
	printf("Software desenvolvido e testado por PromeTheus\n\n");
	printf("Op��o: ");
	
	scanf("%d", &opcao); //armazenando a escolha do usuario
	
	system("cls"); //limpar a tela
	
	switch(opcao) //inicio da sele��o do menu
	{
	case 1:
	registro(); //chamar essa fun��o 
	break;
	
	case 2:
	consulta(); //chamar essa fun��o
	break;
	
	case 3:
	excluir(); //chamar essa fun��o
	break;
	 
	case 4:
	printf("Fechando o programa, obrigado por utilizar o Cartorio E.B.A.C.!\n\n");
	return 0;
	 
	case 12:
	printf("!!!	Teste de inser��o de case, est� n�o � uma op��o valida.	!!!\n\n");
	system("pause");
	break;
	
	case 20:
	teste_main();
	
	default:
	printf("#####Op��o n�o dispoinivel#####\n\n");
	system("pause");
	break;  
} //fim da sele��o
}
}
