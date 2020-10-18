#include <stdio.h>
#include <stdlib.h>

int main(void)
    {
        char name[100],adress[100],phone[13];
        int validation;

        printf("Bem-Vindo ao Sistema de Cadastro!!\n");
        printf("Digite o seu nome completo:");
        gets(name);        

        printf("---------------------------------------------\n");
        printf("Digite o endereco completo:");
        gets(adress);

        printf("---------------------------------------------\n");
        printf("Digite o seu telefone(Ex.: 41999999999)!:");
        gets(phone);

        printf("---------------------------------------------\n");
        printf("Dados informados: %s, %s, %s\n" ,name,adress,phone);

        printf("---------------------------------------------\n");
        printf("Para confirmar pressione [1], para preencher novamente pressione [0]\n");
        scanf("%d" , &validation);
        if (validation == 1)
        {
            printf("Dados cadastrados com sucesso!!\n");
        }else
        {
            printf("Preencha novamente os dados!!\n");
        }
    }
