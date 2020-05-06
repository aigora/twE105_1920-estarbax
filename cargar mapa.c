#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char mat[32][64]={},x;
	int cont = 0,i,n;
	FILE *pf;
	pf = fopen("fichero.txt","r");
	if(pf == NULL)
	{
		printf("No se ha podido abrir el fihero \n");
		exit(-1);
	}
	while (fscanf(pf, "%c", &x) != EOF)
	{
		if(x=='\n')
		{
			cont++;
		}
	}
	rewind(pf);
	
	for(i=0;i<cont;i++)
	{
		x='/';
		for(n=0; x!='\n';n++)
		{
			x= fgetc(pf);
			if(x!='\n')
			{
				mat[i][n]=x;	
			}			
		}
	}	
	for(i=0;i<32;i++)
	{
		for(n=0;n<64;n++)
		{
			printf("%c",mat[i][n]);
		}
		printf("\n");
	}
	fclose(pf);
	
	return 0;
	
	
	
}
