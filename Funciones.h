#define ANC 58  // ancho de la matriz
#include <time.h>

typedef struct
{
	int x;
	int y;
	
}emplazamiento;

typedef struct
{
	int fruta;
	int nivel;
}map_prop;

typedef struct
{
    char nombre [30];
    int puntuacion;
    
}usuario;


int ascii(char letra);
void imprimirmatriz(char mat[][ANC]);
int loop(char matrix[][ANC],emplazamiento pos,int dir,emplazamiento vect[],int i,int regist[],int frutas_iniciales,map_prop *p);
void mueveMalos(emplazamiento vect[],char matriz[][ANC],int regist[],int z); 
int notan_aleatorio(int z);
int aleatorio(int q,int r);
int strdown(int c);
int comprobante(char matriz[][ANC],char com);
int contador(char matriz[][ANC],char k);
int cuadrante(emplazamiento pos);
int ultimo_comprobante(int tecla,char mat[][ANC],emplazamiento pos);
void menu(int a);
void instrucciones();
void borrar();
void color(int a);



