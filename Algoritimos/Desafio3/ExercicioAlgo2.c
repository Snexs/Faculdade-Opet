#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int  maior = 0,menor = 99999;
    int  valor = 1;

    while (valor != 0)
    {
       printf("Digite o valor para ser verificado\n");
       scanf("%d",&valor);

       if (valor > maior)
       {
           maior = valor;
       }
       if (valor < menor && valor != 0)
       {
           menor = valor;
       }
    }
    printf("O maior valor digitado foi: %d\n O menor valor digitado foi: %d\n", maior, menor);
}
