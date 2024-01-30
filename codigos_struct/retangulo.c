#include <stdio.h>
#include <stdlib.h>

/*
- leRetangulo
- criaRetangulo
- calculaArea
- imprimeRetangulo
*/

typedef struct {
	int l1, l2;
} ret;

ret *leRetangulo();
ret *criaRetangulo(int l1, int l2);
int calculaArea(ret *r1);
void imprimeRetangulo(ret *r1);
int ehIgual(ret *r1, ret *r2);

int main() {
	ret *r = criaRetangulo(4, 10);
	ret *ra = leRetangulo();
	imprimeRetangulo(r);	
	imprimeRetangulo(ra);
	printf("Area: %d\n", calculaArea(r));
	if (ehIgual(r, ra)) {
		printf("Sao iguais");
	} else {
		printf("Nao sao iguais");
	}
}

ret *leRetangulo() {
	int l1, l2;
	printf("Informe um dos lados: ");
	scanf("%d", &l1);
	printf("Informe o outro lado: ");
	scanf("%d", &l2);
	return criaRetangulo(l1, l2);
}

ret *criaRetangulo(int l1, int l2) {
	ret *r = (ret *)malloc(sizeof(ret));
	//Fazer as validações
	if (l1 < l2) {
		r->l1 = l1;
	    r->l2 = l2;
	} else {
		r->l2 = l1;
		r->l1 = l2;
	}
}

void imprimeRetangulo(ret *r1) {
	printf("Retangulo: %d x %d\n", r1->l1, r1->l2);
}

int calculaArea(ret *r1) {
	return r1->l1 * r1->l2;
}

int ehIgual(ret *r1, ret *r2) {
	if (r1->l1 == r2->l1 && r1->l2 == r2->l2)
	 	return 1;
	else
		return 0;
}

