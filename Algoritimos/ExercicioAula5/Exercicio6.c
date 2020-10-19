#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float CalculaIdadeDias(int anos,int meses,int dias){
    
    float resultado;

    resultado = (anos * 365) +  (meses * 30.417) + dias;

    return resultado;
}

int main(){
    
    int anos,meses,dias;
    float resultado;

    printf("Digite o valor da idade em anos: ");
    scanf("%d",&anos);

    printf("Digite o valor da idade em meses: ");
    scanf("%d",&meses);

    printf("Digite o valor da idade em dias: ");
    scanf("%d",&dias);


    resultado = CalculaIdadeDias(anos,meses,dias);

    printf("sua idade em dias : %f",resultado);
}
