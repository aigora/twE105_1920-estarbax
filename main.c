#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Funciones.h"

#define N 6 	//cambiante  numero de malos
#define AL 24		//filas matriz
#define ANC 58		//columnas matriz




int main(){
	char x,mat1[AL][ANC]={},mat2[AL][ANC]={},mat3[AL][ANC]={},empezar;
	int cont = 0,i,n,dir,regist[N],midemapa,teclazos=0,vidas=3;
	int contador_frutas1,contador_frutas2,contador_frutas3;
	map_prop temporal;  // almacenará temporalmente lo que deuelvan las funciones loop
	_Bool final=1; //finalizar el bucle while
	FILE *pf;
	emplazamiento pos,malos1,malos2,malos3,malos4,malos5,malos6;
		
	pf = fopen("fichero.txt","r");
	if(pf == NULL)
	{
		printf("Ocurrió un error y no se pudieron cargar los mapas \n");
		exit(-1);
	}	
	
	//bucles for anidados para la asignación de cada mapa
	
	for(i=0;i<24;i++)   /// cargar primer mapa
	{
		x='v';
		for(n=0; x!='\n';n++)
		{
			x= fgetc(pf);  //este bucle for anidado asigna a nuestra matriz(24x58)vacía los elementos que hay dentro del fichero.
			if(x!='\n')
			{
				mat1[i][n]=x;	
			}			
		}
	}
	//deja el cursor justo al comienzo del segundo mapa

	for(i=0;i<24;i++) /// cargar segundo mapa
	{
		x='v';
		for(n=0; x!='\n';n++)
		{
			x= fgetc(pf);  
			if(x!='\n')
			{
				mat2[i][n]=x;	
			}			
		}
	}

	//deja el cursor justo al comienzo del tercer mapa
	
	for(i=0;i<24;i++) ///cargar tercer mapa
	{
		x='/';
		for(n=0; x!='\n';n++)
		{
			x= fgetc(pf);  
			if(x!='\n')
			{
				mat3[i][n]=x;	
			}			
		}
	}
	
	fclose(pf); //cierra el fichero	que almacena los mapas
	
	///		contador de frutas iniciales para cada uno de los mapas.
	
	contador_frutas1=contador(mat1,'o');
	contador_frutas2=contador(mat2,'o');
	contador_frutas3=contador(mat3,'o');
	
	system("color 03");	
	
	menu(1);	///////		MENÚ DE INICIO
	
 	printf("Cargando.");sleep(1);printf(".");sleep(1);printf(".");sleep(1);printf(".");sleep(1);printf(".");sleep(1);printf(".");sleep(1);printf(".");sleep(1);printf(".\n");
	printf("Solo quedan unos ultimos ajustes, espere un momento\n");sleep(4);	
	printf("Ya esta; pulse cualquiera de las teclas direccionales para empezar \n");
	
	while(!kbhit())		// bucle que se ejecutaráinfinitamente hasta que no su pulse alguna de las teclas direccionales
	{		
	}         
															
	emplazamiento vect[N]={malos1,malos2,malos3,malos4,malos5,malos6};     //se pueden añadir más malos añadiendo más varibles de tipo emplazamiento(llegó a haber 14)
	
	midemapa=0;	//empeazamos en el primer mapa
	
	int a=0,b=0,c=0,contfruta1,contfruta2,contfruta3;
	
	final=1;
	
	while(vidas!=0 && final)  // este bucle se ejecutará mientras las vidas no lleguen a 0, y mientras la variable final sea 1(esto cambiará cuando se llega al último mapa)
	{		
		switch(midemapa)
		{
			case 0:			//no te has pasado ningun mapa
				if(a==0)
				{
					for(i=0;i<N;i++)
					{
						regist[i]=1; //vector de todo  unos que indica que al principio, los malos estan posicionados sobre casillas en las que no hay frutas
					}
					pos.x=28;pos.y=19;dir=77+256;       //posición inicial del bueno
					
					vect[0].x=2;vect[0].y=6;
					vect[1].x=5;vect[1].y=6;
					vect[2].x=3;vect[2].y=6;
					vect[3].x=53;vect[3].y=6;
					vect[4].x=55;vect[4].y=6;
					vect[5].x=31;vect[5].y=15;
					
				}
				
				teclazos += loop(mat1,pos,dir,vect,0,regist,contador_frutas1,&temporal);
				
				
				  // 0 si no se paso el mapa; 1 si sí lo pasó 
				printf("Ha pulsado el teclado %d veces \n",teclazos);
				printf("Se ha comido %d frutas \n ",temporal.fruta);
				
				system("pause");
				
				
				if(temporal.nivel)
				{
					midemapa++;
				}
				
				if(midemapa==0)
				{
					vidas--;
				}				
				
				if(vidas==0)
				{
					contfruta1=temporal.fruta;
				}
				
				a++;
				
				printf("TE QUEDAN %d VIDAS \n",vidas);
				sleep(4);
				
				
				break;				
			case 1: // te has pasado el mapa 1 y estas en el 2
				
				if(b==0)
				{
					for(i=0;i<N;i++)
					{
						regist[i]=1; //vector de todo  unos que indica que al principio, los malos estan posicionados sobre casillas en las que no hay frutas
					}
					
					pos.x=28;pos.y=19;dir=77+256;       //posición inicial del buena
					
					vect[0].x=17;vect[0].y=9;
					vect[1].x=19;vect[1].y=9;
					vect[2].x=21;vect[2].y=9;
					vect[3].x=23;vect[3].y=9;
					vect[4].x=26;vect[4].y=9;
					vect[5].x=31;vect[5].y=1;
				}
				
				teclazos += loop(mat2,pos,dir,vect,0,regist,contador_frutas2,&temporal);
				  // 0 si no se paso el mapa; 1 si sí lo pasó 
				
				if(temporal.nivel)
				{
					midemapa++;
				}
				
				if(midemapa==1)
				{
					vidas--;
				}				
				
				if(vidas==0)
				{
					contfruta2=temporal.fruta;
				}
				
				b++;
				
				break;
			case 2:
				
				if(c==0)	//si es la primera vez que se carga el mapa
				{
					for(i=0;i<N;i++)
					{
						regist[i]=1; //vector de todo  unos que indica que al principio, los malos estan posicionados sobre casillas en las que no hay frutas
					}
					
					pos.x=28;pos.y=19;dir=77+256;       //posición inicial del bueno
					
					vect[0].x=32;vect[0].y=8;
					vect[1].x=34;vect[1].y=8;
					vect[2].x=36;vect[2].y=14;
					vect[3].x=24;vect[3].y=14;
					vect[4].x=27;vect[4].y=14;
					vect[5].x=29;vect[5].y=16;
				} 
				
				teclazos += loop(mat3,pos,dir,vect,0,regist,contador_frutas3,&temporal);
				  // 0 si no se paso el mapa; 1 si sí lo pasó 
				
				if(temporal.nivel)
				{
					midemapa++;
				}
				
				if(midemapa==2)
				{
					vidas-=1;
				}				
				
				if(vidas==0)
				{
					contfruta3=temporal.fruta;
				}
				
				c++;
				
				break;
			case 3:   // te has pasado el tercer y último mapa
				
				final=0;
				
				printf("Enhorabuena, te has pasado todos los mapas \n");
				
				break;
		}
		
	}

if(midemapa!=3)
{
	printf("Te quedaste sin vidas \n");
}

printf("Te has pasado %d mapas \n",midemapa);

printf("Has pulsado %d veces el teclado \n",teclazos);

switch(midemapa)
{
	case 0:
		printf("Has logrado comerte %d frutas en el mapa %d \n",contfruta1,midemapa+1);	// si se ha quedado en el mapa 1; se ha logrado comer tantas frutas
		break;
	case 1:
		printf("Has logrado comerte %d frutas en el mapa %d \n",contfruta2,midemapa+1);	// si se ha quedado en el mapa 2; se ha logrado comer tantas frutas
		break;
	case 2:
		printf("Has logrado comerte %d frutas en el mapa %d \n",contfruta3,midemapa+1);	// si se ha quedado en el mapa 3; se ha logrado comer tantas frutas
		break;
	case 3:
		printf("Al comerte toda la fruta en el %cltimo mapa, %cte has pasado el juego! \n",163,173);
		printf("Nuestras más sinceras felicitaciones \n");
		break;
}

system("pause");	
	
	
	return 0;	
}





