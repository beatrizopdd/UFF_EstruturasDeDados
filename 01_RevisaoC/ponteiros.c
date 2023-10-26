#include <stdio.h>

int main() {

    int a = -1;
    int b = -2;
    int c = -3;
    int *ponteiro;

    printf("\nCONTEUDO DE CADA VARIAVEL\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("ponteiro: %d\n", ponteiro);

    printf("\n>> a recebe 5");
    a = 5;

    printf("\nCONTEUDO DE CADA VARIAVEL\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("ponteiro: %d\n", ponteiro);

    printf("\n>> b recebe a \n>> ponteiro recebe endereco de a");
    b = a;
    ponteiro = &a;

    printf("\nCONTEUDO DE CADA VARIAVEL\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("ponteiro: %d\n", *ponteiro);

    printf("\n>> b recebe 7 \n>> conteudo de ponteiro recebe 9");
    b = 7;
    *ponteiro = 9;

    printf("\nCONTEUDO DE CADA VARIAVEL\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("ponteiro: %d\n", *ponteiro);

    printf("\n>> c recebe o conteudo do ponteiro");
    c = *ponteiro;

    printf("\nCONTEUDO DE CADA VARIAVEL\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("ponteiro: %d\n", *ponteiro);

    printf("\nRESULTADO \n");
    printf("ponteiro   | endereco: %p | conteudo: %p | conteudo do conteudo: %d\n", &ponteiro, ponteiro, *ponteiro);
    printf("a          | endereco: %p | conteudo: %d\n", &a, a);
    printf("b          | endereco: %p | conteudo: %d\n", &b, b);
    printf("c          | endereco: %p | conteudo: %d\n", &c, c);

    return 0;
}