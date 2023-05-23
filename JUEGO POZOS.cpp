#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

main(){
int matriz[5][5], j, i, pozos, play[5][5], control1=0, control2=0; 
srand(time(NULL));
char mov;
for(j=0; j<=4; j++){ 
         for(i=0; i<=4; i++){
                 matriz[j][i]=1;
                 play[j][i]=0;
                  }
         }
for(pozos=0; pozos<=3; pozos++){ 
             matriz[1+rand()%4][1+rand()%4]=0; 
             }
while((control1==control2 || control2!=4) && matriz[control1][control2]!=play[control1][control2]){
  printf("Usted esta en la posicion %d, %d.", control1, control2);
  printf("\nR = Derecha, L = Izquierda, U = Arriba, Abajo = D\n");
  fflush(stdin);
  scanf("%c", &mov);
  if((mov=='R') && (control1<4)){
          control1++;
          printf("Se movio correctamente hacia la derecha\n");
            }
  else{
       if(mov=='R'){
      printf("A donde queres ir si no tenes mas espacio pa. Volve a intentarlo\n");
      }
       }
  if((mov=='L') && (control1>0)){
          control1=control1-1;
          printf("Se movio correctamente hacia la izquierda\n");
            }
  else{
      if(mov=='L'){
      printf("A donde queres ir si no tenes mas espacio pa. Volve a intentarlo\n");
      }
       }
  if((mov=='U') && (control2>0)){
          control2=control2-1;
          printf("Se movio correctamente hacia arriba\n");
            }
  else{
      if(mov=='U'){
      printf("A donde queres ir si no tenes mas espacio pa. Volve a intentarlo\n");
      }
       }
  if((mov=='D') && (control2<4)){
          control2++;
          printf("Se movio correctamente hacia abajo\n");
            }
  else{
      if(mov=='D'){
      printf("A donde queres ir si no tenes mas espacio pa. Volve a intentarlo\n");
                 }
      }
  if(matriz[control1][control2]==play[control1][control2]){
      printf("\nCaiste en el pozo, a casa platita");
                                                           }
  if(control1==4 && control2==4){
                 printf("\nGanaste el juego, fasilito el tuto");
                 }
   }
   getch();
  }
