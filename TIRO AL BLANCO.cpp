#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <conio.h>

using namespace std;


int main(){
	
	int edad, i, j, gente, matriz[3][3], n=1, jugar,  mas_puntos, max, puntaje_0, puntaje_1, puntaje_2, acum;
	string  iniciales[100];
	float cont_18=0, porc_18=0, cont_c=0, porc_c=0;
	

	
	do{

		cout<<"-------Ronda "<<n++<<".-------"<<endl;
			
		//Pide informacion a cada participante.
		for(i=0;i<3;i++){
			cout<<"--Participante "<<i+1<<"."<<endl;
			cout<<"Ingrese su inicial: "<<endl;
			cin>>iniciales[i];
			cout<<"Ingrese su edad: "<<endl;
			cin>>edad;
			if(edad<18){
				cont_18+=1;
			}
		}
		
		//Rellena la matriz con los puntajes de cada jugador (fila=jugador) (columna=puntaje de cada tiro).
		for(i=0;i<3;i++){
			
			cout<<"--Turno del participante "<<i<<"."<<endl;
			acum=0;
			for(j=0;j<3;j++){
				
				cout<<"Tiro "<<j+1<<"- Ingrese puntaje( 100, 50, 10, -10 )."<<endl;
				cin>>matriz[i][j];
				if(matriz[i][j]==100){
					cont_c+=1;
				}
				acum+=matriz[i][j];
			}
			
			if(max==0||acum>max){
				max=acum;
				mas_puntos=i;
			}
				
		}

		//Calculos
		puntaje_0=(matriz[0][0])+(matriz[0][1])+(matriz[0][2]);
		puntaje_1=(matriz[1][0])+(matriz[1][1])+(matriz[1][2]);
		puntaje_2=(matriz[2][0])+(matriz[2][1])+(matriz[2][2]);
		porc_18=(cont_18*100)/3;
		porc_c=(cont_c*100)/9;
		
		//Imprime la matriz con todos los puntajes.		
		cout<<"Tabla de puntajes: "<<endl;
		cout<<"\n";
		
		//Puntajes individuales.
		cout<<"Participante 1 obtuvo: "<<puntaje_0<<endl;
		cout<<"Participante 2 obtuvo: "<<puntaje_1<<endl;
		cout<<"Participante 3 obtuvo: "<<puntaje_2<<endl;
		
		//Imprime los resultados de la ronda.
		cout<<"----- Resultados de ronda: "<<n-1<<". -----"<<endl;
		cout<<"\n";
		cout<<"- Mejor puntaje: -"<<endl;
		cout<<"Participante "<<mas_puntos+1<<" con "<<max<<" puntos."<<endl;
		cout<<"\n";
		cout<<"- Porcentaje de participantes con menos de 18: -"<<endl;
		cout<<porc_18<<" %"<<endl;
		cout<<"\n";
		cout<<"- Porcentaje de tiros al centro(100 puntos): -"<<endl;
		cout<<porc_c<<" %"<<endl;
		cout<<"\n";
		
		//Pregunta si quiere jugar otra ronda.
		cout<<"Desea jugar otra ronda ?: 1(si) 2(no)."<<endl;
		cin>>jugar;
		
		
	}while(jugar!=2);	
	
	cout<<"Juego terminado.";
	
	getch();
	return 0;
}


