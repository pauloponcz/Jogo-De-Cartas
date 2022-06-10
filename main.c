#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include "header.h"

//Constantes
#define QNT 10		//quantidades total de cartas entregue

int main(void) {
	int op, ok = 0;
	int s[QNT];								 //variavel que receber os numeros sorteados
	int placar[2] = {0, 0}; 				//variavel para marcar o placar onde no primeiro espaco eh o placar do player e o segundo para o PC
	struct Baralho cartas[52];				//struct onde vai ta armazando as cartas
	struct Baralho cPC[5];					//armazena as cartas do PC
	struct Baralho cPlayer[5];				//armazena as cartas do Player
	struct Baralho x[5];					//onde vai ficar guardado as cartas escolhidas pelo player

	srand(time(NULL));
	setbuf(stdout, NULL);
	system("@cls || clear");

	op = mostrar_regras();
	if (op == 1){
		//dentro do FOR ocorrera um processo para dar valores para a struct Baralho cartas
		for(int i=0; i<52; i++){
			criar_baralho(&cartas[i], i);
		}

		printf("\n ========================= Esse eh o baralho ==========================\n");
		printf("\n");
		for(int i=0; i<52; i++){
			mostrar_baralho(&cartas[i], i);
		}
		printf("\n ======================================================================\n");
		system("pause");
		system("@cls || clear");
		printf("\n");
		printf(" ============================ EMBARALHANDO ============================\n");
		//nesse FOR o baralho sera embaralhado
		for(int i=0, j=0; i<52; i++){
			do {
				j = rand()%52;
			} while (i == j);
			embaralhar(&cartas[i], &cartas[j]);
		}
		//mostrar as cartas novamente depois do embaralhamento
		for(int i=0; i<52; i++){
			Sleep(100);
			mostrar_baralho(&cartas[i], i);
		}
		printf("\n");
		system("@cls || clear");

		//Nesse DO o jogo comeca
		do{
			//Aqui eh sorteado as cartas ao PC e ao Player e no For eh para n�o repetir as cartas
			for(int i=0; i<QNT; i++){
				s[i]=rand()%52;
				for(int j=0; j<i; j++){
					if (s[j] == s[i]){
						i--;
					}
				}
			}
				//Atribui valor para as structs
				for (int i=0; i<QNT/2; i++){
					cPC[i] = cartas[s[i]];
					cPlayer[i] = cartas[s[i+5]];
				}

				//Aqui comeca a rodada
				for(int i=0; i<5; i++){
					system("@cls || clear");

					printf(" ====================================================================================\n");
					printf(" |                            RODADA %d - Player [%d x %d] PC                          |\n", i+1, placar[0], placar[1]);
					printf(" ====================================================================================\n");
					system("pause");
					printf("\n");
					//mostra a carta do computador
					mostrar_cartaCPC(cPC, i);
					printf(" ====================================================================================\n");
					printf(" |                                    SUAS CARTAS                                   |\n");
					printf(" ====================================================================================\n");
					//mostra as cartas do player
					mostrar_cartasPlayer(cPlayer, i);

					//O programa eh rodado ate que o player digite um numero valido
					do{
						printf(" ====================================================================================\n");
						printf(" | Escolha uma carta(Por ex: 9 P):                                                  |\n");
						printf(" | Digite 1 para A / 11 - J / 12 - Q / 13 - K                                       |\n");
						printf(" ====================================================================================\n");
						scanf("%d %c", &x[i].valor, &x[i].naipes);
						ok = 0;

						for(int j = 0; j<5-i; j++){
							//if para verificar se o valor digitado eh valido
							if(x[i].valor == cPlayer[j].valor && x[i].naipes == cPlayer[j].naipes){
								ok = 1;
							}
						}
						if(ok == 0){
							printf("\n | Esse valor eh invalido!!! Tente Novamente.\n");
						}
					}while(ok == 0);
					//Aqui ocorre a retirada da carta escolhida pelo player
					for(int j = 0; j<5; j++){
						if(x[i].valor == cPlayer[j].valor && x[i].naipes == cPlayer[j].naipes && j < 4){
							for(int k=j; k<4; k++){
								cPlayer[k] = cPlayer[k+1];
							}
						}
					}
					//If para marcar placar
					if(x[i].valor > cPC[i].valor){
						if(x[i].naipes == cPC[i].naipes){
							placar[0] += 2;
						} else{
							placar[0]++;
						}
					} else if(cPC[i].valor > x[i].valor){
						if(x[i].naipes == cPC[i].naipes){
							placar[1] += 2;
						} else{
							placar[1]++;
						}
					} else{
						printf("\n| Ninguem pontuou!!\n");
					}
				}
				printf(" ====================================================================================\n");
				if (placar[0] > placar[1]){
					printf(" | O vencededor eh o PLayer!!!                                                 |\n");
				}else{
					printf(" | O vencededor eh o PC!!!                                                     |\n");
				}				
				
		}while(sair == 1);
	}
	return EXIT_SUCCESS;
}


