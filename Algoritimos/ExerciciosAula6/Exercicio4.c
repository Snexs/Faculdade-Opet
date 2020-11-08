#include <stdio.h>
#include <stdlib.h>
#define tam 20

int calcula(int a,int b,int c,int d,int e,int *maiorDois,int *maiorQuatro);

void main()
{
    int vetor[tam],indice;
    
    for (int i = 0; i < tam; i++)
    {
        printf("Insira um valor: ");
        scanf("%d",&indice);
        if (indice <= 0)
        {
            printf("Favor inserir um valor valido\n");
        }else
        {
            for (int ii = 0; ii < tam; ii++)
            {
               if (indice = vetor[i])
                {
                    indice  = tam;
                }else{
                    vetor[i] = indice;
                }
            }
        } 
    }
}
