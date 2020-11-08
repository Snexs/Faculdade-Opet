#include <stdio.h>
#include <stdlib.h>

float calculaMaior(float *valor1,float *valor2,float *valor3);
float calculaMenor(float *v1,float *v2,float *v3);

void main()
{
    float valor1,valor2,valor3,maior,menor,v1,v2,v3;
    
    printf("Digite o primeiro valor: ");
    scanf("%f", &valor1);

    printf("Digite o segundo valor: ");
    scanf("%f", &valor2);

    printf("Digite o terceiro valor: ");
    scanf("%f", &valor3);

    v1 = valor1;
    v2 = valor2;
    v3 = valor3;

    maior = calculaMaior(&valor1, &valor2, &valor3);
    menor = calculaMenor(&v1, &v2, &v3);

    printf("O Maior valor e: %f",maior);
    printf("O Menor valor e: %f",menor);
}

float calculaMaior(float *valor1,float *valor2,float *valor3)
{
    if(*valor1 > *valor2 && *valor1 > *valor3)    
        return *valor1;

    if(*valor2 > *valor3 && *valor2 > *valor1)    
        return *valor2;

    if(*valor3 > *valor2 && *valor3 > *valor2)    
        return *valor3;
     
}

float calculaMenor(float *v1,float *v2,float *v3)
{
    if(*v1 < *v2 && *v1 < *v3)    
        return *v1;

    if(*v2 < *v3 && *v2 < *v1)    
        return *v2;

    if(*v3 < *v2 && *v3 < *v1)    
        return *v3;
}