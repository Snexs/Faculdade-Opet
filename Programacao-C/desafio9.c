#include<stdio.h>

int main (void)
{
  int i,j;
  float vetor[3],matriz[3][2];
  // j == coluna i == linha
  printf ("\nDigite valor para os elementos da matriz\n\n");
  
  for ( i=0; i<3; i++ )
    for ( j=0; j<2; j++ )
    {
      printf ("\nPreco[%d][%d] = ", i, j);
      scanf ("%f", &matriz[ i ][ j ]);
    }
  
  printf("\n\n******************* Saida de Dados ********************* \n\n");
  
    vetor[0] = (matriz[0][0] + matriz[0][1])  / 2;
    vetor[1] = (matriz[1][0] + matriz[1][1]) / 2;
    vetor[2] = (matriz[2][0] + matriz[2][1]) / 2;
    
    for ( i=0; i<3; i++ )
        printf("[%.2f]",vetor[i]);

  return(0);
}