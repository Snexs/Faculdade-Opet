#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int  valor = 0,contador = 0,soma = 0;
        
        printf("Digite o valor para calcular os numeros ate o valor digitado\n");
        scanf("%d",&valor);

    while (contador < valor+1)
    {
        printf("calculando...\n");
        soma = soma + contador;
        contador++;
    }

    printf("O valor total da soma e %d\n",soma);
    
}
