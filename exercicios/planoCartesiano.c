#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

typedef struct {
    int abcissas;  //eixo x
    int ordenadas; //eixo y
} ponto;

ponto *criaPonto(int x, int y);
ponto *lePonto();
void mostraPonto(ponto *p);

int quadrante(ponto *p);
int boolAbcissas(int value);
int boolOrdenadas(int value);
float distancia(ponto *p1, ponto *p2);
float potencia(int x);

int main() {
    setlocale(LC_ALL, "");

    ponto *p1, *p2;
    p1 = criaPonto(5, 7);
    p2 = lePonto();
    int numeroQuadranteP1 = quadrante(p1);
    int numeroQuadranteP2 = quadrante(p2);

    printf("Ponto 1: \n");
    mostraPonto(p1);
    printf("Quadrante: %d\n", numeroQuadranteP1);

    printf("Ponto 2: \n");
    mostraPonto(p2);
    printf("Quadrante: %d\n", numeroQuadranteP2);

    float diferenca = distancia(p1, p2);
    printf("A distância entre os ponto é de %.2f u.a\n", fabs(diferenca));

    return 0;
}

ponto *criaPonto(int x, int y) {
    ponto *p = (ponto *)malloc(sizeof(ponto));
    p->abcissas = x;
    p->ordenadas = y;

    return p;
}

ponto *lePonto() {
    int x, y;

    printf("Insira o valor da coordenada no eixo x: ");
    scanf("%d", &x);
    printf("\nInsira o valor da coordenada no eixo y: ");
    scanf("%d", &y);

    return criaPonto(x, y);
}

void mostraPonto(ponto *p) {
    if(p == NULL) {
        printf("Erro inesperado! Este ponto possui referência NULL na memória!\n");
        exit(1);
    }

    printf("Coordenadas: (%d, %d)\n", p->abcissas, p->ordenadas);
}

int quadrante(ponto *p) {
    if(p == NULL) {
        printf("O ponteiro recebido é nulo. Tente novamente!\n");
        exit(1);
    }
    
    if(boolAbcissas(p->abcissas) && boolOrdenadas(p->ordenadas)) return 1;
    if(!boolAbcissas(p->abcissas) && boolOrdenadas(p->ordenadas)) return 2;
    if(!boolAbcissas(p->abcissas) && !boolOrdenadas(p->ordenadas)) return 3;
    if(boolAbcissas(p->abcissas) && !boolOrdenadas(p->ordenadas)) return 4;
}

int boolAbcissas(int value) {
    return value >= 0;
}

int boolOrdenadas(int value) {
    return value >= 0;
}

float distancia(ponto *p1, ponto *p2) {
    return sqrt(potencia(p2->abcissas - p1->abcissas) + potencia(p2->ordenadas - p1->ordenadas));
}

float potencia(int x) {
    return x*x;
}
