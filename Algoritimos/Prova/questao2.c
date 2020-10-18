#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num, i, resultado = 0;
 
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    if (num == 0 || num == 1)
    {
        printf("%d nao e primo nem composto\n",num);
        exit(0);
    }

    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
        resultado++;
        break;
        }
    }
    
    if (resultado == 0)
        printf("%d e um numero primo\n", num);
    else
        if (resultado != 0 || resultado != 1)
            printf("%d e um numero composto\n", num);
}