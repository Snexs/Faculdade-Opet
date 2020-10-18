#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int  tabuada = 0,n = 0,contador = 0,m = 0;
        
    printf("Digite o valor do inicio do intertvalo para calcular a tabuada\n");
    scanf("%d",&n);
    printf("Digite o valor do fim do intertvalo para calcular a tabuada\n");
    scanf("%d",&m);

    if(n < 0 && m < 0)
    printf("o valor deve ser maior que 0\n");
    
    while (contador <= m)
    {
        tabuada = n;
        for (int x = 1; x<=10; x++)
        {
        printf("%dX%d=%d\n",x,tabuada,x*tabuada);
        }
        n++;

        if(n > m)
            break;
    }
}