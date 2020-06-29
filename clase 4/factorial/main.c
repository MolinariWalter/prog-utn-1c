/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int getFactorial(int);

int main()
{
    int resultado;
    resultado=getFactorial(5);

    printf("el factorial de 5 es %d",resultado);

    return 0;
}

int getFactorial(int numero)
{
   int factorial;

   factorial=numero;//*numero;


    for(numero;numero!=0;numero--)
    {

        factorial+=(numero-1)*factorial;
        //factorial+=(numero-1)*numero;

    }
    return factorial;
}
