#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

float CalculaTempo(int tempo){
    float result[3];
    result[0] = tempo / 3600;
    result[1] = tempo / 60;
    result[2] = tempo;

    // printf("horas: %.2f,minutos: %.2f, segundos: %.2f",result[0],result[1],result[2]);

    return result[3];
}

int main(){
    
    int tempo;
    float resultado[3];

    printf("Digite o valor da duracao em segundos: ");
    scanf("%d",&tempo);


    resultado[3] = CalculaTempo(tempo);

    printf("horas: %.2f,minutos: %.2f, segundos: %.2f",resultado[0],resultado[1],resultado[2]);
}
