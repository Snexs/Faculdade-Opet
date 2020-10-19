#include <stdio.h>
#include <stdlib.h>

float calculaMedia(float,float,float,char[2]);

void main()
{
    float nota,nota2,nota3,media;
    char letra[2];

    printf("Digite a primeira nota: ");
    scanf("%f", &nota);

    printf("Digite a primeira nota: ");
    scanf("%f", &nota2);

    printf("Digite a primeira nota: ");
    scanf("%f", &nota3);

    printf("Digite uma letra para calcular a media: ");
    printf("A - Media Aritimetica: ");
    printf("P - Media Ponderada: ");
    printf("H - Harmonica: ");
    scanf("%s", &letra);
    
    media = calculaMedia(nota,nota2,nota3,letra);

    printf("A media %s e: %f",letra,media);
}

float calculaMedia(float nota,float nota2,float nota3,char*letra)
{
    float media;

    if(letra == "A" || letra  == "a")
        media = (nota + nota2 + nota3) / 3;

    if(letra == "P" || letra  == "p")
        media = ((nota * 5) + (nota2 * 3) + (nota3 * 2)) / (5 + 3 + 2);

    if(letra == "H" || letra  == "h")
        media = (3/((1/nota)+(1/nota2)+(1/nota3)));
}
