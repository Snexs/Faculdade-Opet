#include <stdio.h>
#include <stdlib.h>

float calculaVolume(float);

void main()
{
    float raio = 0,volume;
    
    printf("Digite o raio da circunferencia: ");
    scanf("%f", &raio);

    volume = calculaVolume(raio);

    printf("o volume dessa circunferencia e: %f",volume);
}

float calculaVolume(float raio)
{
    const float Pi = 3.14159265359;
    float volume;

    volume = 4 / (3 * Pi * raio * 3);
    
    return volume; 
}