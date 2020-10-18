#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int anoADescobrir = 0,g,c,x,z,e,n,d;
    
    printf("Digite o ano para descobrir a data da pascoa: ");
    scanf("%d", &anoADescobrir);

    g = (anoADescobrir % 19) + 1;

    c = (anoADescobrir/100) + 1;

    x = ((3 * c) / 4) - 12;

    z = (((8 * c) + 5) / 25) -5;

    e = ((11 * g) + 20 + z - x) % 30;

    if (e == 25 && g > 11 || e == 24)
    {
        e++;
    }
    
    n = 44 - e;

    if (n < 21)
    {
        n = n + 30;
    }
    
    d = ((5 * anoADescobrir) / 4) - (x + 10);

    n = (n + 7) - ((d + n) % 7);

    if (n > 31)
    {
        n = n - 31;
        printf("A pascoa sera do dia %d de abril de %d\n",n,anoADescobrir);
    }
    else
    {
        printf("A pascoa sera do dia %d de marco de %d\n",n,anoADescobrir);
    }
    
}