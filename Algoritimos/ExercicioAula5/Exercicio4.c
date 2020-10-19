#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

double Baskara(int a,int b,int c){
    double delta,raizes[2],result;

    delta = ((4 * a) * c) - (b * b);

    printf("delta e %lf\n",delta);

    if(delta < 0)
    {
        printf("a equacao nao possui raizes");
        exit(1);
    }
    raizes[0] = ((-b) - sqrt(delta)) / (2 * a);
    raizes[1] = ((-b) + sqrt(delta)) / (2 * a);

    return raizes[2];   
}

int main(){
    
    int a,b,c;
    double Resultado[2];

    printf("Digite um numero: ");
    scanf("%d",&a);

    printf("Digite um numero: ");
    scanf("%d",&b);

    printf("Digite um numero: ");
    scanf("%d",&c);

    Resultado[2] = Baskara(a,b,c);

    printf("as raizes sao: %lf e %lf",Resultado[0],Resultado[1]);
}
