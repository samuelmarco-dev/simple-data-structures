#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500

typedef struct {
    int valor;   // Valor da carta
    char num;    // A = 1, 2, ..., 0 = 10, Q = Dama, J = Valete, K = Rei
    char naipe;  // O = Ouros, E = Espadas, C = Copas, P = Paus
} carta;

typedef struct {
    carta *cartas[N];
    int nrcarta;
} baralho;

carta *criaCarta(char valor, char naipe);
void mostraCarta(carta *c1);
baralho *criaBaralhoVazio();
baralho *criaBaralho();
void mostraBaralho(baralho *b1);
void embaralha(baralho *b1);

carta *proximaCarta(baralho *b);
void adicionaCarta(baralho *b, carta *c);
int totalPontos(baralho *b);
int totalCartas(baralho *b);

void jogaPC(baralho *monte, baralho *pc, int limite);
void jogaPessoa(baralho *monte, baralho *jogador);
void mostraResultado(baralho *mao, char *nome);
int resultado(baralho *j1, baralho *j2);

int main() {
    int res;

    srand(time(NULL));
    baralho *monte = criaBaralho();
    embaralha(monte);
    //mostraBaralho(monte);

    baralho *pc = criaBaralhoVazio();
    baralho *jogador = criaBaralhoVazio();
    adicionaCarta(jogador, proximaCarta(monte));
    adicionaCarta(pc, proximaCarta(monte));
    adicionaCarta(jogador, proximaCarta(monte));
    adicionaCarta(pc, proximaCarta(monte));

    jogaPC(monte, pc, 20);    
    jogaPessoa(monte, jogador);    
    
    mostraResultado(pc, "PC");
    mostraResultado(jogador, "Jogador");
    res = resultado(jogador, pc);
    if (res == 0) {
        printf("EMPATE :|");
    } else if (res == 1) {
        printf("Parabens, voce ganhou! >:)");
    } else {
        printf("Voce perdeu :/");
    }
    printf("\n\n");
}

carta *criaCarta(char numero, char naipe) {
    char numvalido[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'Q', 'J', 'K'};
    int valores[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    int i;
    carta *c1;

    c1 = (carta *)malloc(sizeof(carta));
    
    // Validando o naipe
    switch (naipe) {
        case 'O': case 'E': case 'C': case 'P':
            c1->naipe = naipe;
            //Validando o numero
            for (i = 0; i<13; i++) {
                if (numero == numvalido[i]) {
                    c1->num = numero;
                    c1->valor = valores[i];
                    return c1;
                }
            }
    }

    free(c1);
    return NULL;
}

void adicionaCarta(baralho *b, carta *c) {
    b->cartas[b->nrcarta++] = c;
}

baralho *criaBaralhoVazio() {
    baralho *b1 = (baralho *)malloc(sizeof(baralho));
    b1->nrcarta = 0;
    return b1;
}

baralho *criaBaralho() {
    int i, j;
    char num[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'Q', 'J', 'K'};
    char naipe[] = {'O', 'E', 'C', 'P'};
    baralho *b1 = criaBaralhoVazio();
   
    for(i=0; i<13; i++) {
        for (j=0; j<4; j++) {
            adicionaCarta(b1, criaCarta(num[i], naipe[j]));
        }
    }

    return b1;
}

void mostraCarta(carta *c1) {
    int i;
    char valores[] = {'O', 'E', 'C', 'P'};
    char *naipes[] = {"<>","/\\", "S2", "&&"};

    for (i=0; i<4; i++) {
        if (c1->naipe == valores[i]) break;
    }

    if (c1->num == '0')
        printf(" 10_%s ", naipes[i]);
    else
        printf(" _%c_%s ", c1->num, naipes[i]);
}

void mostraBaralho(baralho *b1) {
    int i;
    for (i = 0; i<b1->nrcarta; i++) {
        mostraCarta(b1->cartas[i]);
        if (i % 4 == 3) printf("\n");
    }
}

void embaralha(baralho *b1) {
    int i, a, b, vezes;
    carta *aux;
    vezes = b1->nrcarta * 3;
    for (i=0; i<vezes; i++) {
        a = rand() % b1->nrcarta;
        b = rand() % b1->nrcarta;
        aux = b1->cartas[a];
        b1->cartas[a] = b1->cartas[b];
        b1->cartas[b] = aux;
    }
}

carta *proximaCarta(baralho *b) {
    if (b->nrcarta == 0)
        return NULL;

    b->nrcarta--;
    return b->cartas[b->nrcarta];
}

int totalPontos(baralho *b) {
    int i, total = 0;
    for (i=0; i<b->nrcarta; i++) {
        total += b->cartas[i]->valor;
    }
    return total;
}

int totalCartas(baralho *b) {
    return b->nrcarta;
}

void jogaPC(baralho *monte, baralho *pc, int limite) {
    while (totalPontos(pc) < limite) {
        adicionaCarta(pc, proximaCarta(monte));
    }
}

void jogaPessoa(baralho *monte, baralho *jogador) {
    char nova;
    carta *c;

    printf("Suas cartas: \n");
    mostraBaralho(jogador);
    printf("\n\n");
    do {
        printf("Deseja uma nova carta? (S ou s para SIM, qualquer outra para não) ");
        scanf(" %c", &nova);
        if (nova == 's' || nova == 'S') {
            c = proximaCarta(monte);
            adicionaCarta(jogador, c);
            printf("Nova Carta: ");
            mostraCarta(c);
            printf("\n");
        }
    } while (nova == 's' || nova == 'S');
}

void mostraResultado(baralho *mao, char *nome) {
    printf("\n***************\nResultado %s\n***************\n", nome);
    printf("%d cartas e %d pontos\n", totalCartas(mao), totalPontos(mao));
    if (totalPontos(mao) == 21) {
        printf("UHULLL Arrasou\n");
    } else if (totalPontos(mao) > 21) {
        printf("Estourou\n");
    }
    mostraBaralho(mao);
    printf("\n");

}

int resultado(baralho *j1, baralho *j2) {
    int p1, p2;
    p1 = totalPontos(j1); 
    p2 = totalPontos(j2);

    //Retorna 0 para empate, 1 para o jogador 1 e -1 para o jogador 2
    if (p1 == p2 || (p1 > 21 && p2 > 21)) {
        return 0;
    } else if (p2 > 21 || p2 < p1) {
        return 1;
    } else {
        return -1;
    }
}