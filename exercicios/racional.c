#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    float numerador;
    float denominador;
} racional;

racional *criaNumeroRacional(float numerador, float denominador);
racional *leNumeros();
void mostraRacional(racional *r);

float resultado(racional *r);
float adicionaInteiro(racional *r, int valor);
float somaRacionais(racional *r1, racional *r2);
float subtraiInteiro(racional *r, int valor);
float subtraiRacionais(racional *r1, racional *r2);

int main() {
    setlocale(LC_ALL, "");

    racional *r1, *r2;
    r1 = criaNumeroRacional(10, 3);
    r2 = leNumeros();

    printf("Resultado número racional 1: \n");
    mostraRacional(r1);
    printf("Resultado número racional 2: \n");
    mostraRacional(r2);

    float soma = somaRacionais(r1, r2);
    printf("A soma entre %f e %f, resulta em: %f\n", resultado(r1), resultado(r2), soma);
    return 0;
}

racional *criaNumeroRacional(float numerador, float denominador) {
    racional *r = (racional *)malloc(sizeof(racional));
    r->numerador = numerador;
    r->denominador = denominador;

    return r;
}

racional *leNumeros() {
    float x, y;

    printf("Digite o denominador: ");
    scanf("%f", &x);
    printf("\nDigite o numerador: ");
    scanf("%f", &y);

    return criaNumeroRacional(x, y);
}

void mostraRacional(racional *r) {
    printf("Numero racional: %.5f/%.5f = %.5f\n", r->numerador, r->denominador, resultado(r));
}

float resultado(racional *r) {
    return r->numerador/r->denominador;
}

float adicionaInteiro(racional *r, int valor) {
    if(!valor) return resultado(r);
    else return resultado(r) + valor/1;
}

float somaRacionais(racional *r1, racional *r2) {
    return resultado(r1) + resultado(r2);
}

float subtraiInteiro(racional *r, int valor) {
    if(!valor) return resultado(r);
    else return resultado(r) - valor/1;
}

float subtraiRacionais(racional *r1, racional *r2) {
    int result1 = resultado(r1);
    int result2 = resultado(r2);

    if(result1 >= result2) {
        return resultado(r1) - resultado(r2);
    } else {
        return resultado(r2) - resultado(r1);
    }
}
