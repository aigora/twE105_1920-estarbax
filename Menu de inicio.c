#include <stdio.h>
#include <string.h>

//Menu de inicio


void main()
{
	char n[60];
	int i;
	printf("¿Que desea hacer? \n");
	printf("-Si quiere jugar pulse 1 \n-Si quiere acceder a las instrucciones pulse 2 \n-Si quiere salir pulse 3 \n");
	do
	{
		printf("Recuerda que solo puede introducir 1,2, o 3 \n");
		scanf("%s",n);
		i=strlen(n);
	}
	while((i!=1) || (n[0]<48 || n[0]>57) || (n[0]!=49 && n[0]!=50 && n[0]!=51));
	switch(n[0])
	{
		case '1':
			printf("Inicia el juego \n");
			break;
		case '2':
			printf("Accede a las instrucciones \n");
			break;
		case '3':
			printf("Salir \n");
			break;
	}
}
