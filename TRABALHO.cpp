#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
// falta: gravar o ticket no arquivo, inserir multa e cadastrar os clientes para apresentação
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
	int verific_pagamento;
};

int main(){
	
	//declaracao de variaveis
   	char opcao_telainicial, rg_motorista[15], forma_pagamento[50];
	int controle_telainicial = 1, opcao_cadastro,conta_idade;
	float valor_total, desconto_idoso, desconto_ong, desconto_total, valor_aluguel, tempo_aluguel;
	struct cadastro cadastro_cliente; 
	struct endereco endereco_cliente;
	FILE *fp;
    //obtendo a data do sistema
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    printf("Data: %d/%d/%d/\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    
	do { 
	//menu inicial
		printf("|-----------------------------|\n");
		printf("|    1) Pedido Carro          |\n");
		printf("|                             |\n");
		printf("|                             |\n");
		printf("|    2) Sair Programa         |\n");
		printf("|-----------------------------|\n");
		printf("Opcao Escolhida: ");
		scanf("%d", &opcao_telainicial);
		fflush(stdin);
		//limpa a tela
		system("CLS");
		switch(opcao_telainicial){
			
				case 1:
					//cadastro cliente e pedido carro
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
						//calculo idade
						if (( tm.tm_mon + 1)>= cadastro_cliente.data_mes){
							conta_idade = ((tm.tm_year + 1900) - cadastro_cliente.data_ano);
						} 
						else 
							conta_idade = ((tm.tm_year + 1900) - cadastro_cliente.data_ano)-1;		
					fprintf( fp,"Idade: %d\n",conta_idade);
					printf("\n----------------------------------------------\n");
					fclose(fp);
					fflush(stdin);
					system("CLS");
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
						printf("\nDefina a Forma de Pagamento:\n1) Debito \n2) Credito \n3) Dinheiro\n Escolhido: ");
						scanf("%d", &cadastro_cliente.verific_pagamento);
						fprintf( fp, "Forma de Pagamento: %d\n", cadastro_cliente.verific_pagamento);
						fflush(stdin);
						printf("\n----------------------------------------------\n");
						printf("Digite o tempo do Aluguel em dias: ");
						scanf("%f", &tempo_aluguel);
						fprintf( fp, "\nTempo: %d dias", tempo_aluguel);
						printf("\n----------------------------------------------\n");
						fflush(stdin);
						system("CLS");
						//calculo desconto
							if (cadastro_cliente.verific_ong == 1){
								valor_aluguel = tempo_aluguel * 50;
								desconto_ong = valor_aluguel * 0.05;
							}  
							else{
								valor_aluguel = tempo_aluguel * 50;
							}
							if (conta_idade >= 60){
								valor_aluguel = tempo_aluguel * 50;
								desconto_idoso = valor_aluguel* 0.1;
							}
							else{
								valor_aluguel = tempo_aluguel * 50;	
							}
							desconto_total = desconto_idoso + desconto_ong;
							valor_aluguel = valor_aluguel - desconto_total;
							//verificacao de forma de pagamento
							switch (cadastro_cliente.verific_pagamento)
							{
								case 1: 
								strcpy(forma_pagamento, "Debito");
								break;
								
								case 2:
								strcpy(forma_pagamento, "Credito");
								break;
								
								case 3:
								strcpy(forma_pagamento, "Dinheiro");
								break;
								
								default:
								printf("Forma de pagamento invalida!");
							}
							fflush(stdin);
							//comprovante de locacao valores
							printf("\n----------------------------------------------\n");
							printf("\tComprovante de Locacao\t\n");
							printf("Valor Total Locacao: %.2f\n", valor_aluguel);
							printf("Desconto ONG: %.2f\n", desconto_ong);
							printf("Desconto Idoso: %.2f", desconto_idoso);
							printf("\n----------------------------------------------\n");
							fp = fopen("Ticket.txt","a");
							if(!fp)
							{
							printf( "Erro na abertura do arquivo");
							exit(0);
							}
							system("CLS");
							//apresentação ticket
							printf("\n-----------------------------------------------------------\n");
							printf("SLCAI - Sistema de Locacao de Carros Adaptados \ne Inclusivos\n");
							printf("CNPJ: 09.157.788/0012-24\n");
							printf("IM: 422.322\n");
							printf("\t Recibo Provisorio de Servicos\n");
							printf("Data: %d/%d/%d/\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
							printf("Periodo de Aluguel: %f dias\n", tempo_aluguel);
							printf("Tarifa: R$50,00 \n");
							printf("Descontos: \n ONG:   %.2f \n Idoso: %.2f\n", desconto_ong, desconto_idoso);
							printf("Forma de Pagamento: %s", forma_pagamento);
							printf("\n-----------------------------------------------------------\n");
							printf("\t Dados do Cliente \n");
							printf("Nome: %c \n", cadastro_cliente.nome);
							printf("Data de Nascimento: %d/%d/%d \n",cadastro_cliente.data_dia, cadastro_cliente.data_mes, cadastro_cliente.data_ano);
							printf("Idade: %d \n", conta_idade);
							printf("RG: %d \n",cadastro_cliente.rg);
						break;	
				case 2:
					printf("Fim Programa");
					controle_telainicial = 1;
					break;
				
				default :
					printf("Valor Invalido!\n");
						}
			} while (controle_telainicial != 0);
	system("Pause");	
}
