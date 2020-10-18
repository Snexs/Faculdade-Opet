#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int meses = 12;
    float juros,valorInvestido,valorTotal;
    juros = 1.1;
    printf("Digite o valor a ser aplicado: ");
    scanf("%f", &valorInvestido);

    printf("Digite o valor do juros esta a: %d%%\n",juros);

    for (int i = 0; i <= meses; i++)
    {
        valorTotal = valorInvestido * juros;
        printf("Mes %d ,O valor investido %f com os rendimentos ficou %f\n",i,valorInvestido,valorTotal);
        if (i == meses)
        {
            valorTotal = (valorInvestido * juros) * 12;
            printf("O valor total de rendimentos %f\n",valorTotal);
        }
        
    }
}