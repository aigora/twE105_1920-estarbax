#include "Funciones.h"

#define N 6 	//cambiante  numero de malos
#define AL 24		//filas matriz
#define ANC 58		//columnas matriz




int main(){
	char x,mat1[AL][ANC]={},mat2[AL][ANC]={},mat3[AL][ANC]={},empezar;
	int cont = 0,i,n,dir,regist[N],midemapa,teclazos=0,vidas=3;
	int contador_frutas1,contador_frutas2,contador_frutas3,u=0;
	map_prop temporal;  // almacenar� temporalmente lo que devuelvan las funciones loop
	_Bool final=1;//finalizar el bucle while
	FILE *pf, *pc;
	emplazamiento pos,malos1,malos2,malos3,malos4,malos5,malos6;	//si se quieren m�s malos, a�adir m�s variables de malos
    usuario sesion;
		
	pf = fopen("fichero.txt","r");
	if(pf == NULL)
	{
		printf("Tuvo lugar un error y no se pudieron cargar los mapas \n");
		exit(-1);
	}	
	
	//bucles for anidados para la asignaci�n de cada mapa
	
	for(i=0;i<24;i++)   /// cargar primer mapa
	{
		x='v';
		for(n=0; x!='\n';n++)
		{
			x= fgetc(pf);  //este bucle for anidado asigna a nuestra matriz(24x58)vac�a los elementos que hay dentro del fichero.
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
	
 	printf("Cargando.");sleep(1);printf(".");sleep(1);printf(".");sleep(1);printf(".");sleep(1);printf(".");sleep(1);printf(".");sleep(1);printf(".");sleep(1);printf(".\n");
	printf("Solo quedan unos ultimos ajustes, espere un momento\n");sleep(3);	
	printf("Ya esta; pulse cualquiera de las teclas direccionales para empezar \n");
	
	while(!kbhit())		// bucle que se ejecutara infinitamente hasta que no su pulse alguna de las teclas direccionales
	{		
	}         
															
	emplazamiento vect[N]={malos1,malos2,malos3,malos4,malos5,malos6};     //se pueden a�adir m�s malos a�adiendo m�s varibles de tipo emplazamiento(lleg� a haber 14)
	
	midemapa=0;	//empeazamos en el primer mapa
	
	int a=0,b=0,c=0,contfruta1,contfruta2,contfruta3;
	
	final=1;
	
	while(vidas!=0 && final)  // este bucle se ejecutar� mientras las vidas no lleguen a 0, y mientras la variable final sea 1(esto cambiar� cuando se llega al �ltimo mapa)
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
					pos.x=28;pos.y=19;dir=77+256;       //posici�n inicial del bueno
					
					vect[0].x=2;vect[0].y=6;
					vect[1].x=5;vect[1].y=6;
					vect[2].x=3;vect[2].y=6;
					vect[3].x=53;vect[3].y=6;
					vect[4].x=55;vect[4].y=6;
					vect[5].x=31;vect[5].y=15;
					
				}
				
				teclazos += loop(mat1,pos,dir,vect,0,regist,contador_frutas1,&temporal);
				
				
				  // 0 si no se paso el mapa; 1 si s� lo pas� 
				printf("Ha pulsado el teclado %d veces \n",teclazos);
				printf("Se ha comido %d frutas \n ",temporal.fruta);
				
				sleep(2);
				
				
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
				sleep(3);
				
				
				break;				
			case 1: // te has pasado el mapa 1 y estas en el 2
				
				if(b==0)
				{
					for(i=0;i<N;i++)
					{
						regist[i]=1; //vector de todo  unos que indica que al principio, los malos estan posicionados sobre casillas en las que no hay frutas
					}
					
					pos.x=28;pos.y=19;dir=77+256;       //posici�n inicial del bueno
					
					vect[0].x=17;vect[0].y=9;
					vect[1].x=19;vect[1].y=9;
					vect[2].x=21;vect[2].y=9;
					vect[3].x=23;vect[3].y=9;
					vect[4].x=26;vect[4].y=9;
					vect[5].x=31;vect[5].y=1;
				}
				
				teclazos += loop(mat2,pos,dir,vect,0,regist,contador_frutas2,&temporal);
				  // 0 si no se paso el mapa; 1 si s� lo pas�
				  
				printf("Ha pulsado el teclado %d veces \n",teclazos);
				printf("Se ha comido %d frutas \n ",temporal.fruta);
				
				sleep(2);
				
				
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
				sleep(3);
				
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
				  // 0 si no se paso el mapa; 1 si s� lo pas� 
				  
				printf("Ha pulsado el teclado %d veces \n",teclazos);
				printf("Se ha comido %d frutas \n ",temporal.fruta);
				
				sleep(2);
				
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
				sleep(3);
				
				break;
			case 3:   // te has pasado el tercer y �ltimo mapa
				
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
		printf("Nuestras más sinceras felicitaciones \n");
		break;
}

system("pause");
    
    
    int puntos=0; //puntos al principio del juego
    const int puntmap= 5000; // puntos que se obtienen al avanzar de mapa
    
    if (midemapa==0)
    {
        puntos=50*contfruta1;
    }
    else if (midemapa==1)
    {
        if (teclazos<=50)
        {
            puntos=500*contfruta1 + puntmap - 10*teclazos;
        }
        else if (teclazos>50 && teclazos<=100)
        {
            puntos=200*contfruta1 + puntmap - 10*teclazos;
        }
        else if (teclazos>100 && teclazos<=200)
        {
            puntos= 150*contfruta1 + puntmap - 10*teclazos;
        }
        else if (teclazos>200 && teclazos<=300)
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
        if (teclazos<=100)
        {
            puntos=500*contfruta1 + 500*contfruta2 + 2*puntmap - 10*teclazos;
        }
        else if (teclazos>100 && teclazos<=200)
        {
            puntos=200*contfruta1 + 200*contfruta2 + 2*puntmap - 10*teclazos;
        }
        else if (teclazos>200 && teclazos<=400)
        {
            puntos=150*contfruta1 + 150*contfruta2 + 2*puntmap - 10*teclazos;
        }
        else if (teclazos>400 && teclazos<=600)
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
        if (teclazos<=150)
        {
            puntos=500*contfruta1 + 500*contfruta2 + 500*contfruta3 + 3*puntmap - 10*teclazos;
        }
        else if (teclazos>150 && teclazos<=300)
        {
            puntos=200*contfruta1 + 200*contfruta2 + 200*contfruta3 + 3*puntmap - 10*teclazos;
        }
        else if (teclazos>300 && teclazos<=600)
        {
            puntos=150*contfruta1 + 150*contfruta2 + 150*contfruta3 + 3*puntmap - 10*teclazos;
        }
        else if (teclazos>600 && teclazos<=900)
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
		strcpy(jugador[cuantosJugadores].nombre,sesion.nombre);	//la variable sesi�n de tipo usuario pasa al �ltimo elemento(vac�o)del vector 'jugador'
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
              }
              
            break;
        case 1:
            for(u=0;u<cuantosJugadores;u++)
            {
                fprintf(pc,"#%i|%s,puntuacion:%i\n",u+1,jugador[u].nombre,jugador[u].puntuacion);
            }
            
            break;
    }
    fclose(pc);
    
    char micadena[cuantosJugadores*40];
    
    pc=fopen("Clasificacion.txt","r");
    if(pc==NULL)
    {
    	printf("No se pudo abrir el fichero \n");
    	exit(-1);
	}
	u=0;
	while(fscanf(pc,"%c",&r)!=EOF)
	{
		micadena[u]=r;
		u++;
	}
	borrar();
	printf("ESTA ES LA CLASIFICACION\n");
	printf("%s",micadena);
	
	
	
	return 0;	
}







