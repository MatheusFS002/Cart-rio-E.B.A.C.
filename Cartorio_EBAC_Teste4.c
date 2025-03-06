#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de memória
#include <locale.h> //bibilioteca de alocações de texto por região
#include <string.h> //biblioteca das strings

int registro() //Função para cadastrar os usuarios no sistema
{
	printf("RRR	Coloque as informações para registrar um nome	RRR\n\n");
	
	//Inicio da Criação de variaveis
	char arquivo[20];
	char nome[25];
	char sobrenome [50];
	char cpf[12];
	char profissao[50];
	//Fim da criação de variaveis
	
	printf("Informe seu CPF:\n"); //Coletando informação do usuario
	scanf("%s", cpf); //%s para lembrar a string/Armazenar a informação que o usuario passou
	
	strcpy(arquivo, cpf); //Responsavel por copiar as informações da string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); //abrir arquivo e escrever(write)
	fprintf(file, cpf); // Salvar o arquivo criado
	fclose(file); //Fechar o arquivo
	
	//Inicio
	file=fopen(arquivo,"a");
	fprintf(file,", ");
	fclose(file);
	//Fim, utilizado para criar um espaço entre uma informação e outra que armazenamos no arquivo
	
	printf("Informe o seu nome:\n");
	scanf("%s", nome);
	
	file=fopen(arquivo, "a"); //Abrir o arquivo e adicionar/alterar uma informação nele (add/alter)
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
	
	printf("Por favor informe sua profissão, caso não possua digite N/A:\n");
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
		printf("Nenhum arquivo localizado com essas informações.\n");
	}
	
	while(fgets(conteudo, 199, file) != NULL)
	{
		printf("\n Localizado as seguintes informações para o CPF informado:\n\n");
		printf("%s", conteudo);
		printf ("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int excluir()
{
	char cpf[300];
	
	printf("Informe o CPF do usúario a ser excluido:");
	scanf("%s", cpf);
	
	remove( cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usúario excluido do sistema!\n");
		system("pause");
	}
}

int teste_main()
{
	printf("!!!	Este é um teste de inserção de main, concluido, não é uma opção valida.	!!!\n\n");
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
	
	
	printf("###  Cartório da E.B.A.C. ###\n\n"); //inicio do menu
	printf("Escolha a opção que deseja consultar:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Gerenciar nomes\n");
	printf("\t3 - Excluir nomes\n"); 
	printf("\t4 - Sair do sistema\n\n"); //fim do menu
	printf("Software desenvolvido e testado por PromeTheus\n\n");
	printf("Opção: ");
	
	scanf("%d", &opcao); //armazenando a escolha do usuario
	
	system("cls"); //limpar a tela
	
	switch(opcao) //inicio da seleção do menu
	{
	case 1:
	registro(); //chamar essa função 
	break;
	
	case 2:
	consulta(); //chamar essa função
	break;
	
	case 3:
	excluir(); //chamar essa função
	break;
	 
	case 4:
	printf("Fechando o programa, obrigado por utilizar o Cartorio E.B.A.C.!\n\n");
	return 0;
	 
	case 12:
	printf("!!!	Teste de inserção de case, está não é uma opção valida.	!!!\n\n");
	system("pause");
	break;
	
	case 20:
	teste_main();
	
	default:
	printf("#####Opção não dispoinivel#####\n\n");
	system("pause");
	break;  
} //fim da seleção
}
}
