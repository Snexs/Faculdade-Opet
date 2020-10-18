#include <stdio.h>
#include <stdlib.h>

    int numeroInserido = 0,media = 0,contador = 0,soma = 0;
    int numeroArmazenado[];

int main(void)
    {
    Algoritimo();
    }

int Algoritimo(){
    
    printf("Digite o numero para ser calculado a media!\n");
    printf("Digite somente numeros pares serao calculados!\n");
    printf("Digite 0 para encerrar!\n");
    scanf("%d", &numeroInserido);
    
    if (numeroInserido == 0 && contador < 2)
    {
        printf("Para calcular a media deve ser inserido mais que um valor\n");
        exit(0);
    }

    if (numeroInserido == 0 && contador >= 2)
    {
        for (int i = 0; i <= contador; i++)
        {
            soma += numeroArmazenado[i];
            if (i == contador)
            {
                media = soma / contador ;
                printf("Media dos valores inseridos:%d\n",media);
                exit(0);
            }
        } 
    }

    while (numeroInserido != 0 && numeroInserido > 0)
    {
        if ((numeroInserido % 2) == 0)
        {
            numeroArmazenado[contador] = numeroInserido;
            printf("Valor inserido:%d\n",numeroInserido);
            contador++;
            Algoritimo();
        }
        else
        {
            printf("Favor inserir numero PAR!\n");
            Algoritimo();
        }
    }
}

