#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int resultado;
    numero = 1;
    resultado = calcularFactorial(numero);
    printf("El resultado es: %d", resultado);

    return 0;
}

int calcularFactorial(int numero)
{
    int resultado;
    if(numero==0)
    {
        resultado = 1;
    }
    else
    {
        resultado = numero * calcularFactorial(numero-1);
    }

    return resultado;
}
