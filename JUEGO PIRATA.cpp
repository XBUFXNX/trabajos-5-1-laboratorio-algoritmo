#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


void main(){
//VARIABLES
	//Jugador
	int movimientos = 0, pir_x = 0, pir_y = 0, tocoAgua = 0, tocoTesoro = 0, opcion = 0;
	char direccion;
	
	//Tablero
	int grado, i, j;
	char tablero[100][100];
	
	//Tesoro
	int tes_x = 0, tes_y = 1;
	
	//Entorno
	int tablero_creado = 0;
    srand(time(NULL));
	
	printf("El Pirata Pata de Palo:");
	
	//Que juege mientras tenga movimientos, no haya tocado agua y no haya tocado el tesoro
	while(movimientos < 50 && tocoAgua == 0 && tocoTesoro == 0){
		
		printf("\n1- Iniciar el Tablero\n2- Mostrar Tablero\n3- Mover por el mapa\nElija: ");
		scanf("%d", &opcion);
		
		switch(opcion){
			case 1:
				tablero_creado = 1; //Ya se esta creando el tablero
				
				printf("\nElija el las dimensiones del tablero (NxN): ");
				scanf("%d", &grado);
				
				//Reseteo la cantidad de movimientos
				movimientos = 0;
				
				//Relleno el tablero
				for(i=0; i<grado; i++){
					for(j=0; j<grado; j++){
						/*
						A - Agua (bordes)
						. - Tierra (Relleno)
						*/
						
						if(i==0 || i==(grado-1)|| j==0 || j==(grado-1)){
							tablero[i][j] = 'A';
						}else{
							tablero[i][j] = '.';
						}
					}
				}
				
				pir_x = 1 + rand()%(grado-3);	//Posicion en x del pirata
				pir_y = 1 + rand()%(grado-3);	//Posicion en y del pirata
				
				do{
					tes_x = 1 + rand()%(grado-3); //Posicion en x del tesoro
					tes_y = 1 + rand()%(grado-3); //Posicion en y del tesoro
				}while(pir_y == tes_y && pir_x == tes_x);
				
				tablero[tes_y][tes_x] = 'T';
				
				break;
			case 2:
				//Si el tablero no se creo, que salga de esta opcion y lo avise
				if(tablero_creado == 0){

					printf("\nAun no se ha creado el tablero");
					break;
				}
				
				//Muestro tablero
				for(i = 0; i<grado; i++){
            		for(j=0; j<grado; j++){
            			if(i == pir_y && j == pir_x){
                    		printf("[X]");
                		}else{
                			printf("[?]");
						}
    				}
    				printf("\n");
        		}
				break;
			case 3:
				//Si el tablero no se creo, que salga de esta opcion y lo avise
				if(tablero_creado == 0){
					
					printf("\nAun no se ha creado el tablero");
					break;
				}
				//Mover por el mapa
				printf("\nEn que direccion se quere mover? (N,S,E,0): ");
				fflush(stdin);
				scanf("%c", &direccion);
				
				movimientos += 1;
				
				switch(direccion){
					case 'N': //Si presiona N
					case 'n': //o n
						//Resto 1 a la posicion en y del pirata
                    	pir_y -= 1;
						break;
					case 'S': //Si presiona S
					case 's': //o s
						//Sumo 1 a la posicion en y del pirata
						pir_y += 1;
						break;
					case 'E': //Si presiona E
					case 'e': //o e
						//Sumo 1 a la posicion en x del pirata
						pir_x += 1;
						break;
					case 'O': //Si presiona O
					case 'o': //o o
						//Resto 1 a la posicion en x del pirata
						pir_x -= 1;
						break;
					default:
						printf("\nNo existe dicho punto cardinal");
						movimientos -= 1; //Hizo un movimiento no valido, no cuenta.
				}
				
				//Una vez se mueve el pirata, que puede pasar?
				//Cocรณ con agua
				if(tablero[pir_y][pir_x] == 'A'){
					//Pierde
					tocoAgua = 1;
				}else
				//Encontrรณ el tesoro
				if(tablero[pir_y][pir_x] == 'T'){
					tocoTesoro = 1;
				}
				
				break;
			default:
				printf("\nNo existe esa opcion");
				break;
		}
	}
	//FINAL
	if(tocoTesoro == 1){		//Llegรณ al tesoro?
		printf("\nFELICITACIONES, ENCONTRO EL TESORO");
	}else if(tocoAgua == 1){	//Tocรณ el agua?
		printf("\nUfa, cayo al agua. Perdio");
	}else{						//Entonces se quedรณ sin movimientos
		printf("\nUfa, se les a ha acabado los movimientos\nantes de encontrar el tesoro. Perdio");
	}
	
	//Mapa Completo
	printf("\nMapa Completo\n");
	for(i = 0; i<grado; i++){
   		for(j=0; j<grado; j++){
   			if(i == pir_y && j == pir_x){
   				printf("[P]");	
			}else{
            	printf("[%c]", tablero[i][j]);
        	}
    	}
    	printf("\n");
	}	
	
	getch();
}