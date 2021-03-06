#include "Funciones.h"

#define N 6 	//cambiante  numero de malos
#define AL 24		//filas matriz
#define ANC 58		//columnas matriz




int main(){
	char x,mat1[AL][ANC]={},mat2[AL][ANC]={},mat3[AL][ANC]={};
	int i,n,dir,regist[N],midemapa,teclazos=0,vidas=3;
	int contador_frutas1,contador_frutas2,contador_frutas3,u=0;
	map_prop temporal;  // almacenará temporalmente lo que devuelvan las funciones loop
	_Bool final=1;//finalizar el bucle while
	FILE *pf, *pc;
	emplazamiento pos,malos1,malos2,malos3,malos4,malos5,malos6;	//si se quieren más malos, añadir más variables de malos
    usuario sesion;
		
	pf = fopen("fichero.txt","r");
	if(pf == NULL)
	{
		printf("Tuvo lugar un error y no se pudieron cargar los mapas \n");
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
	
	menu(1);	///////		MENU DE INICIO
	
	printf("Escriba su nombre. Tenga en cuenta que si juega con un nombre que ya se ha usado se actualizara atutomaticamente \nsu puntuacion en la clasificacion si se diera el caso de que fuera mayor la que consiguiese \n");
	do
	{
		if(u!=0)
		{
			printf("Ha escrito un nombre demasiado largo, tiene que ocupar menos de 20 caracteres\n");
			printf("Pruebe otra vez\n");
		}
		scanf("%s", sesion.nombre);
		
		u++;
	}while(strlen(sesion.nombre)>20);
	
	printf("Hola %s\n",sesion.nombre);
		
	printf("Ya esta; pulse una tecla para empezar \n");
	
	x=getch();        
															
	emplazamiento vect[N]={malos1,malos2,malos3,malos4,malos5,malos6};     //se pueden añadir más malos añadiendo más varibles de tipo emplazamiento(llegó a haber 14)
	
	midemapa=0;	//empezamos en el primer mapa
	
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
					
					vect[0].x=24;vect[0].y=17;
					vect[1].x=37;vect[1].y=17;
					vect[2].x=30;vect[2].y=8;
					vect[3].x=13;vect[3].y=4;
					vect[4].x=51;vect[4].y=4;
					vect[5].x=50;vect[5].y=21;
					
				}
				
				teclazos += loop(mat1,pos,dir,vect,0,regist,contador_frutas1,&temporal);
				
				
				  // 0 si no se paso el mapa; 1 si sí lo pasó
				printf("Ha pulsado el teclado %d veces \n",teclazos);
				printf("Se ha comido %d frutas \n ",temporal.fruta);
				
				
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
				
				printf("VIDAS RESTANTES: %d \n",vidas);
				
				printf("Introduca cualquier caracter para continuar\n");
				scanf(" %c",&x);
				
				
				break;				
			case 1: // te has pasado el mapa 1 y estas en el 2
				
				if(b==0)
				{
					for(i=0;i<N;i++)
					{
						regist[i]=1; //vector de todo  unos que indica que al principio, los malos estan posicionados sobre casillas en las que no hay frutas
					}
					
					pos.x=29;pos.y=12;dir=80+256;       //posición inicial del bueno
					
					vect[0].x=15;vect[0].y=7;
					vect[1].x=45;vect[1].y=7;
					vect[2].x=16;vect[2].y=16;
					vect[3].x=44;vect[3].y=16;
					vect[4].x=30;vect[4].y=22;
					vect[5].x=30;vect[5].y=1;
				}
				
				teclazos += loop(mat2,pos,dir,vect,0,regist,contador_frutas2,&temporal);
				  // 0 si no se paso el mapa; 1 si sí lo pasó
				  
				printf("Ha pulsado el teclado %d veces \n",teclazos);
				printf("Se ha comido %d frutas \n ",temporal.fruta);
				
				
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
				
				printf("VIDAS RESTANTES: %d \n",vidas);
				
				printf("Introduca cualquier caracter para continuar\n");
				scanf(" %c",&x);
				
				break;
			case 2:
				
				if(c==0)	//si es la primera vez que se carga el mapa
				{
					for(i=0;i<N;i++)
					{
						regist[i]=1; //vector de todo  unos que indica que al principio, los malos estan posicionados sobre casillas en las que no hay frutas
					}
					
					pos.x=28;pos.y=14;dir=77+256;       //posición inicial del bueno
					
					vect[0].x=32;vect[0].y=8;
					vect[1].x=34;vect[1].y=8;
					vect[2].x=7;vect[2].y=10;
					vect[3].x=50;vect[3].y=12;
					vect[4].x=47;vect[4].y=18;
					vect[5].x=16;vect[5].y=20;
				} 
				
				teclazos += loop(mat3,pos,dir,vect,0,regist,contador_frutas3,&temporal);
				  // 0 si no se paso el mapa; 1 si sí lo pasó
				  
				printf("Ha pulsado el teclado %d veces \n",teclazos);
				printf("Se ha comido %d frutas \n ",temporal.fruta);
				
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
				
				printf("VIDAS RESTANTES: %d \n",vidas);
				
				printf("Introduca cualquier caracter para continuar\n");
				scanf(" %c",&x);
				
				break;
			case 3:   // te has pasado el tercer y Ãºltimo mapa
				
				final=0;
				
				printf("Enhorabuena, te has pasado todos los mapas \n");
				
				break;
		}
		
	}

if(midemapa!=3)
{
	printf("Te quedaste sin vidas \n");
}

printf("Numero de mapas superados: %d \n",midemapa);

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
		printf("Nuestras mas sinceras felicitaciones \n");
		break;
}

    printf("pulse cualquier tecla para consultar la clasificaci%n \n",162);
    getch();
    
    
    int puntos=0; //puntos al principio del juego
    const int puntmap= 50000; // puntos que se obtienen al avanzar de mapa
    
    if (midemapa==0)
    {
        puntos=50*contfruta1;
    }
    else if (midemapa==1)
    {
        if (teclazos<=150)
        {
            puntos=500*contfruta1 + puntmap - 10*teclazos;
        }
        else if (teclazos>150 && teclazos<=250)
        {
            puntos=200*contfruta1 + puntmap - 10*teclazos;
        }
        else if (teclazos>250 && teclazos<=350)
        {
            puntos= 150*contfruta1 + puntmap - 10*teclazos;
        }
        else if (teclazos>350 && teclazos<=500)
        {
            puntos=100*contfruta1 + puntmap - 10*teclazos;
        }
        else
        {
            puntos= puntmap - 10*teclazos;
        }
    }
    
    else if(midemapa==2)
    {
        if (teclazos<=300)
        {
            puntos=500*contfruta1 + 500*contfruta2 + 2*puntmap - 10*teclazos;
        }
        else if (teclazos>300 && teclazos<=500)
        {
            puntos=200*contfruta1 + 200*contfruta2 + 2*puntmap - 10*teclazos;
        }
        else if (teclazos>500 && teclazos<=700)
        {
            puntos=150*contfruta1 + 150*contfruta2 + 2*puntmap - 10*teclazos;
        }
        else if (teclazos>700 && teclazos<=1000)
        {
            puntos=100*contfruta1 + 100*contfruta2  + 2*puntmap - 10*teclazos;
        }
        else
        {
        puntos=2*puntmap - 10*teclazos;
        }
    }
    else
    {
        if (teclazos<=450)
        {
            puntos=500*contfruta1 + 500*contfruta2 + 500*contfruta3 + 3*puntmap - 10*teclazos;
        }
        else if (teclazos>450 && teclazos<=750)
        {
            puntos=200*contfruta1 + 200*contfruta2 + 200*contfruta3 + 3*puntmap - 10*teclazos;
        }
        else if (teclazos>750 && teclazos<=1050)
        {
            puntos=150*contfruta1 + 150*contfruta2 + 150*contfruta3 + 3*puntmap - 10*teclazos;
        }
        else if (teclazos>1050 && teclazos<=1500)
        {
            puntos=100*contfruta1 + 100*contfruta2 + 100*contfruta3 + 3*puntmap - 10*teclazos;
        }
        else
        {
            puntos=3*puntmap - 10*teclazos;
        }
    }
    

    int v,cuantosJugadores=0,indiferente; //declaro la u arriba
    char r;
    
    sesion.puntuacion=puntos;
    
    pc=fopen("Clasificacion.txt", "r");
    if(pc==NULL)
    {
        printf("No se ha podido abrir fichero\n");
        exit (-1);
    }
   
    while (fscanf(pc,"%c",&r)!=EOF)
    {
        if(r=='\n') //contamos el numero de lineas del fichero 
        {
        	cuantosJugadores++;
	}            
    }   

    cuantosJugadores--;	//hay que restar una debido a que en el fichero hay un salto de lÃ­nea de mÃ¡s
	
    usuario jugador[cuantosJugadores+1],alm;
    rewind(pc);
    
    for(u=0;u<cuantosJugadores;u++) 
    {
        fscanf(pc,"#%i|%[^,],puntuacion:%i\n",&indiferente,jugador[u].nombre,&jugador[u].puntuacion);
    }
    fclose(pc);
    
    
    int indicador=0;    //con este indicador sabremos si hay alguna partida registrada con el mismo nombre
    
    for(u=0;u<cuantosJugadores;u++)
    {
        if(strcmp(sesion.nombre,jugador[u].nombre)==0)
        {
            indicador=1;
            if(puntos > jugador[u].puntuacion)
            {
                jugador[u]=sesion;
            }            
        }
    }
    
   if(indicador==0)	//si no hay ninguna partida registrada con el mismo nombre
   {
		strcpy(jugador[cuantosJugadores].nombre,sesion.nombre);	//la variable sesiÃ³n de tipo usuario pasa al Ãºltimo elemento(vacÃ­o)del vector 'jugador'
		jugador[cuantosJugadores].puntuacion=sesion.puntuacion;      
   }
        
    
    switch(indicador)
    {
        case 0:
            for(u=0;u<cuantosJugadores+1;u++)
               {
                   for(v=u+1;v<cuantosJugadores+1;v++)
                   {
                       if(jugador[u].puntuacion < jugador[v].puntuacion)                       
                       {
	                       alm=jugador[u];
	                       jugador[u]=jugador[v];
	                       jugador[v]=alm;
                       }
                   }
               }
               
               
            break;
        case 1:
            for(u=0;u<cuantosJugadores;u++)
               {
                   for(v=u+1;v<cuantosJugadores;v++)
                   {
                       if(jugador[u].puntuacion < jugador[v].puntuacion)
                       
                       {
	                       alm=jugador[u];
	                       jugador[u]=jugador[v];
	                       jugador[v]=alm;
                       }
                   }
               }               
            break;
    }
    
    pc=fopen("Clasificacion.txt","w");
    switch(indicador)
    {
        case 0:
            
              for(u=0;u<cuantosJugadores+1;u++)
              {
                  fprintf(pc,"#%i|%s,puntuacion:%i\n",u+1,jugador[u].nombre,jugador[u].puntuacion);
		  if(u==cuantosJugadores)
                  {
                  	fprintf(pc,"\n");
		  }
              }
              
            break;
        case 1:
            for(u=0;u<cuantosJugadores;u++)
            {
                fprintf(pc,"#%i|%s,puntuacion:%i\n",u+1,jugador[u].nombre,jugador[u].puntuacion);
		if(u+1==cuantosJugadores)
                {
                	fprintf(pc,"\n");
		}
            }
            
            break;
    }
    fclose(pc);
    
    pc=fopen("Clasificacion.txt","r");
	
    if(pc==NULL)
    {
	printf("No se pudo abrir el fichero \n");
	exit(-1);
	}
	u=0;
	while(fscanf(pc,"%c",&r)!=EOF)
	{
		u++;	//contar cuantos caracteres hay en el fichero clasificación
	}
	char micadena[u];	//declarar una cadena tan larga como el número de caracteres existentes
	strcpy(micadena,"");	//la cadena empieza estando vacía
	u=0;
	rewind(pc);		//retornamos el puntero al principio del fichero
	while(fscanf(pc,"%c",&r)!=EOF)
	{
		micadena[u]=r;		//rellenamos nuestra cadena con los caracteres que haya dentro del fichero
		u++;
	}
	borrar();		//borramos la pantalla
	printf("ESTA ES LA CLASIFICACI%cN\n",224);
	printf("\n");
	printf("%s\n",micadena);	//mostramos la clasificación por pantalla
	printf("Gracias por jugar\n");
	
	
	return 0;	
}







