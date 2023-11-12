#include <stdio.h>

void trocaSemP(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void trocaComP(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int menor = 10, maior = 6;

    trocaSemP(menor, maior);
    printf("menor = %d | maior = %d\n", menor, maior);
    trocaComP(&menor, &maior);
    printf("menor = %d | maior = %d\n", menor, maior);


    return 0;
}