#include <stdio.h>
#include <stdlib.h>

    int numeroInserido = 0,tabuada = 0,contador = 0;

int main(void)
    {
    Tabuada();
    }

int Tabuada(){
    
    printf("Digite um numero!\nTentativas:%d\n",contador);
    scanf("%d", &numeroInserido);

    for (int i = 0; i < 11; i++)
    {
        tabuada = numeroInserido;

        for (int x = 1; x<=numeroInserido; x++)
        {
            printf("%dX%d=%d\n",x,tabuada,x*tabuada);
        }
        contador++;
        Tabuada();
    }
}

