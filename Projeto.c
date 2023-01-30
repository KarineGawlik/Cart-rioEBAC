#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> // biblioteca de alocação de espaço em menória
#include <locale.h> //biblioteca de alocação de texo por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar o usuário no sistema
{
	//inicio criação das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informações do usurário
	scanf("%s", cpf); // %s referente a strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores da string
	
	FILE *file; // cria o arquivo file no banco de dados (computador)
	file = fopen(arquivo, "w"); //sempre que usar o "w", é para criar o arquivo, depois vai atualizar com o "a"
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //colocar a vírgula, para separar as informações 
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); //guardar na memória (s=string)
	
	file = fopen(arquivo, "a"); //"a" é para atualizar o arquivo, abrir o arquivo
	fprintf(file,nome); //atualizar informações 
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
	setlocale(LC_ALL, "Portuguese"); //colocar a biblioteca de acentos, pois uma função não enxerga a outra 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf)
	
	;FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //se o arquivo cpf for nulo
	{
		printf("Não foi possível localizar! \n");
	}
		
	//função para salvar o arquivo dentro, quando quer fazer uma ação até ela acabar, usa while (laço de repetição)
	while(fgets(conteudo, 200, file) != NULL) //enquanto fgets (buscar no arquivo) estiver escrevendo na string conteúdo, até 200 valores que estão dentro do arquivo, enquanto for diferente de nulo
	{
		printf("\nEssas são as informações do usuário: "); 
		printf("%s", conteudo); //salvar o conteúdo da variável
		printf("\n\n"); 
	}
	system("pause");
}

int deletar()
{
	char cpf[40]; //criando a variável cpf
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s",cpf); //escanear a string cpf, e salvar no arquivo cpf
	
	remove(cpf); //remover o usuário
	
	;FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema");
		system("pause"); 
	}
	
}

int main()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cartório da EBAC ###\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n ");
		printf("\t2 - Consultar nomes\n ");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //Fim do menu
		
		scanf("%d",&opcao); //Armazenando escolha do usuário
		
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //inicio das funcões 
		{
			case 1: //chamada de funcões 
			registro();
			break;
			
			case 2: 
			consulta();
			break; 
			
			case 3:
			deletar();
			break; 
		
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break; //Fim da seleção
		}
	}
}
