#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int  tabuada = 0,inserido = 0;
        
    printf("Digite o valor para calcular a tabuada\n");
    scanf("%d",&inserido);

    if(inserido < 0)
    printf("o valor deve ser maior que 0,%d\n",inserido);
    
    tabuada = inserido;

    for (int x = 1; x<=10; x++)
    {
        printf("%dX%d=%d\n",x,tabuada,x*tabuada);
    }
}