#include <stdio.h>

int main() {

char produtoA[30] = "Produto A";
char produtoB[30] = "Produto B";

unsigned int estoqueA = 1000;
unsigned int estoqueB = 2000;

float precoA = 10.50f;
float precoB = 20.40f;

unsigned int estoqueMinimoA = 500;
unsigned int estoqueMinimob = 2500;

double valorTotalA;
double valorTotalB;

int resultadoA, resultadoB;


printf("Produto %s tem estoque %u e o valor unitario é R$ %.2f\n", produtoA, estoqueA, precoA);
printf("Produto %s tem estoque %u e o valor unitario é R$ %.2f\n", produtoB, estoqueB, precoB);

resultadoA = estoqueA > estoqueMinimoA;
resultadoB = estoqueB > estoqueMinimob;

printf("O produto %s tem estoque minimo %d\n", produtoA, resultadoA);
printf("O produto %s tem estoque minimo %d\n", produtoB, resultadoB);

printf("valor total de A (R$ %f) é maior que valor total de B (R$ %f): %d\n", estoqueA * precoA, estoqueB * precoB, (estoqueA * precoA) > (estoqueB * precoB));



    return 0;
}