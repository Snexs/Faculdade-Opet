#include<stdio.h>

float valores[3],aux,digitado;
int i,j;

int exibir()
{
    for (i = 0; i < 3; i++)
    {
        printf("%.2f\n",valores[i]);    
    } 
}

int classificar()
{
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (valores[i] > valores[j])
            {
                aux = valores[j];
                valores[j] = valores[i];
                valores[i] = aux;
            }
        }
    }
}

int main()
{
  for (i = 0; i < 3; i++)
  {
      printf("digite o %do numero\n", i+1);
      scanf("%f", &digitado);
      valores[i] = digitado;
  }
    classificar();
    exibir();
}