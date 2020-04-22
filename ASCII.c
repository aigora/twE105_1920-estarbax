#include <stdio.h>

int ascii(char letra);

int main(){
	char letra;
	int res;
	scanf(" %c",&letra);
	res=ascii(letra);
	
	printf("%d",res);
	
	return 0;
	
}

int ascii(char letra)
{
	int result;
	result=letra;
	return result;
}
