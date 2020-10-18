#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trocar(char*,char*);

int main(void)
    {
        char var[100],var1[100];

        printf("Bem-Vindo ao Jogo da troca de valores!!\n");
        printf("Digite o primeiro valor para ser trocado!:");
        gets(var);        
        printf("---------------------------------------------\n");
        printf("Digite o segundo valor para ser trocado!:");
        gets(var1);
        trocar(var,var1);
        printf("---------------------------------------------\n");
        printf("Primeiro valor: %s \n" ,var);

        printf("---------------------------------------------\n");
        printf("Segundo valor: %s \n" ,var1);

        printf("---------------------------------------------\n");
        printf("Aperte algo para encerrar\n");
        system("pause");
    }

void trocar (char* var,char* var1){
    char var2[100];

    strcpy(var2,var);
    strcpy(var,var1);
    strcpy(var1,var2);

}
