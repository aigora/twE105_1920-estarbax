#include <stdio.h>
// funci�n para ir a una posici�n determinada

void gotoxy(int x,int y);

main ()
{
gotoxy(4,40); //reposicionar cursor
printf("hello world"); //muestra el texto donde hab�amos dicho
}

//inconvenientes: -la funci�n considera el (1,1), no en la esquina superior izq, sino en la posici�n donde se encuentra el cursor al justo cuando se ejecuta la funci�n; 
// 					si la funci�n gotoxy(x,y) es la primera sentencia que aparece en el main(la primera intrucci�n que le damos a nuestro programa), el (1,1) ser� la esquina superior izq.

 //				  - Todo lo que hay entre el (1,1) y nuestra (x,y), ser� espacio en blanco.
 


// Eso es principalmente lo que hay que arreglar.

void gotoxy(int x,int y)
{
	int i,n;
	for(i=1;i<=x;i++)
	{
		for(n=1;n<=y;n++)
		{
			if(i==x && n==y-1)
			{
				printf(" ");
			}
			else
			{
				printf(" ");
			}
		}
		if(i!=x)
			printf("\n");
	}
}
