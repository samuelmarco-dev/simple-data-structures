#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int ano;
  int mes;
  int dia;
} data;

int diaMes(int mes) {
  int dias;
  switch (mes){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      dias = 31;
      break;
    case 2:
      dias = 29;
      break;
    default:
      dias = 30;
  }

  return dias;
}

int ehValida(data *d) {
  if (d->dia < 1 || d->dia > diaMes(d->mes)) {
    return 0;
  } else if(d->mes < 1 || d->mes > 12) {
    return 0;
  } else if (d->ano < 2000 || d->ano > 2050) {
    return 0;
  }

  return 1;
}

data *criaData(int dia, int mes, int ano) {
  data *d = (data *) malloc(sizeof(data));
  d->dia = dia;
  d->mes = mes;
  d->ano = ano;

  if (!ehValida(d)) {
    printf("*** Data Invalida! ***");
    exit(1);
  }

  return d;
}

data *leData() {
  int dia, mes, ano;
  printf("Informe o dia: \n");
  scanf("%d", &dia);
  printf("Informe o mes: \n");
  scanf("%d", &mes);
  printf("Informe o ano: \n");
  scanf("%d", &ano);

  return criaData(dia, mes, ano);
}

void nomeMes(int mes, char *nome) {
  switch (mes) {
    case 1:
       strcpy(nome, "Janeiro");
       break;
    case 2:
       strcpy(nome, "Fevereiro");
       break;
    case 3:
      strcpy(nome, "Marco");
      break;
    case 4:
      strcpy(nome, "Abril");
      break;
    case 5:
       strcpy(nome, "Maio");
       break;
    case 6:
       strcpy(nome, "Junho");
       break;
    case 7:
      strcpy(nome, "Julho");
      break;
    case 8:
      strcpy(nome, "Agosto");
      break;
    case 9:
       strcpy(nome, "Setembro");
       break;
    case 10:
       strcpy(nome, "Outubro");
       break;
    case 11:
      strcpy(nome, "Novembro");
      break;
    case 12:
      strcpy(nome, "Dezembro");
      break;
    default:
      strcpy(nome, "Invalido");
  }
}

void exibeData(data *d, int formato) {
  char mes[100];

  switch (formato) {
    case 1:
      if (d->dia < 10) {
        if (d->mes < 10) {
          printf("0%d/0%d/%d\n", d->dia, d->mes, d->ano);
        } else {
          printf("0%d/%d/%d\n", d->dia, d->mes, d->ano);
        }
      } else {
        printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
      }
      break;
    case 2:
        nomeMes(d->mes, mes);
        printf("%d de %s de %d\n", d->dia, mes, d->ano);
        break;
    case 3:
      printf("%4d-%2d-%2d\n", d->ano, d->mes, d->dia);
      break;
    default:
      printf("Formato invalido!\n");
  }
}

long int emDias(data *d) {
  int i;
  long int total;
  total = d->ano * 365;
  for(i = 1; i<d->mes; i++) {
    total += diaMes(i);
  }
  total+= d->dia;
  return total;
}

long int intervaloDias(data *dt1, data *dt2) {
  long int dias1, dias2;
  dias1 = emDias(dt1);
  dias2 = emDias(dt2);
  if (dias1 > dias2) {
    return dias1 - dias2;
  } else {
    return dias2 - dias1;
  }
}

int main() {
  data *d1, *d2;

  d1 = leData();
  exibeData(d1, 1);
  exibeData(d1, 2);
  exibeData(d1, 3);

  d2 = criaData(9, 3, 2020);
  printf("O intervalo das datas eh de %ld dia(s)\n", intervaloDias(d1, d2));

  return 0;
}
