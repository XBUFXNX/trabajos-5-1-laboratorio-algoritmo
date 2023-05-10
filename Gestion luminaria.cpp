#include<stdio.h>
int main(){
int i=0,maxcalle[5],max,acum=0,totalcalle=75,calle,luz;

for(i=0;i<5;i++)
{
printf("ingrese cuantas luces de la calle %d estan prendidas: ",i);
scanf("%d",&maxcalle[i]);
acum+=maxcalle[i];
while(maxcalle[i]<1||maxcalle[i]>15)
{
printf("---------ERROR\n");
printf("ingrese cuantas luces de la calle %d estan prendidas: ",i);
scanf("%d",&maxcalle[i]);
}
}
totalcalle=totalcalle-acum;
printf("ingrese el numero de calle(1 al 5)");
scanf("%d",&calle);
while(calle<1||calle>5)
{
printf("ERROR\n");
printf("ingrese el numero de calle(1 al 5)");
scanf("%d",&calle);
}
printf("\nEl valor maximo de luces que quiere prender es de %d",maxcalle[calle-1]);
printf("\n\n");
printf("ingrese las luces que quiera encender(1 al 15)");
scanf("%d",&luz);
if(maxcalle[calle-1]==luz||maxcalle[calle-1]==0)
{
printf("se encendieron el maximo de luces de esa calle\n");
}
if(luz==0)
{
printf("\n\n");
printf("Oscura");
}


if(maxcalle[calle-1]>=15-luz)
{
printf("\nEsta calle es muy iluminada");
printf("\n\n");
}

else if(maxcalle[calle-1]<=15-luz)
{
printf("\nEsta calles es luminada");
printf("\n\n");
}

else if(maxcalle[calle-1]<luz)
{
printf("\nEsta calle es tenebrosa");
printf("\n\n");
}

printf("el total de luces apagadas es de %d",totalcalle);
}
