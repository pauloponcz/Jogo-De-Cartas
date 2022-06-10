//Struct
/*Struct para formar o baralho*/
struct Baralho{
	char naipes;	//para O, E, C, P
	int valor;		//para os numeros das cartas
};


//Procedimentos e Funcoes
int mostrar_regras();													//funcao que mostra as regras e retorna se o usuario quer continuar ou nao
void criar_baralho(struct Baralho *cartas, int i);						//procedimento para criar o baralho
void mostrar_baralho(struct Baralho *cartas, int i);					//Procedimento para mostrar o baralho
char verificar_carta(struct Baralho *cartas);							//procedimento para ver se a carta eh uma letra ou numero
void embaralhar(struct Baralho *cartasx, struct Baralho *cartasy);		//procedimento para embaralhar
void mostrar_cartaCPC(struct Baralho cPC[], int i);						//mostra as cartas do Pc
void versoCarta(int x);													//procedimento para ajudar a fazer o verso da carta
void mostrar_cartasPlayer(struct Baralho cPlayer[], int i);				//procedimento para mostrar as cartas do player
int sair();