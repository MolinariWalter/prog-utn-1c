#include <stdio.h>
#include <stdlib.h>

int main()
{
     int numero1, numero2,suma, resta, producto;
     float promedio;
    printf("\n Ingrese el primer entero :");
    scanf("%d", &numero1);
    printf("\n Ingrese el segundo entero : ");
    scanf("%d", &numero2);

    suma=numero1+numero2;
    resta=numero1-numero2;
    producto=numero1*numero2;
    promedio=(float)suma/2;


    printf("\n la suma es : %d", suma);
    printf("\n la resta es : %d", resta);
    printf("\n el producto es : %d", producto);
    printf("\n el promedio es : %.2f", promedio);
    return 0;
}
