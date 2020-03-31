#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contadorPares = 0;
    int contadorPositivos = 0;
    int contadorNegativos = 0;
    int contadorIngresos = 0;

    int maximo;
    int minimo;

    int suma = 0;
    float promedio;

    char seguir = 's';



    while(seguir == 's')
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        if(numero%2 == 0)
        {
            contadorPares++;
        }

        if(numero > 0)
        {
            contadorPositivos++;
        }
        else
        {
            if(numero < 0)
            {
                contadorNegativos++;
            }
        }

        suma += numero; // suma = suma + numero;


        if( numero>maximo || contadorIngresos == 0)
        {
            maximo = numero;

        }

        if(numero<minimo || contadorIngresos == 0)
        {
            minimo = numero;
        }




        contadorIngresos++;

        printf("Desea ingresar otro numero?");
        __fpurge(stdin);
        scanf("%c", &seguir);



    }

    promedio = (float) suma / contadorIngresos;


    printf("Cantidad de pares: %d\n", contadorPares);

    printf("Cantidad de positivos: %d\n", contadorPositivos);

    printf("Cantidad de negativos: %d\n", contadorNegativos);

    printf("El promedio de numeros es: %.2f\n", promedio);

    printf("EL maximo es: %d\n", maximo);
    printf("EL minimo es: %d\n", minimo);

    return 0;
}
