#include <stdio.h>
#include <stdlib.h>

int main(void)
    {
        float var,var1,var2;

        printf("Bem-Vindo ao Repetidor de Numeros!!\n");
        printf("Digite o primeiro numero para ser repetido!:");
        scanf("%f", &var);        

        printf("---------------------------------------------\n");
        printf("Digite o segundo numero para ser repetido!:");
        scanf("%f", &var1);

        printf("---------------------------------------------\n");
        printf("Digite o terceiro numero para ser repetido!:");
        scanf("%f", &var2);

        printf("---------------------------------------------\n");
        printf("Primeiro valor informado: %f \n" ,var);

        printf("---------------------------------------------\n");
        printf("Segundo valor informado: %f \n" ,var1);

        printf("---------------------------------------------\n");
        printf("Terceiro valor informado: %f \n" ,var2);

        printf("---------------------------------------------\n");
        printf("Aperte algo para encerrar\n");
        system("pause");
    }

