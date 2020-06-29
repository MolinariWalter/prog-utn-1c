#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;

    do
    {
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        printf("5. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                printf("Estoy sumando!!!\n");
                break;
            case 2:
                printf("Estoy restando!!!\n");
                break;
            case 3:

                printf("Estoy multiplicando!!!\n");
                break;
            case 4:

                printf("Estoy dividiendo!!!\n");
                break;

        }
        system("pause");
        system("cls");
    }while(opcion!=5);
    return 0;
}
