#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

struct endereco
{
	char rua[50];
	char bairro[20];
	int numero;
	char cep[12];
	char complemento[80];	
};
struct cadastro
{
	char nome[35];
	char rg[15];
	int data_dia;
	int data_mes;
	int data_ano;
	int verific_ong;
	int verific_motorista;
};

int main(){
	
   	char opcao_telainicial, rg_motorista[15];
	int controle_telainicial = 1, opcao_cadastro,conta_idade, tempo_aluguel;
	float valor_total, desconto_idoso, desconto_ong, desconto_total, valor_aluguel;
	struct cadastro cadastro_cliente; 
	struct endereco endereco_cliente;
	FILE *fp;
    
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    printf("Data: %d/%d/%d/\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    
	do { 
	
		printf("|-----------------------------|\n");
		printf("|    1) Pedido Carro          |\n");
		printf("|                             |\n");
		printf("|                             |\n");
		printf("|    2) Sair Programa         |\n");
		printf("|-----------------------------|\n");
		printf("Opcao Escolhida: ");
		scanf("%d", &opcao_telainicial);
		fflush(stdin);
		switch(opcao_telainicial){
			
				case 1:
					fp = fopen("Cliente.txt","a");
					if(!fp)
					{
					printf( "Erro na abertura do arquivo");
					exit(0);
					}
					printf("----------------------------------------------");
					printf("\n               Cadastro Cliente           \n");
					printf("\nInforme o seu nome: ");
					gets(cadastro_cliente.nome);
					fprintf( fp, "Nome: %s\t", cadastro_cliente.nome);
					fflush(stdin);
					printf("\nInforme o Numero do seu RG (com pontuacao): ");
					scanf("%s", &cadastro_cliente.rg);
					fprintf( fp, "RG: %s\t", cadastro_cliente.rg);
					printf("\nPossui parceria com ONG?\n1) Sim\n2) Nao\n\nOpcao Escolhida: ");
					scanf("%d", &cadastro_cliente.verific_ong);
					printf("\nInforme o dia do seu Nascimento: ");
					scanf("%d", &cadastro_cliente.data_dia);
					fprintf( fp, "%d/", cadastro_cliente.data_dia);
					printf("\nInforme o mes do seu Nascimento: ");
					scanf("%d", &cadastro_cliente.data_mes);
					fprintf( fp, "%d/", cadastro_cliente.data_mes);
					printf("\nInforme o ano do seu Nascimento: ");
					scanf("%d", &cadastro_cliente.data_ano);
					fprintf( fp, "%d\t", cadastro_cliente.data_ano);
						if (( tm.tm_mon + 1)>= cadastro_cliente.data_mes){
							conta_idade = ((tm.tm_year + 1900) - cadastro_cliente.data_ano);
						} 
						else 
							conta_idade = ((tm.tm_year + 1900) - cadastro_cliente.data_ano)-1;		
					fprintf( fp,"Idade: %d\n",conta_idade);
					printf("\n----------------------------------------------\n");
					fclose(fp);
					fflush(stdin);
						fp = fopen("Pedido_Carro.txt","a");
						if(!fp)
						{
						printf( "Erro na abertura do arquivo");
						exit(0);
						}
						printf("----------------------------------------------");
						printf("\n               Pedido Carro               \n");
						printf("\nInforme o nome da sua rua: ");
						gets(endereco_cliente.rua);
						fprintf( fp, "Rua: %s\t", endereco_cliente.rua);
						fflush(stdin);
						printf("\nInforme o seu Bairro: ");
						gets(endereco_cliente.bairro);
						fprintf( fp, "Bairro: %s\t\n", endereco_cliente.bairro);
						fflush(stdin);
						printf("\nInforme o numero da sua casa: ");
						scanf("%d", &endereco_cliente.numero);
						fprintf( fp, "Numero: %d\t", endereco_cliente.numero);
						fflush(stdin);
						printf("\nInforme o seu CEP: ");
						scanf("%s", &endereco_cliente.cep);
						fprintf( fp, "CEP: %s\t\n", endereco_cliente.cep);
						fflush(stdin);
						printf("\nDefina um ponto de Referencia: ");
						gets(endereco_cliente.complemento);
						fprintf( fp, "Complemento: %s\n", endereco_cliente.complemento);
						fflush(stdin);
						printf("\nE desejavel motorista?\n1) Sim\n2) Nao\n\nOpcao Escolhida: ");
						scanf("%d", &cadastro_cliente.verific_motorista);
						fflush(stdin);
						printf("\n----------------------------------------------\n");
						printf("Digite o tempo do Aluguel em dias: ");
						scanf("%d", &tempo_aluguel);
						fprintf( fp, "\nTempo: %d dias", tempo_aluguel);
						printf("\n----------------------------------------------\n");
							if (cadastro_cliente.verific_ong == 1){
								valor_aluguel = tempo_aluguel * 50;
								desconto_ong = valor_aluguel*0,05;
						}  
							else if (cadastro_cliente.verific_ong == 2)
							{
								valor_aluguel = tempo_aluguel * 50;
						    }
							if (conta_idade >= 60){
								valor_aluguel = tempo_aluguel * 50;
								desconto_idoso = valor_aluguel*0,1;
							}
							else{
								valor_aluguel = tempo_aluguel * 50;	
							}
							desconto_total = desconto_idoso + desconto_ong;
							valor_aluguel = valor_aluguel - desconto_total;
							printf("\n----------------------------------------------\n");
							printf("\tComprovante de Locacao\t\n");
							printf("Valor Total Locacao: %.2f\n", valor_aluguel);
							printf("Desconto Idoso: %.2f\n",desconto_ong);
							printf("Desconto Idoso: %.2f",desconto_idoso);
							printf("\n----------------------------------------------\n");
							fp = fopen("Ticket.txt","a");
							if(!fp)
							{
							printf( "Erro na abertura do arquivo");
							exit(0);
							}
							
						break;	
				case 2:
					printf("Fim Programa");
					break;
				
				default :
					printf("Valor Invalido!\n");
						}
				controle_telainicial = 0;
			} while (controle_telainicial != 0);
	system("Pause");	
}
