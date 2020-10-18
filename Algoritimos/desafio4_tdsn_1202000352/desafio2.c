#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int  valor = 0,contador = 0;
        
        printf("Digite o valor para ser descrito o numeros naturais pares\n");
        scanf("%d",&valor);

    while (contador < valor+1)
    {
        if((contador % 2) == 0)
        printf("%d\n", contador);
        contador++;
    }
    
}
