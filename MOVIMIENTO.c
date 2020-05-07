#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define up 38
#define down 40
#define right 39
#define left 37


void movi(char mov);
void rep();
int ascii(char letra);

int main(){
	
	rep();
		
	return 0;
		
}

int ascii(char letra)
{
	int result;
	result=letra;
	return result;
}

void movi(char mov)
{
	int x=1,y=1,i;
	printf(".");
	i=ascii(mov);
	
	switch(i)
	{
		case up:
			y++;
			gotoxy(x,y);	
			printf(".");	
			gotoxy(x,y-1);
			printf(" ");
			break;
			
		case down:
			y--;
			if(y==0)
			{
				y=1;
			}
			else
			{
				gotoxy(x,y);
				printf(".");	
				gotoxy(x,y+1);
				printf(" ");
			}					
			break;
		case right:
			x++;
			gotoxy(x,y);
			printf(".");
			gotoxy(x-1,y);
			printf(" ");
			break;
		case left:
			x--;
			if(x==0)
			{
				x=1;
			}
			else
			{
				gotoxy(x,y);
				printf(".");
				gotoxy(x+1,y);
				printf(" ");
			}			
			break;
		
	}
	
	
}

void rep()
{
	char mov;
	
	do
	{
		scanf(" %c",&mov);	
		movi(mov);
	}
	while(mov!='q');
}


