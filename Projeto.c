#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em men�ria
#include <locale.h> //biblioteca de aloca��o de texo por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar o usu�rio no sistema
{
	//inicio cria��o das vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informa��es do usur�rio
	scanf("%s", cpf); // %s referente a strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores da string
	
	FILE *file; // cria o arquivo file no banco de dados (computador)
	file = fopen(arquivo, "w"); //sempre que usar o "w", � para criar o arquivo, depois vai atualizar com o "a"
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //colocar a v�rgula, para separar as informa��es 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //guardar na mem�ria (s=string)
	
	file = fopen(arquivo, "a"); //"a" � para atualizar o arquivo, abrir o arquivo
	fprintf(file,nome); //atualizar informa��es 
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //colocar a biblioteca de acentos, pois uma fun��o n�o enxerga a outra 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf)
	
	;FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //se o arquivo cpf for nulo
	{
		printf("N�o foi poss�vel localizar! \n");
	}
		
	//fun��o para salvar o arquivo dentro, quando quer fazer uma a��o at� ela acabar, usa while (la�o de repeti��o)
	while(fgets(conteudo, 200, file) != NULL) //enquanto fgets (buscar no arquivo) estiver escrevendo na string conte�do, at� 200 valores que est�o dentro do arquivo, enquanto for diferente de nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); 
		printf("%s", conteudo); //salvar o conte�do da vari�vel
		printf("\n\n"); 
	}
	system("pause");
}

int deletar()
{
	char cpf[40]; //criando a vari�vel cpf
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf); //escanear a string cpf, e salvar no arquivo cpf
	
	remove(cpf); //remover o usu�rio
	
	;FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema");
		system("pause"); 
	}
	
}

int main()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cart�rio da EBAC ###\n\n");
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n ");
		printf("\t2 - Consultar nomes\n ");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //Fim do menu
		
		scanf("%d",&opcao); //Armazenando escolha do usu�rio
		
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //inicio das func�es 
		{
			case 1: //chamada de func�es 
			registro();
			break;
			
			case 2: 
			consulta();
			break; 
			
			case 3:
			deletar();
			break; 
		
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break; //Fim da sele��o
		}
	}
}
