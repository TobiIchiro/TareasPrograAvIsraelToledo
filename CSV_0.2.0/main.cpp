 //Cuasi Shell V_1.0.1
//Manriquez Yasser; Miranda Zoraida; Morales Julio; Toledo Israel

/*					
	Notas:		Existen diversos "errores" que estamos omitiendo ej comando exit solo se identifica si esta en minusculas 
*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include "Polinomio.h"
#include "Racional.h"
#include <iostream>
using namespace std;

#define max_args 13  			//Numero maximo de argumentos (-1) cuando se trate de un comando externo
#define maxln_Com_Amb 105 		//Numero de caracteres maximo para comando las variables de ambiente

/*Declarando variables*/
char comando[maxln_Com_Amb]; 	//Esta var lee el comando que ingrese el usuario
char *args[max_args]; 			//en este arreglo se almacenan los argumentos del comando ingresado
char *frac[max_args]; 			//en este arreglo se almacenan las fracciones
int i;
FILE *Archivo;
char nombre[maxln_Com_Amb];
char poli1[maxln_Com_Amb];
char poli2[maxln_Com_Amb];
char opera[1];
char coeficiente[maxln_Com_Amb];
char polinomio[15];
int insert;
int f;		//entero que define la fraccion

/*Declarando cabeceras de funciones*/
void separaArgs(void); 				//Esta funcion separa la cadena ingresada por el usuario en palabras individuales, la 1ra palabra sera considerada comando y el resto sus argumentos
void CrearArchivo(FILE *Archivo);	//Esta funcion crea el archivo txtx del comando 
void InsertarDatos(FILE *Archivo);
void leerDatos(FILE *Archivo);
void driverPolinomio(FILE *Archivo);
void SavePolinomio(void);
void DesplegarInfo(void);
void SepararNuevo(void);
	

int main(int argc, char** argv) {
	int exit=1;		//Valor para determinar cuando se ingresa comando exit
	
	do{				//Programa en operacion hasta que no se ingrese 'exit'
    	int validar=0;
    	
		printf(">>  "); 					//Imprimiendo el indicador del shell
    	fflush(stdin); 						//Limpiando el buffer de entrada de teclado
    	memset(comando,'\0',maxln_Com_Amb);	//Borrando cualquier contenido previo de comando
    	scanf("%[^\n]s",comando); 			//Esperar hasta que el usuario ingrese algun comando
    	
    	if(strlen(comando)>0){				//Actua cuando el comando tiene algo
    		separaArgs();
				
			if(strcmp(comando,"exit")==0){ //analiza no se ingrese coamndo 'exit'
        	exit=0;}
        	
        	else{	//Inicia el analisis de lo ingresado
        	
				if(strcmp(comando,"variable")==0){
					CrearArchivo(Archivo);
					validar = 1;
				}
				if(strcmp(comando,"info")==0){
					DesplegarInfo();
					validar = 1;
				}
				if(strcmp(comando,"ver")==0){
					leerDatos(Archivo);
					validar = 1;
				}
				if(strcmp(comando,"clc")==0){
					system("cls");
					validar = 1;
				}
				if(strcmp(comando,"operacion")==0){
					driverPolinomio(Archivo);
					validar = 1;
				}
				if (validar == 0){
				cout<<"<<  Ingresa un comando valido"<<endl;
				}
				
			}
		}
	}while(exit);
	
	return 0;
}

void separaArgs(void){  

	for(i=0;i<(max_args-1);i++) args[i]=NULL;							//Borrar argumento previo
		strtok(comando," =()[]{},"), i=0; 								//separar palabras individuales usando tokens (espacio vacio) guarda en args[i]
		args[i]=comando; 												//El 1er argumento sera la constante
	while((args[++i]=strtok(NULL," =()[]{},"))!=NULL && i<(max_args-2));
}

void CrearArchivo(FILE *Archivo){
	char respuesta[2];
	FILE *arch;
	strcpy(nombre,args[1]);				//Guarda temporalmente el nombre de la variable 
	strcat(nombre,".txt");				//Concatena el nombre de la variable y .txt para crear el archivo
	
	Archivo = fopen (nombre, "r");	
	char namefile[15];
   
	if (!Archivo){						//Verifica la creacion del archvio
    Archivo=fopen (nombre, "w");
    InsertarDatos(Archivo);			
    }
    
    else{								//Pregunta si quieres sobre escribir
    cout<<"<<  La variable "<<args[1]<<" ya existe, sobre escribir? si/no"<<endl;
	int sobre = 1;						//variable para ciclo de sobre escribir
	
	do{   
		fflush(stdin);
		cout<<">>  ";
		cin>>respuesta;
			if(strcmp(respuesta,"si")==0){
				InsertarDatos(Archivo);
				sobre = 0;
			}
			else if(strcmp(respuesta,"no")==0){
				sobre = 0;
			}else {
			cout<<"<<  Error: por favor ingresa una opcion correcta"<<endl;
			}
	}while(sobre);
	
	}
        
        fclose(Archivo);
    
}

void InsertarDatos(FILE *Archivo){
	int y;
	char Y[1];
	fclose(Archivo);
	Archivo=fopen(nombre, "w+");
	strcpy(polinomio,"");
	for(y=2; y<i; y++){
		strcat(polinomio,args[y]);
		strcat(polinomio," ");
	}
	
	cout<<"    "<<args[1]<<" ="<<endl<<"\t"<<polinomio<<endl;
	y-=2;
	sprintf(Y,"%d",y);
	strcat(Y," ");
	strcat(Y,polinomio);
	strcpy(polinomio,Y);
	fwrite(polinomio,sizeof(char),sizeof(polinomio),Archivo);

	fclose(Archivo);
}

void leerDatos(FILE *Archivo){
	int y;
	FILE *arch;
	strcpy(nombre,args[1]);				//Guarda temporalmente el nombre de la variable 
	strcat(nombre,".txt");				//Concatena el nombre de la variable y .txt para crear el archivo
	
	Archivo = fopen (nombre, "r");	
	char namefile[15];
	   
	if (!Archivo){						//Verifica la creacion del archvio
	cout<<"<<  La variable "<<args[1]<<" no existe"<<endl;
	}
    else{
    fread(polinomio,sizeof(char),sizeof(polinomio),Archivo);		//Inicializa para leer el archvio
	
    cout<<"    "<<args[1]<<" ="<<endl;
    
    for(i=0;i<(max_args-1);i++) args[i]=NULL;						//mismo proceso que separar argumentos, polinomio = grado de este
		strtok(polinomio," "), i=0;
	while((args[++i]=strtok(NULL," "))!=NULL && i<(max_args-2));
	
	cout<<"\t";
	
	for(y=1; y<i; y++){				//ciclo para ver coeficiente por coeficiente 
	cout<<args[y]<<" ";
	}
	cout<<endl;
	
    fclose(Archivo);				//cierra el archivo
	}
}

void driverPolinomio(FILE *Archivo){
	int y;
	
	FILE *arch;
	strcpy(opera,args[2]);				//guarda temporalmente el operador
	strcpy(poli1,args[1]);				//Guarda temporalmente el nombre de polinomio1 
	strcat(poli1,".txt");				//Concatena el polinomio1 y .txt para abrir el archivo
	strcpy(poli2,args[3]);				//Guarda temporalmente el nombre del polinomio2 
	strcat(poli2,".txt");				//Concatena el polinomio2 y .txt para abrir el archivo
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Archivo = fopen (poli1, "r");	
	char namefile[15];
	
	if (!Archivo){						//Verifica la creacion del archvio
	cout<<"<<  La variable "<<args[1]<<" no existe"<<endl;
	}
	else{
	fread(polinomio,sizeof(char),sizeof(polinomio),Archivo);		//Inicializa para leer el archvio
    
    for(i=0;i<(max_args-1);i++) args[i]=NULL;						//mismo proceso que separar argumentos, polinomio = grado de este
		strtok(polinomio," "), i=0;
	while((args[++i]=strtok(NULL," "))!=NULL && i<(max_args-2));
	
    fclose(Archivo);				//cierra el archivo
  	Rac *unRacPt=new Rac[i-1];
  	
	char n[10];		//entero que define el numerador
	char d[10];		//entero que define el denominador
	int N;
	int D;
	
	for (y=0;y<(i-1);y++){
		
		strcpy(coeficiente,args[y+1]);
		SepararNuevo();
		strcpy(n,frac[0]);
		N = atoi(n);
		strcpy(d,frac[1]);
		D = atoi(d);
		*(unRacPt+y)=Rac(N,D);
	}
  	//usamos constructor Polinomio(int,Rac*)
  	Polinomio Polinomio1(i-2,unRacPt); 
  	//Polinomio1 es de grado 2 con coeficientes Rac a_{0} a_{1} a_{2}*/
  	
  	//se repite pero ahora con poli2
	Archivo = fopen (poli2, "r");	
	char namefile[15];
	
	if (!Archivo){						//Verifica la creacion del archvio
	cout<<"<<  La variable "<<args[3]<<" no existe"<<endl;
	}
	else{
	fread(polinomio,sizeof(char),sizeof(polinomio),Archivo);		//Inicializa para leer el archvio
    
    for(i=0;i<(max_args-1);i++) args[i]=NULL;						//mismo proceso que separar argumentos, polinomio = grado de este
		strtok(polinomio," "), i=0;
	while((args[++i]=strtok(NULL," "))!=NULL && i<(max_args-2));
	
    fclose(Archivo);				//cierra el archivo
  	Rac *unRacPt=new Rac[i-1];
	
	for (y=0;y<(i-1);y++){
		
		strcpy(coeficiente,args[y+1]);
		SepararNuevo();
		strcpy(n,frac[0]);
		N = atoi(n);
		strcpy(d,frac[1]);
		D = atoi(d);
		*(unRacPt+y)=Rac(N,D);
	}
  	//usamos constructor Polinomio(int,Rac*)
	////////////////////////////////////////////////////////////////////////////////////////////////
	Polinomio Polinomio2(i-2,unRacPt);
	//Este es el final del programa 
	
  	if(strcmp(opera,"+")==0){
		Polinomio Polinomio3 = Polinomio1 + Polinomio2;
  		cout<<Polinomio3<<endl;}
	if(strcmp(opera,"*")==0){
		Polinomio Polinomio3 = Polinomio1 * Polinomio2;
  		cout<<Polinomio3<<endl;}
  		if(strcmp(opera,"-")==0){
		Polinomio Polinomio3 = Polinomio1 - Polinomio2;
  		cout<<Polinomio3<<endl;}
	//agregar los otros operadores
	
		  
		}
	}
}

void SepararNuevo(void){  
	
	frac[0]=strtok(coeficiente,"/"); 
	frac[1]=strtok(NULL,"/");
}


void DesplegarInfo(){
	cout<<"<<  Este programa es una creacion de Yasser, Zoraida, Julio e Israel; CSV_1.0.1"<<endl;
	cout<<"    Ingresa los comandos correctos para que funcione el interprete"<<endl<<endl;
	cout<<"    Lista de comandos"<<endl;	
	cout<<"    variable \t crea la variable y guarda ex. variable A = {1, 2}"<<endl;
	cout<<"    ver \t muestra la variable deseada ex. ver A"<<endl;
	cout<<"    operacion \t realiza las operaciones de polinomios ex. operacion A + B"<<endl;
	cout<<"    clc \t limpia la pantalla"<<endl;
	cout<<"    exit \t cierra el programa"<<endl;
}

