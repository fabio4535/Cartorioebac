#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()
{
	//inicio de criação de variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome [40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variaveis/string
    
    printf("Digite o cpf a ser cadastrado: ");//coletando informações do usoário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //responsavel por criar os valores dos string
     
     FILE *file; //cria o arquivo
     file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
     fprintf(file,cpf); //salvo o valor da variavel
     fclose(file); //fecha o arquivo
     
     file = fopen(arquivo, "a");
     fprintf(file,",");
     fclose(file);
     
     printf("Digite o nome a ser cadastrado: ");
     scanf("%s",nome);
     
	 file = fopen(arquivo, "a");
	 fprintf(file,nome);
	 fclose(file);
	 
	 file = fopen(arquivo, "a");
     fprintf(file,",");
     fclose(file);
     
     printf("Digite o sobrenome a ser cadastrado: ");
     scanf("%s", sobrenome);
     
     file = fopen(arquivo, "a");
     fprintf(file,sobrenome);
     fclose(file);
     
     printf("Digite o cargo a ser cadastrado: ");
     scanf("%s", cargo);
     
     file = fopen(arquivo, "a");
     fprintf(file,cargo);
     fclose(file);
     
     system("pause");
     

}


int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	
	}
	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informaçôes do usuário: ");
		printf("%s", conteudo);
		printf("\n\n"); 
	}
	
	system("pause");
}


int deletar()
{
    char cpf[40];
 
    printf("Digite o cpf do usuário a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf); 
    
    FILE *file;
    file = fopen(cpf,"r");
 
 
    if(file == NULL)
   {
    	printf("usuário deletado com suceso!.\n");
 	    system("pause");
  
   }


}
int main()
{
	int opcao=0; //Definindo Variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	    
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //inicio do Menu
	    printf("escolha a opção desejada do menu:\n\n");
	    printf("\t1 - registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - Deletar nomes \n\n"); 
	    printf("opção: "); //fim do menu
	
        scanf("%d", &opcao); //armazenando a escolha do usuário
	
	    system("cls"); //responsavel por limpa a tela
	    
	    
	    switch(opcao) //inicio da seleção do menu
	    {
	    	case 1:
	        registro(); //chamada de funções
	       	break;
		
			case 2:
			consulta();
            break;	
		
			case 3:
		    deletar();
	        break;
		
			default:
			printf("essa opção não está disponivel!\n");
    	    system("pause");
	        //fim da seleção	
			
		}
		
    }
	 
    

}
    
    

