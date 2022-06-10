#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include "header.h"

//Constantes
#define QNT 10		//quantidades total de cartas entregue

int mostrar_regras(){
	int x;
	printf(" ===========================================================================\n");
	printf(" |                                Jogo de cartas                           |\n");
	printf(" ===========================================================================\n");
	printf(" | Devem ser distribu�das 5 cartas para cada um dos jogadores. A cada      |\n");
	printf(" | rodada, o computador inicia jogando uma carta e, na sequ�ncia, o joga-  |\n");
	printf(" | dor deve jogar a sua carta. Ganha um ponto o jogador que jogar a carta  |\n");
	printf(" | maior e, caso as cartas possuam o mesmo naipe, o jogador ganha mais um  |\n");
	printf(" | ponto. Caso as duas cartas possuam o mesmo valor, declara-se empate na  |\n");
	printf(" | jogada e nenhum jogador ganha ponto. As cartas devem ser utilizadas     |\n");
	printf(" | apenas 1 vez. Ao final das 5 rodadas deve ser informado o vencedor do   |\n");
	printf(" | jogo e deve-se questionar o usu�rio se deseja jogar novamente.          |\n");
	printf(" | Ordem crescente das cartas:                                             |\n");
	printf(" | A - 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10 - J - Q - K                  |\n");
	printf(" ===========================================================================\n");

	printf(" =====================\n");
	printf(" |Deseja prosseguir? |\n");
	printf(" | 1 - SIM           |\n | 2 - NAO           |\n");
	printf(" =====================\n");
	scanf(" %d", &x);

	system("@cls || clear");
	return x;
}

void criar_baralho(struct Baralho *carta, int x){
	carta->valor = x / 4 + 1; 		//aqui e dado o valor das cartas na ordem 1, 1, 1, 1, 2, 2, 2, 2...

	switch(x%4){					//aqui eh dado o valor dos naipes que vai acompanhar a ordem acima
	case 0:
		carta->naipes = 'O';
		break;
	case 1:
		carta->naipes = 'E';
		break;
	case 2:
		carta->naipes = 'C';
		break;
	case 3:
		carta->naipes = 'P';
		break;
	}
}

void mostrar_baralho(struct Baralho *cartas, int i){
	if(i == 13 || i == 26 || i == 39){
		printf("\n");
	}
	if(cartas->valor == 1 || cartas->valor > 10){
		printf("(%c de %c)  ", verificar_carta(cartas), cartas->naipes);
	} else{
		printf("(%d de %c)  ", cartas->valor, cartas->naipes);
	}
}

char verificar_carta(struct Baralho *carta){
	switch (carta->valor){
		case 1:
			return 'A'; break;
		case 11:
			return 'J'; break;
		case 12:
			return 'Q'; break;
		case 13:
			return 'K'; break;
		}
	return 0;
}

void embaralhar(struct Baralho *cartasx, struct Baralho *cartasy){
	int	 auxV; 		//auxV eh uma auxiliar das variaveis valor
    char auxN;		//auxN eh uma auxiliar das variaveis naipes

	auxV = cartasx->valor;
	cartasx->valor = cartasy->valor;
	cartasy->valor = auxV;

	auxN = cartasx->naipes;
	cartasx->naipes = cartasy->naipes;
	cartasy->naipes = auxN;
}

void mostrar_cartaCPC(struct Baralho cPC[], int x){
	for(int i=0; i<5-x; i++){
		printf("  -------------  ");
	}
	printf("\n");
	if(verificar_carta(&cPC[x]) == 0){
		if(cPC[x].valor == 10){
			printf(" |%d%c          | ", cPC[x].valor, cPC[x].naipes);
		}else{
			printf(" |%d%c           | ", cPC[x].valor, cPC[x].naipes);
		}
	}else {
		printf(" |%c%c           | ", verificar_carta(&cPC[x]), cPC[x].naipes);
	}
	if(x < 5){
		versoCarta(x-1);
	}
	printf("\n");
	printf(" |   -------   | ");
	if(x < 5){
		versoCarta(x-1);
	}
	printf("\n");
	printf(" |  |       |  | ");
	if(x < 5){
		versoCarta(x-1);
	}
	printf("\n");
	printf(" |  |       |  | ");
	if(x < 5){
		versoCarta(x-1);
	}
	printf("\n");
	printf(" |  |       |  | ");
	if(x < 5){
		versoCarta(x-1);
	}
	printf("\n");
	if(verificar_carta(&cPC[x]) == 0){
		if(cPC[x].valor == 10){
			printf(" |  |   %d  |  | ", cPC[x].valor);
		} else{
			printf(" |  |   %d   |  | ", cPC[x].valor);
		}
	} else{
		printf(" |  |   %c   |  | ", verificar_carta(&cPC[x]));
	}
	if(x < 5){
		versoCarta(x-1);
	}
	printf("\n");
	printf(" |  |       |  | ");
	if(x < 5){
		versoCarta(x-1);
	}
	printf("\n");
	printf(" |  |       |  | ");
	if(x < 5){
		versoCarta(x-1);
	}
	printf("\n");
	printf(" |  |       |  | ");
	if(x < 5){
		versoCarta(x-1);
	}
	printf("\n");
	printf(" |   -------   | ");
	if(x < 5){
		versoCarta(x-1);
	}
	printf("\n");
	if(verificar_carta(&cPC[x]) == 0){
		if(cPC[x].valor == 10){
			printf(" |          %c%d| ", cPC[x].naipes, cPC[x].valor);
		}else{
			printf(" |           %c%d| ",cPC[x].naipes, cPC[x].valor);
		}
	} else{
		printf(" |           %c%c| ",cPC[x].naipes, verificar_carta(&cPC[x]));
	}
	if(x < 5){
		versoCarta(x-1);
	}
	printf("\n");
	for(int i=0; i<5-x; i++){
			printf("  -------------  ");
	}
	printf("\n");
}

void versoCarta(int x){
	for(int i=0; i<3-x; i++){
		printf(" |* * * * * * *| ");
	}
}

void mostrar_cartasPlayer(struct Baralho cPlayer[], int x){
	for(int i=0; i<5-x; i++){
		printf("  -------------  ");
	}
	printf("\n");
	for(int i=0; i<5-x; i++){
		if(verificar_carta(&cPlayer[i]) == 0){
			if(cPlayer[i].valor == 10){
				printf(" |%d%c          | ",cPlayer[i].valor, cPlayer[i].naipes);
			}else{
				printf(" |%d%c           | ", cPlayer[i].valor, cPlayer[i].naipes);
			}
		}else {
			printf(" |%c%c           | ", verificar_carta(&cPlayer[i]), cPlayer[i].naipes);
		}
	}
	printf("\n");
	for(int i=0; i<5-x; i++){
		printf(" |   -------   | ");
	}
	printf("\n");
	for(int i=0; i<3; i++){
		for(int j=0; j<5-x; j++){
			printf(" |  |       |  | ");
		}
		printf("\n");
	}
	for(int i=0; i<5-x; i++){
		if(verificar_carta(&cPlayer[i]) == 0){
			if(cPlayer[i].valor == 10){
				printf(" |  |   %d  |  | ", cPlayer[i].valor);
			} else{
				printf(" |  |   %d   |  | ", cPlayer[i].valor);
			}
		} else{
			printf(" |  |   %c   |  | ", verificar_carta(&cPlayer[i]));
		}
	}
	printf("\n");
	for(int i=0; i<3; i++){
		for(int j=0; j<5-x; j++){
			printf(" |  |       |  | ");
		}
		printf("\n");
	}
	for(int i=0; i<5-x; i++){
		printf(" |   -------   | ");
	}
	printf("\n");
	for(int i=0; i<5-x; i++){
		if(verificar_carta(&cPlayer[i]) == 0){
			if(cPlayer[i].valor == 10){
				printf(" |          %c%d| ",cPlayer[i].naipes, cPlayer[i].valor);
			}else{
				printf(" |           %c%d| ",cPlayer[i].naipes, cPlayer[i].valor);
			}
		} else{
			printf(" |           %c%c| ",cPlayer[i].naipes, verificar_carta(&cPlayer[i]));
		}
	}
	printf("\n");
	for(int i=0; i<5-x; i++){
		printf("  -------------  ");
	}
	printf("\n");
}

int sair(){
    int sair;
    printf(" ====================================================================================\n");
	printf(" | Deseja jogar novamente?                                                          |\n");
	printf(" | 1 - SIM   2 - NAO                                                                |\n");
	printf(" ====================================================================================\n");
    return scanf("%d", &sair);
}