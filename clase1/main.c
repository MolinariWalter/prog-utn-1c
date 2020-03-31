#include <stdio.h>
#include <stdlib.h>

int main()
{
     int numero1,numero2,numero3,numMax;

    printf("\n ingrese el primer numero :");
    scanf("%d",&numero1);
    printf("\n ingrese el segundo numero :");
    scanf("%d",&numero2);
    printf("\n ingrese el tercer numero :");
    scanf("%d",&numero3);
    numMax=numero1;

    if(numero2>numMax){

        numMax=numero2;
    }
    if(numero3>numMax){

        numMax=numero3;
    }
    printf("\n El numero maximo ingresado es : %d", numMax);


    return 0;
}
