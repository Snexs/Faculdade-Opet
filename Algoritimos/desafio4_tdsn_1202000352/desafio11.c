#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int  n = 0,x = 0;
        
    printf("Digite o valor de X\n");
    scanf("%d",&x);
    printf("Digite o valor de N\n");
    scanf("%d",&n);

    if(n < 0)
    printf("o valor deve ser maior que 0\n");
    
    int resultado = pow(x,n);

    printf("resultado da potencia e %d",resultado);
}