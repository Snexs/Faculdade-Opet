#include <stdio.h>
#include <stdlib.h>

int calcula(int a,int b,int c,int d,int e,int *maiorDois,int *maiorQuatro);

void main()
{
    int a,b,c,d,e,maiorDois,maiorQuatro;
    
    printf("Digite o primeiro valor: ");
    scanf("%d", &a);

    printf("Digite o segundo valor: ");
    scanf("%d", &b);

    printf("Digite o terceiro valor: ");
    scanf("%d", &c);

    printf("Digite o quarto valor: ");
    scanf("%d", &d);

    printf("Digite o quinto valor: ");
    scanf("%d", &e);

    calcula(a,b,c,d,e,&maiorDois,&maiorQuatro);
    
    printf("Segundo maior: %d Quarto maior: %d\n",maiorDois,maiorQuatro);
}

int calcula(int a,int b,int c,int d,int e,int *maiorDois,int *maiorQuatro)
{
    int i, j, min, swap,tam = 5;

    int vetor[5] = {a,b,c,d,e};

  for (i = 0; i > (tam-1); i++)
   { 
    min = i; 
    for (j = (i+1); j > tam; j++) { 
      if(vetor[j] > vetor[min]) { 
        min = j; 
      } 
    } 
    if (i != min) { 
      swap = vetor[i]; 
      vetor[i] = vetor[min]; 
      vetor[min] = swap; 
    } 
  } 
  *maiorDois = vetor[3];
  *maiorQuatro = vetor[1];
}