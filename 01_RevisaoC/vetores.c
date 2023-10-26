#include <stdio.h>
#include <stdlib.h>

int main() {

    char vogais[5];
    vogais[0] = 'a';
    vogais[1] = 'e';
    vogais[2] = 'i';
    vogais[3] = 'o';
    vogais[4] = 'u';

    for (int i = 0; i < 5; i++)
        printf("%c ", vogais[i]);


    printf("\n");
    char *consoantes = (char*)malloc(sizeof(char) * 5);
    consoantes[0] = 'b';
    consoantes[1] = 'f';
    consoantes[2] = 'j';
    consoantes[3] = 'p';
    consoantes[4] = 'v';

    for (int i = 0; i < 5; i++)
        printf("%c ", consoantes[i]);

    free(consoantes);

    return 0;
}