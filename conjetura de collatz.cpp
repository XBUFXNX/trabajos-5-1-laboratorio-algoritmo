#include <stdio.h>
int num; 
main()
{
	printf("ingresar un numero");
	scanf ("%d", &num);
	do
	{
	if(num%2 == 0)
	{
		num= num / 2;
	}
	
	else if(num != 1 && num%2 != 0)
	{
		num= (num * 3) + 1;
	}
	printf("sucesion: %d\n", num);
	}
	while(num != 1);
}
