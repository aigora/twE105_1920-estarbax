#include "Funciones.h"

#define up 119
#define down 115
#define right 100
#define left 97




int ascii(char letra)
{
	int result;
	result=letra;
	return result;
}

void imprimirmatriz(char mat[][64])
{
	int i,n;
	for(i=0;i<32;i++)
	{
		for(n=0;n<64;n++)
		{
			printf("%c",mat[i][n]);
		}
		printf("\n");
	}
}

int rep(char matrix[][64],emplazamiento pos,char dir)
{
	char mov='r';
	int i;	
	if(dir!='q')
	{
		i=ascii(dir);
		switch(i)
		{
			case up:			
				if(matrix[pos.y-1][pos.x]!='*' && matrix[pos.y-1][pos.x]!='|' && matrix[pos.y-1][pos.x-1]!='/')
				{
					matrix[pos.y][pos.x]=' ';		
					pos.y-=1;
				}			
				break;
				
			case down:
				if(matrix[pos.y+1][pos.x]!='*' && matrix[pos.y+1][pos.x]!='|' && matrix[pos.y+1][pos.x-1]!='/')
				{
					matrix[pos.y][pos.x]=' ';
					pos.y+=1;
				}					
				break;
			case right:
				if(matrix[pos.y][pos.x+1]!='*' && matrix[pos.y][pos.x+1]!='|' && matrix[pos.y][pos.x+1]!='/')
				{
					matrix[pos.y][pos.x]=' ';
					pos.x+=1;
				}
				break;
			case left:
				if(matrix[pos.y][pos.x-1]!='*' && matrix[pos.y][pos.x-1]!='|' && matrix[pos.y][pos.x-1]!='/')
				{
					matrix[pos.y][pos.x]=' ';
					pos.x-=1;
						
				}		
				break;			
		}
		matrix[pos.y][pos.x]='D';
		system("cls");		
		imprimirmatriz(matrix);
		while(mov!='w' && mov!='s' && mov!='d' && mov!='a' && mov!='q')
		{
			mov=getch(); 		//aquí tiene que recoger la nueva tecla.
		}
		rep(matrix,pos,mov);				
	}
	else
	{
		printf("Termino el juego \n");
		return 0;		
	}	
}


