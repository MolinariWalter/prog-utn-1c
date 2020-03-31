#include <stdio.h>
#include <stdlib.h>

int main()
{
    int main()
{
    int numero;
    int contadorPares = 0;

    char seguir = 's';

    while(seguir == 's')
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        if(numero%2 == 0)
        {
            contadorPares++;
        }


        printf("Desea ingresar otro numero?");
        __fpurge(stdin);
        scanf("%c", &seguir);

    }


    printf("Cantidad de pares: %d\n", contadorPares);


    return 0;
}
