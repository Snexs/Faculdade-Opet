#include <stdio.h>

main()
{
	int dia, mes, ano;	
    printf("Digite a data:  ");
    scanf("%2d%2d%4d", &dia, &mes, &ano);
    
    if((dia>0 && dia<100) && (mes>0 && mes<100) && (ano>=1000 && ano<=9999))
    {
    	if(mes>0 && mes<=12)
		{
	    if(mes==01)
	        if(dia>0 && dia<=31)
	        	printf("\n Dia: %02d Valido\n\nMes: %02d Valido\n\nAno: %d Valido\n\nDATA VALIDA", dia, mes, ano);
	        	else
	    		printf("\nData nao Valida.");
	    if(mes==02)
	        if(dia>0 && dia<=29)
	        	if (((ano%4)==0) && ((ano%100)!=0) || ((ano% 400)==0))
	        	printf("\nDia: %02d Valido\n\nMes: %02d Valido\n\nAno: %d Valido\n\nDATA VALIDA", dia, mes, ano);
	        	else
	    		printf("\nData nao Valida.");
	    if(mes==03)
	        if(dia>0 && dia<=31)
	        	printf("\nDia: %02d Valido\n\nMes: %02d Valido\n\nAno: %d Valido\n\nDATA VALIDA", dia, mes, ano);
	        	else
	    		printf("\nData nao Valida.");
	 	if(mes==04)
	        if(dia>0 && dia<=30)
	        	printf("\nDia: %02d Valido\n\nMes: %d Valido\n\nAno: %d Valido\n\nDATA VALIDA", dia, mes, ano);
	        	else
	    		printf("\nData nao Valida.");
	    if(mes==05)
	        if(dia>0 && dia<=31)
	        	printf("\nDia: %02d Valido\n\nMes: %02d Valido\n\nAno: %d Valido\n\nDATA VALIDA", dia, mes, ano);
	        	else
	    		printf("\nData nao Valida.");
	    if(mes==06)
	        if(dia>0 && dia<=30)
	        	printf("\nDia: %02d Valido\n\nMes: %02d Valido\n\nAno: %d Valido\n\nDATA VALIDA", dia, mes, ano);
	        	else
	    		printf("\nData nao Valida.");
	    if(mes==07)
	        if(dia>0 && dia<=31)
	        	printf("\nDia: %02d Valido\n\nMes: %02d Valido\n\nAno: %d Valido\n\nDATA VALIDA", dia, mes, ano);
	        	else
	    		printf("\nData nao Valida.");
	    if(mes==8)
	        if(dia>0 && dia<=31)
	        	printf("\nDia: %02d Valido\n\nMes: %02d Valido\n\nAno: %d Valido\n\nDATA VALIDA", dia, mes, ano);
	        	else
	    		printf("\nData nao Valida.");
	    if(mes == 9 )
	        if(dia>0 && dia<=30)
	        	printf("\nDia: %02d Valido\n\nMes: %02d Valido\n\nAno: %d Valido\n\nDATA VALIDA", dia, mes, ano);
	        	else
	    		printf("\nData nao Valida.");
	    if(mes==10)
	        if(dia>0 && dia<=31)
	        	printf("\nDia: %02d Valido\n\nMes: %d Valido\n\nAno: %d Valido\n\nDATA VALIDA", dia, mes, ano);
	    		else
	    		printf("\nData nao Valida.");
		if(mes==11)
	        if(dia>0 && dia<=30)
	        	printf("\nDia: %02d Valido\n\nMes: %d Valido\n\nAno: %d Valido\n\nDATA VALIDA", dia, mes, ano);
				else
	    		printf("\nData nao Valida.");
	    if(mes==12)
	        if(dia>0 && dia<=31)
	        	printf("\nDia: %02d Valido\n\nMes: %d Valido\n\nAno: %d Valido\n\nDATA VALIDA", dia, mes, ano);   
				else
	    		printf("\nData nao Valida!");
		}
		else
			printf("\nData Invalida!");
	}
	else
		printf("\nDigito Invalido!");	
}
