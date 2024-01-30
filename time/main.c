#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hora, min, seg;
} time;

time *criaTempo(int h, int m, int s);
time *leTempo();
void mostraTempo(time *t);
time *adicionarTempo(time *t, int seg);
time *subtrairTempo(time *t, int seg);
time *diferenca(time *t1, time *t2);

int emSegundos(time *t);
time *emHoras(int seg);

int main() {
    time *t1, *t2, *t3;

    t1 = criaTempo(13,0,0);
    t2 = leTempo();
    t3 = diferenca(t1, t2);

    mostraTempo(t1);
    mostraTempo(t2);
    mostraTempo(t3);

    return 0;
}

time *criaTempo(int h, int m, int s) {
    if(s > 59){
        printf("Segundos invalidos!\n");
        return NULL;
    }
    if(m > 59){
        printf("Minutos invalidos!\n");
        return NULL;
    }
    if(h<0 || m<0 || s<0){
        printf("O tempo nao pode ser negativo\n");
        return NULL;
    }

    time *t = (time *)malloc(sizeof(time));
    t->hora = h;  //(*t).hora
    t->min = m;  //(*t).min
    t->seg = s; // (*t).seg

    return t;
}

time *leTempo() {
    int h, m, s;

	printf("Informe a hora: ");
	scanf("%d", &h);
	printf("Informe os minutos: ");
	scanf("%d", &m);
	printf("Informe os segundos: ");
	scanf("%d", &s);

    return criaTempo(h, m, s);
}

void mostraTempo(time *t) {
    if(t == NULL){
        printf("Tempo invalido\n");
        return;
    }

    printf("Tempo: %2d:%2d:%2d\n", t->hora, t->min, t->seg);
}

time *adicionarTempo(time *t, int seg) {
    int totalTempo = emSegundos(t) + seg;
    time *aux = emHoras(totalTempo);
    
    if(aux != NULL){
        t->hora = aux->hora;
        t->min = aux->min;
        t->seg = aux->seg;
        free(aux);
    }

    return t;
}

time *subtrairTempo(time *t, int seg) {
    int totalTempo = emSegundos(t) - seg;
    time *aux = emHoras(totalTempo);
    
    if(aux != NULL){
        t->hora = aux->hora;
        t->min = aux->min;
        t->seg = aux->seg;
        free(aux);
    }

    return t;
}

time *diferenca(time *t1, time *t2) {
    int s1, s2;
    s1 = emSegundos(t1);
    s2 = emSegundos(t2);

    if(s1>s2) {
        return emHoras(s1 - s2);
    } else{
        return emHoras(s2 - s1);
    }
}

int emSegundos(time *t) {
    return t->hora * 3600 + t->min * 60 + t->seg;
}

time *emHoras(int seg) {
    int h, m;
    if(seg < 0) exit(1);

    h = seg/3600;
    seg = seg % 3600;
    m = seg/60;
    seg = seg % 60;

    return criaTempo(h, m, seg);
}
