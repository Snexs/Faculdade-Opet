#include<stdio.h>

int main(void)
{ 
    int numeroInserido,jogo1,jogo2; 
    int tabuada = 0; 
    
    printf("Bem-Vindo ao Jogo de Matematica!!\n"); 
    printf("Digite o numero para ser calculado!:"); 
    scanf("%d", &numeroInserido); 
    printf("---------------------------------------------\n"); 
    
    jogo1 = numeroInserido; 
    
    printf("o atecessor e %d,o numero inserido e %d, o sucessor e %d\n",jogo1-1,jogo1,jogo1+1); 
    printf("---------------------------------------------\n"); tabuada = numeroInserido; 
    for (int x = 1; x<=10; x++) 
    { 
        printf("%dX%d=%d\n",x,tabuada,x*tabuada); 
    } 
    printf("---------------------------------------------\n"); 
    
    jogo2 = numeroInserido; 
    
    printf("O numero inserido e %d, o primeiro e %d,o segundo e %d,o terceiro e %d\n",jogo2,jogo2+2,jogo2+4,jogo2+6); 
    
    printf("---------------------------------------------\n"); 
    
    printf("Aperte algo para encerrar\n"); 
    system("pause"); 
}