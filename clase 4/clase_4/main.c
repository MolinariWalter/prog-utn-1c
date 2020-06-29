/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


/*
1. mantenibilidad
2. reutilizacion
3. depuracion
4. independencia del codigo
*/
//alcance - visibilidad - scope
//1 si es par o 0 si es impar

int esPar(int);
void mostrar();



int main()
{

   int esVerdadero;
   int numero ;
   mostrar();
   printf("\nNumero en MAIN %d", numero);


    printf("Ingrese un numero: ");
    scanf("%d", &numero);

   esVerdadero = esPar(numero);

   if(esVerdadero==1)
   {
       printf("Es par");
   }
   else
   {
       printf("Es impar");
   }


    return 0;
}

void mostrar()
{
    int numero;
    numero = 9;
    printf("NUMERO %d", numero);
}

int esPar(int numero)
{
    int esVerdadero = 0;


    if(numero%2==0)
    {
        esVerdadero = 1;
    }


    return esVerdadero;

}
