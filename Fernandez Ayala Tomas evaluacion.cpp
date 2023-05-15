#include<stdio.h>
#include<string.h>
main()
{
	char tipo[14]; //variable de tipo de alfajor
	char cant; //variable de cantidad de alfajores
	int i, num, n; 
	float acum1=0, acum2=0, acum3=0, acum4=0; //variable para acumular todos los alfajores
	int P_choco = 500 /*sabor chocolate*/, P_dulce = 750 /*sabor dulce de leche*/, P_fruta = 30 /*sabor de fruta*/, P_mix = 1000 /*sabor mixtos*/; //precios por cada caja y sabor, son precios preestablecidos
	float gana_c= 0 , gana_d = 0, gana_f = 0, gana_m = 0;
	
	
	
	for(i=0; i < n; i++)
	{
		printf("///empleado %d ///", i); //informa al usuario el numero de empleado que se esta ingresando
		printf("ingrese el tipo de alfajor (chocolate / dulce de leche / fruta / mixtos)"); //el empleado debe ingresar el tipo de alfajor que hizo
		scanf("%s", &tipo[i]);
		printf("ingrese la cantidad de alfajores producidos"); // el empleado debe ingresar la cantidad de alfajores que produjo
		scanf("%d", &num);
		
		
		cant = strlen(tipo[i]); //cuenta la cantidad de caracteres que tiene la palabra (incluye los espacios)
		
		//sinceramente nose como calcular el resto de una divicion, asi que decidi ignorar el resto en caso de que no sea un multiplo de 6
		
		
		
		//dependiendo de la cantidad de caracteres dictara que sabor de alfajor se ingreso
		
		if(cant == 9) //el sabor del alfajor es chocolate
		{
			
			acum1 = acum1 + num;
			
		}
		if(cant == 14) //el sabor del alfajor es dulce de leche 
		{
			acum2 = acum2 + num;
		}
		if(cant == 5) //el sabor del alfajor es fruta
		{
			acum3 = acum3 + num;
		}
		if(cant == 6) //el sabor del alfajor es mixtos
		{
			acum4 = acum4 + num;
		}
	}
	
	// se hace la divicion por 6 ya que es la cantidad e alfajores por caja, y se multiplica por el precio prestablecido 
	gana_c = (acum1 / 6) * P_choco;
	gana_d = (acum2 / 6) * P_dulce;
	gana_f = (acum3 / 6) * P_fruta;
	gana_m = (acum4 / 6) * P_mix;
	
	
	//se devuelve al usuario la gancia de los alfajores
	printf("la ganancia total de los alfajores de chocolate es de %d");
	printf("la ganancia total de los alfajores de dulce de leche es de %d");
	printf("la ganancia total de los alfajores de fruta es de %d");
	printf("la ganancia total de los alfajores mixtos es de %d");

	
	

}





