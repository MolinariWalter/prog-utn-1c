#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"

#include "vuelos.h"
#include "piloto.h"

#include "Functions.h"



/****************************************************
    Menu:
     1. Cargar archivo
     2. Imprimir vuelos
     3. Cantidad de pasajeros
     4. Cantidad de pasajeros a irlanda
     5. Filtrar vuelos cortos
     6. Listar vuelos a portugal
     7. Filtrar a Alex Lifeson

*****************************************************/


int main()
{
    int option = -1;
    char path_vuelos[]="Vuelos.csv";
    char path_pilotos[]="pilotos.csv";



    LinkedList* Lista_vuelos = ll_newLinkedList();
    LinkedList* Lista_pilotos = ll_newLinkedList();
    //pilotos_new_harcodeado(Lista_pilotos);

    LinkedList* Lista_vuelos_irlanda = ll_newLinkedList();
    LinkedList* Lista_vuelos_cortos = ll_newLinkedList();
    LinkedList* Lista_piloto_Determinado = ll_newLinkedList();
    LinkedList* Lista_vuelos_por_nombre = ll_newLinkedList();


    do
    {
        printf("%s%s%s%s%s%s%s%s%s",
               "1. Cargar el archivo Vuelos.csv (modo texto).\n",
               "2. Imprimir vuelos.\n",
               "3. Cantidad de pasajeros.\n",
               "4. Cantidad de pasajeros a irlanda.\n",
               "5. Filtrar vuelos cortos.\n",
               "6. Listar vuelos a portugal.\n",
               "7. Filtrar a Alex Lifeson.\n",
               "8. Filtrar la lista de pilotos por nombre. \n",
               "9. salir\n");


        UTN_getNumberInt(&option,"Ingrese una opcion: ","\nError.\n",1,8,1);

        switch(option)
        {
            case 1:// cargar desde archivo data.csv modo texto
                    system("cls");
                    printf("CARGAR DESDE EL ARCHIVO MODO TEXTO\n");
                    if (controller_Molinari_load_vuelos_FromText(path_vuelos,Lista_vuelos)&&
                           controller_Molinari_load_pilotos_FromText(path_pilotos,Lista_pilotos) )
                    {
                        printf("\nCarga correcta.\n");
                    }else
                        {
                            printf("\nError al cargar los datos.");
                        }
            break;
            case 2://cargar desde archivo data.csv modo binario
                    system("cls");
                    printf("IMPRIMIR VUELOS\n");
                    if ( controller_Molinari_List_vuelos(Lista_vuelos,Lista_pilotos))
                    {
                        printf("\nlistado correcto..\n");
                    }else
                    {
                        printf("\nerror al listar..\n");
                    }

            break;
            case 3://alta empleado
                    system("cls");
                    printf("CANTIDAD DE PASAJEROS\n");

                    printf("\nCantidad de pasajeros : %d\n",ll_count(Lista_vuelos,&ContadorPasajeros));


            break;
            case 4://modificar empleado
                    system("cls");
                    printf("CANTIDAD DE PASAJEROS A IRLANDA\n");

                    Lista_vuelos_irlanda = ll_filter(Lista_vuelos,&vuelos_por_destino);
                    printf("\nCantidad de pasajeros a Irlanda : %d\n",ll_count(Lista_vuelos_irlanda,&ContadorPasajeros));


            break;
            case 5://baja empleado
                    system("cls");
                    printf("FILTRAR VUELOS CORTOS\n");
                    Lista_vuelos_cortos = ll_filter(Lista_vuelos,&vuelos_cortos);
                    if ( controller_Molinari_List_vuelos(Lista_vuelos_cortos,Lista_pilotos))
                    {
                        printf("\nlistado correcto..\n");
                    }else
                    {
                        printf("\nerror al listar..\n");
                    }


            break;
            case 6://listar empleado
                    system("cls");
                    printf("LISTAR VUELOS A PORTUGAL\n");
                    if(controller_Molinari_List_vuelo_determinado(Lista_vuelos,"Portugal") == 1)
                    {
                        printf("listar correcto.\n");
                    }else
                    {
                        printf("error.\n");
                    }
            break;
            case 7://ordenar empleado
                    system("cls");
                    printf("FILTRAR A ALEX LIFESON\n");
                    Lista_piloto_Determinado = ll_filter(Lista_vuelos,&vuelos_por_piloto);

                    if ( controller_Molinari_List_vuelos(Lista_piloto_Determinado,Lista_pilotos) )
                    {
                        printf("\nlistado correcto..\n");
                    }else
                    {
                        printf("\nerror al listar..\n");
                    }




            break;
            case 8:
                    system("cls");
                    printf("FILTRAR VUELOS POR NOMBRE\n");
                    Lista_vuelos_por_nombre = ll_filter_parametro(Lista_vuelos,&piloto_por_nombre,"Erwin Rommel");

                    if ( controller_Molinari_List_vuelos(Lista_vuelos_por_nombre,Lista_pilotos))
                    {
                        printf("\nlistado correcto..\n");
                    }else
                    {
                        printf("\nerror al listar..\n");
                    }
            break;
            case 9://gurdar modo texto
                    system("cls");
                    printf("SALIR\n");

            break;

        }
        system("pause");
        system("cls");


    }while(option != 9);


    return 0;
}
