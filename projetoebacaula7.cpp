#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()
{
	//inicio de cria��o de variaveis/string
	char arquivo[40];
    char cpf[40];
    char nome [40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de variaveis/string
    
    printf("Digite o cpf a ser cadastrado: ");//coletando informa��es do uso�rio
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
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	
	}
	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n"); 
	}
	
	system("pause");
}


int deletar()
{
    char cpf[40];
 
    printf("Digite o cpf do usu�rio a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf); 
    
    FILE *file;
    file = fopen(cpf,"r");
 
 
    if(file == NULL)
   {
    	printf("usu�rio deletado com suceso!.\n");
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
	
	    printf("### Cart�rio da EBAC ###\n\n"); //inicio do Menu
	    printf("escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - Deletar nomes \n\n"); 
	    printf("\t4 - Sair do sistema\n\n");
	    
	    printf("op��o: "); //fim do menu
	
        scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	    system("cls"); //responsavel por limpa a tela
	    
	    
	    switch(opcao) //inicio da sele��o do menu
	    {
	    	case 1:
	        registro(); //chamada de fun��es
	       	break;
		
			case 2:
			consulta();
            break;	
		
			case 3:
		    deletar();
	        break;
	        
	        case 4:
	        printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
				
		
			default:
			printf("essa op��o n�o est� disponivel!\n");
    	    system("pause");
	        //fim da sele��o	
			
		}
		
    }
	 
    

}
    
    
