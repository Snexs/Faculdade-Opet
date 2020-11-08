#include <stdio.h>
#include <stdlib.h>

int calcula(int valor1,int valor2,int *quo,int *resto);

void main()
{
    int valor1,valor2,quo,resto,resultado;
    
    printf("Digite o primeiro valor: ");
    scanf("%d", &valor1);

    printf("Digite o segundo valor: ");
    scanf("%d", &valor2);

    resultado = calcula(valor1, valor2,&quo,&resto);
    
    if(resultado == 0)
    {
        printf("O quociente e: %d\n",quo);
        printf("O resto e: %d\n",resto);
    }else{
        printf("Impossivel efetuar essa divisao\n");
    }
    
}

int calcula(int valor1,int valor2,int *quo,int *resto)
{
    if(valor2 <= 0)
    {
        return -1;
    }else
    {
        *quo = valor1 / valor2;
        *resto = valor1 % valor2;
        return 0;
    }
}