#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int  x = 0,y = 0,contador = 0;
        
        printf("Digite o valor de x\n");
        scanf("%d",&x);
        printf("Digite o valor de y\n");
        scanf("%d",&y);

    if(y > x)
    printf("o valor de y deve ser menor que x\n");
    while (y <= x)
    {
        contador = x;
        printf("%d\n",x);
        x--;
        contador--;
        
        if(contador < y)
            break;
    }    
}