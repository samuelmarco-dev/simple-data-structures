#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int base, altura;
} retangulo;

int verificaDadosRetangulo(int base, int altura);
retangulo *criaRetangulo(int base, int altura);
retangulo *leRetangulo();
void imprimeRetangulo(retangulo *r);

float calculaArea(retangulo *r);
void ehIgual(retangulo *r1, retangulo *r2);

int main() {
    retangulo *r1, *r2;
    r1 = criaRetangulo(10, 10);
    r2 = leRetangulo();

    printf("\nRetangulo 1: \n");
    imprimeRetangulo(r1);
    printf("Area do retangulo 1: %.3f m^2\n", calculaArea(r1));

    printf("Retangulo 2: \n");
    imprimeRetangulo(r2);
    printf("Area do retangulo 2: %.3f m^2\n", calculaArea(r2));

    printf("\n");
    ehIgual(r1, r2);

    return 0;
}

int verificaDadosRetangulo(int base, int altura) {
    if(base < 0 || altura < 0) return 0; 
    return 1;
}

retangulo *criaRetangulo(int base, int altura) {
    if(verificaDadosRetangulo(base, altura)) {
        retangulo *r = (retangulo *)malloc(sizeof(retangulo));
        r->base = base;
        r->altura = altura;
        return r;
    }

    printf("Dados invalidos. Tente novamente!\n");
    return NULL;
}

retangulo *leRetangulo() {
    int base, altura;

    printf("Informe a base do retangulo: ");
    scanf("%d", &base);
    printf("Informe a altura do retangulo: ");
    scanf("%d", &altura);

    return criaRetangulo(base, altura);
}

void imprimeRetangulo(retangulo *r) {
    if(r == NULL) {
        printf("Erro. O parametro passado é um ponteiro nulo\n");
        return;
    }

    printf("Base: %d, Altura: %d\n", r->base, r->altura);
}

float calculaArea(retangulo *r) {
    return r->base * r->altura;
}

void ehIgual(retangulo *r1, retangulo *r2) {
    float areaRetangulo1 = calculaArea(r1);
    float areaRetangulo2 = calculaArea(r2);

    if(areaRetangulo1 == areaRetangulo2) {
        printf("Em termos de area, os retangulos sao iguais\n");
        return;
    }
    
    printf("Em termos de area, os retangulos sao diferentes\n");
}
