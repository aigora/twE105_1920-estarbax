#include "Funciones.h"

#define up 72+256
#define down 80+256
#define right 77+256
#define left 75+256

#define N 6 		//cambiante  (numero de malos)
#define AL 24		//filas matriz
#define ANC 58		//columnas matriz
#define V 2000	


int ascii(char letra)
{
	int result;
	result=letra;
	return result;
}

void imprimirmatriz(char mat[][ANC])
{
	int i,n;
	for(i=0;i<AL;i++)
	{
		for(n=0;n<ANC;n++)
		{
			printf("%c",mat[i][n]);
		}
		printf("\n");
	}
}

int loop(char matrix[][ANC],emplazamiento pos,int dir,emplazamiento vect[],int i,int regist[],int frutas_iniciales,map_prop *p)
{
	int aux,z,t; //t es la variable que se utiliza para los bucles
			
	aux=dir;
	
	if(dir!=113)
	{
		switch(dir)
		{
			case up:		//se ha pulsado la flecha de arriba	
				while(matrix[pos.y-1][pos.x]!='=' && matrix[pos.y-1][pos.x]!='|' && matrix[pos.y-1][pos.x]!='/' && !kbhit())
				{
					z=cuadrante(pos);  // Determina en que cuadrante se encuentra nuestro personaje
					matrix[pos.y][pos.x]=' ';	//Deja la posición en la que estaba nuestro personaje vacía		
					pos.y-=1; 	//Cambia el valor de la posición de nuestro personaje (este caso -1 porque el usuario pulsó arriba)
					
					mueveMalos(vect,matrix,regist,z);	//función que reposiciona a los malos
					
					matrix[pos.y][pos.x]='D';		//El elemento que corresponde a las nuevas coordenadas de nuestro personaje en el 
													//símbolo de nuestro personaje ( D ) 
					
					for(t=0;t<N;t++)		//bucle que hace que el elemento que corresponde a cada una de las coordenadas de los malos
					{										// sea el ( # )
						matrix[vect[t].y][vect[t].x]='#';
					}
										
					borrar();	//función que borra la pantalla, gracias a esta función es posible crear los 'frames' del juego
					
					imprimirmatriz(matrix);		//función que imprime la nueva matriz por pantalla
						
					if(comprobante(matrix,'D'))	//comprobante de si estamos muertos
					{
						printf("Has perdido \n");	
						p->nivel=0;
						p->fruta = frutas_iniciales-(contador(matrix,'o'));
						return i;
					}
					if(comprobante(matrix,'o'))		//comprobante de si ya no queda fruta (hemos ganado)
					{
						printf("Has ganado \n");		
						p->nivel=1;
						p->fruta=0;
						return i;
					}		
				}			
				break;
				
			case down:		//flecha de abajo
				while(matrix[pos.y+1][pos.x]!='=' && matrix[pos.y+1][pos.x]!='|' && matrix[pos.y+1][pos.x]!='/' && !kbhit())
				{
					z=cuadrante(pos);
					matrix[pos.y][pos.x]=' ';
					pos.y+=1;
					
					mueveMalos(vect,matrix,regist,z);
					
					matrix[pos.y][pos.x]='D';
					
					for(t=0;t<N;t++)
					{
						matrix[vect[t].y][vect[t].x]='#';
					}
					
					
					borrar();
					
					imprimirmatriz(matrix);
					
					if(comprobante(matrix,'D'))
					{
						printf("Has perdido \n");	
						p->nivel=0;
						p->fruta = frutas_iniciales-(contador(matrix,'o'));
						return i;
					}
					if(comprobante(matrix,'o'))
					{
						printf("Has ganado \n");		
						p->nivel=1;
						p->fruta=0;
						return i;
					}
				}					
				break;
			case right:		//flecha derecha
				while((matrix[pos.y][pos.x+1]!='=' && matrix[pos.y][pos.x+1]!='|' && matrix[pos.y][pos.x+1]!='/' && !kbhit()) || pos.x==57)
				{
					z=cuadrante(pos);
					matrix[pos.y][pos.x]=' ';
					if((pos.y==11 || pos.y==12) && (pos.x==57))
					{
						pos.x=0;
					}					
					else
					{
						pos.x+=1;
					}										
					
					mueveMalos(vect,matrix,regist,z);
					
					matrix[pos.y][pos.x]='D';
					
					
					for(t=0;t<N;t++)
					{
						matrix[vect[t].y][vect[t].x]='#';
					}
					
					
					borrar();
					
					imprimirmatriz(matrix);
					
					if(comprobante(matrix,'D'))
					{
						printf("Has perdido \n");	
						p->nivel=0;
						p->fruta = frutas_iniciales-(contador(matrix,'o'));
						return i;
					}
					if(comprobante(matrix,'o'))
					{
						printf("Has ganado \n");		
						p->nivel=1;
						p->fruta=0;
						return i;
					}
				}
				break;
			case left:		//flecha izquierda
				while((matrix[pos.y][pos.x-1]!='=' && matrix[pos.y][pos.x-1]!='|' && matrix[pos.y][pos.x-1]!='/' && !kbhit()) || pos.x==0)
				{
					z=cuadrante(pos);
					matrix[pos.y][pos.x]=' ';
					if((pos.y==11 || pos.y==12) && (pos.x==0))
					{
						pos.x=57;
					}						
					else
					{
						pos.x-=1;
					}									
					
					mueveMalos(vect,matrix,regist,z);
					
					matrix[pos.y][pos.x]='D';
					
					for(t=0;t<N;t++)
					{
						matrix[vect[t].y][vect[t].x]='#';
					}
					
					borrar();
					
					imprimirmatriz(matrix);	
					
					if(comprobante(matrix,'D'))
					{
						printf("Has perdido \n");	
						p->nivel=0;
						p->fruta = frutas_iniciales-(contador(matrix,'o'));
						return i;
					}
					if(comprobante(matrix,'o'))
					{
						printf("Has ganado \n");		
						p->nivel=1;
						p->fruta=0;
						return i;
					}					
				}
				break;
		} //aquí termina el switch		 
		dir=getch(); 		//aquí tiene que recoger la nueva tecla.
		if(dir == 0 || dir == 224) // bug que ocurre con el código ascii de las teclas direccionales
		{
			dir = 256 + getch();
		}
		else if(dir == 81)	//si es la Q (mayúscula)
		{
			dir=strdown(dir); //la hace q(minúscula)
		}
		if(dir!=72+256 && dir!=80+256 && dir!=77+256 && dir!=75+256 && dir!=113) //si la tecla pulsada no es ni las flechas ni q, 
		{		//Q = 81;  q = 113; 113-81=32;									//la dirección vuelve a ser la de antes y se repite loop(...);
			dir=aux;
			loop(matrix,pos,dir,vect,i,regist,frutas_iniciales,p);
		}
		
		if(ultimo_comprobante(dir,matrix,pos)) //con este condicional hacemos que se reduzcan considerablemente las trampas
		{									   //si estas yendo hacia la derecha y quieres parar para pensar mejor la jugada,(si hay pared arriba)
			dir=aux;						   //antes se podía dar hacia arriba y se paraba; ahora con la función ultimo_comprobante() no; porque comprueba (en este ejemplo)
		}										// si tenias pared arriba, si es así, este condicional se 'activa', y dir recupera su valor anterior que estaba almacenado en aux.
		i++;//contador de pulsaciones													por tanto, el juego es más fluido 
		
		
		loop(matrix,pos,dir,vect,i,regist,frutas_iniciales,p);	//es una función recursiva		
	}
	else	// si se pulsa q, se accede al menú de pause
	{
		printf("Al pulsar la tecla q, ha accedido al men%c de pause \n",163);
		menu(0);
		borrar();
		printf("EL JUEGO CONTIN%cA \n",233);
		sleep(2);
		dir=right;
		loop(matrix,pos,dir,vect,i,regist,frutas_iniciales,p);
	}		
}//aquí termina la función loop();

//funcion de movimiento de los malos
void mueveMalos(emplazamiento vect[],char matriz[][ANC],int regist[],int z)
{
	int i,dir;
	for(i=0;i<N;i++)
	{
		dir=notan_aleatorio(z);
		switch(dir)
		{
			case 1: //arriba
				if(matriz[vect[i].y-1][vect[i].x]!='=' && matriz[vect[i].y-1][vect[i].x]!='/' && matriz[vect[i].y-1][vect[i].x]!='|' && matriz[vect[i].y-1][vect[i].x]!='#' )
				{	
					if(regist[i]== 0) //si donde estabas antes habia fruta
					{
						matriz[vect[i].y][vect[i].x]='o'; //deja la fruta donde estaba
					}	
					else	//en caso contrario
					{		
						matriz[vect[i].y][vect[i].x]=' '; //déjalo vacío
					}					
					vect[i].y-=1;
					
					regist[i]=1;
					
					if(matriz[vect[i].y][vect[i].x] == 'o') //si vas a una casilla donde hay fruta ( 'o' )
					{
						// que quede registrado que el enésimo malo se dirige hacia fruta por medio del vector regist[]
						regist[i]=0;
					}
					//Este ciclo se repetirá para cada uno de los malos. 
					//'Si el malo enésimo se dirige hacia fruta, que quede registrado en la posición enésima del vector regist[]'	
				}
				break;
			case 2: //abajo
				if(matriz[vect[i].y+1][vect[i].x]!='=' && matriz[vect[i].y+1][vect[i].x]!='/' && matriz[vect[i].y+1][vect[i].x]!='|' && matriz[vect[i].y+1][vect[i].x]!='#')
				{
					if(regist[i]== 0)
					{
						matriz[vect[i].y][vect[i].x]='o';
					}	
					else	
					{		
						matriz[vect[i].y][vect[i].x]=' '; 
					}					
					vect[i].y+=1;
					
					regist[i]=1;
					
					if(matriz[vect[i].y][vect[i].x] == 'o') 
					{
						
						regist[i]=0;
					}	
				}
				break;
			case 3:  //derecha
				if(matriz[vect[i].y][vect[i].x+1]!='=' && matriz[vect[i].y][vect[i].x+1]!='/' && matriz[vect[i].y][vect[i].x+1]!='|' && matriz[vect[i].y][vect[i].x+1]!='#')
				{
					if(regist[i]== 0)
					{
						matriz[vect[i].y][vect[i].x]='o';
					}	
					else	
					{		
						matriz[vect[i].y][vect[i].x]=' '; 
					}					
					vect[i].x+=1;
					
					regist[i]=1;
					
					if(matriz[vect[i].y][vect[i].x] == 'o') 
					{
						
						regist[i]=0;
					}	
				}
				break;
			case 4:  //izq
				if(matriz[vect[i].y][vect[i].x-1]!='=' && matriz[vect[i].y][vect[i].x-1]!='/' && matriz[vect[i].y][vect[i].x-1]!='|' && matriz[vect[i].y][vect[i].x-1]!='#')
				{
					if(regist[i]== 0)
					{
						matriz[vect[i].y][vect[i].x]='o';
					}	
					else	
					{		
						matriz[vect[i].y][vect[i].x]=' '; 
					}					
					vect[i].x-=1;
					
					regist[i]=1;
					
					if(matriz[vect[i].y][vect[i].x] == 'o') 
					{
						
						regist[i]=0;
					}	
				}
				break;
			default:
				printf("No salio bien\n");
				break;					
		}
	}
	
}

int notan_aleatorio(int z)
{
	int numero,vect[10],vect_2[5];
	switch(z)
	{
		case 1:	// estamos en el primer cuadrante (arriba izq)
			// vect[10]={1,1,1,1,3,3,3,3,4,2};
			vect[0]=2;vect[1]=1;vect[2]=1;vect[3]=3;vect[4]=3;vect[5]=3;vect[6]=4;vect[7]=1;vect[8]=3;vect[9]=1;
			numero = vect[aleatorio(0,9)];
		
			break;
		case 2: //estamos en el segundo cuadrante (arriba derecha)
			// vect[10]={1,1,1,4,4,4,3,2,3,2};
			vect[0]=2;vect[1]=1;vect[2]=1;vect[3]=4;vect[4]=4;vect[5]=4;vect[6]=3;vect[7]=1;vect[8]=4;vect[9]=1;
			numero = vect[aleatorio(0,9)];
		
			break;
		case 3:		//estamos en el tercer cuadrante (abajo izq)
			// vect[10]={2,2,2,4,4,4,3,1,3,1};
			vect[0]=2;vect[1]=2;vect[2]=1;vect[3]=4;vect[4]=3;vect[5]=4;vect[6]=4;vect[7]=2;vect[8]=4;vect[9]=2;
			numero = vect[aleatorio(0,9)];
		
			break;
		case 4:		//estamos en el cuarto cuadrante (abajo derecha)
			// vect[10]={2,2,2,3,3,3,4,1,4,1};
			vect[0]=2;vect[1]=2;vect[2]=1;vect[3]=3;vect[4]=4;vect[5]=3;vect[6]=3;vect[7]=2;vect[8]=3;vect[9]=2;
			numero = vect[aleatorio(0,9)];
		
			break;
	}
	return numero;
}

int aleatorio(int q,int r)
{
	int numero;
	srand (time(NULL)); 
 	numero = rand () % (r-q+1) + q;   //genera ul numero aleatorio entre q y r
 	return numero;
	
}

int strdown(int c) //convierte el ASCII de una letra mayÃºscula en su forma minÃºscula
{
	int min; 
	int i='a'-'A'; //i=32
	min=c+i;
	return min;	
}

int comprobante(char matriz[][ANC],char com)
{
	int i,n;
	_Bool k;
	k=1;	
	for(i=0;i<AL;i++)
	{
		for(n=0;n<ANC;n++)
		{
			if(matriz[i][n]== com)	//comprueba si el 'char com' está en alguna celda de la matriz
			{
				k=0;	
			}
		}
	}
	return k;
}

int contador(char matriz[][ANC],char k)
{
	int i,n,cont=0;
	

	for(i=0;i<AL;i++)
	{
		for(n=0;n<ANC;n++)
		{
			if(matriz[i][n]== k)	/////	cuanta cuantas veces está cierto elemento en la matriz mapa
			{
				cont++;	
			}
		}
	}
	return cont;
	
}

int cuadrante(emplazamiento pos)		//AL 24	 filas matriz		    ANC 58  columnas matriz
{
	if(pos.y<=(AL/2)-1 && pos.x<=ANC/2)
	{
		return 1;	//estamos en el primer cuadrante (arriba izquierda)
	}
	else if(pos.y<=(AL/2)-1 && pos.x>=(ANC/2)+1)  
	{
		return 2;	//estamos en el segundo cuadrante (arriba derecha)	
	}
	else if(pos.y>=(AL/2) && pos.x<=ANC/2)
	{
		return 3;	//estamos en el tercer cuadrante (abajo izquierda)
	}
	else if(pos.y>=(AL/2) && pos.x>=(ANC/2)+1)
	{
		return 4;	//estamos en el cuarto cuadrante (abajo derecha)
	}
}

int ultimo_comprobante(int tecla,char mat[][ANC],emplazamiento pos)
{
	switch(tecla)
	{
		case up:
			if(mat[pos.y-1][pos.x]=='=' || mat[pos.y-1][pos.x]=='|')
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
			break;
		case down:
			if(mat[pos.y+1][pos.x]=='=' || mat[pos.y+1][pos.x]=='|')
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
			break;
		case right:
			
			if(mat[pos.y][pos.x+1]=='=' || mat[pos.y][pos.x+1]=='|')
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
			break;
		case left:
			
			if(mat[pos.y][pos.x-1]=='=' || mat[pos.y][pos.x-1]=='|') 
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
			break;
		case 113: //tecla q
			
			return 0;
			
			break;
	}
}


void menu(int a)  // resume;  opciones:  instrucciones,salir atras
{
	int p;
	_Bool final=1;
	char mini_cad[1];
	
	color(0);
	
	printf("Men%c opciones \n",163);
	
	while(final)
	{
		
		printf("%cQue desea hacer? \n",168);
		
		if(a==1)
		{
			printf("-Si quiere empezar a jugar pulse 1 \n-Si quiere acceder a las instrucciones pulse 2 \n-Si quiere salir pulse 3 \n");
		}
		else
		{
			printf("-Si quiere continuar jugando pulse 1 \n-Si quiere acceder a las instrucciones pulse 2 \n-Si quiere salir pulse 3 \n");
		}
		
		do
		{
			printf("Recuerda que solo puede introducir 1,2, o 3 \n");
			scanf("%s",mini_cad);
			p=strlen(mini_cad);
		}
		while((p!=1) || (mini_cad[0]<48 || mini_cad[0]>57) || (mini_cad[0]!=49 && mini_cad[0]!=50 && mini_cad[0]!=51));
		
		switch(mini_cad[0])
		{
			case '1':	//inicia el juego
				final=0;
				break;
			case '2':
				instrucciones();
				final=1;
				break;
			case '3':
				printf("Salir \n");
				exit(-1);
				break;
		}	
	}	
	color(1);
}


void instrucciones()
{
	borrar();
	printf("Accede a las instrucciones\n");
	FILE *g;  //declaramos un puntero
	char x, cad[V];
	int i=0;
	g=fopen("instrucciones.txt","r"); //el puntero apunta al fichero instrucciones.txt
	if(g==NULL)
	{
		printf("No se ha podido abrir el fichero\n");
		exit(-1);
		
	}
	
	strcpy(cad,"");	//empieza siendo cadena vacía
	
	while(fscanf(g,"%c",&x)!=EOF)	//lectura de cada uno de los elementos del fichero
	{
		cad[i]=x;	//almacenamiento de los elementos del fichero en una cadena de caracteres
		i++;	
	}
	printf("%s",cad);	//imprimir por pantalla la cadena de caracteres
	fclose(g);	//cerramos el fichero
	printf("\nPulse una tecla para continuar\n");
	while(!kbhit())
	{
		
	}
	x=getch();	//la almacena aquí para evitar problemas
	borrar();
}


void borrar()
{
  #ifdef _WIN32  //El símbolo _WIN32 está definido sólo en Windows
    system("cls");	//sólo se podrá acceder aquí si se compila en Windows
  #else		// si NO estamos en Windows
    printf("\033[2J"); //Secuencia de escape para el borrado del terminal y posicionamiento del cursor al principio del mismo
  #endif
}

void color(int a)	//funcion para cambiar el color muy parecida a borrar(), utiliza secuencias de escape
{
	if(a==1)
	{
		#ifdef _WIN32
			system("color 03");
		#else
			printf("\033[36m\033[40m");	//color del mapa
		#endif		
	}
	else
	{
		#ifdef _WIN32
			system("color F0");
		#else
			printf("\033[30m\033[47m");	//color del menú
		#endif		
	}
	
}


