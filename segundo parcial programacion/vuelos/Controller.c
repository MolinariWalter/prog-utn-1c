#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#include "vuelos.h"

#include "parser.h"

#include "Functions.h"

#define ASCENDENTE 0
#define DESCENDENTE 1




int controller_Molinari_load_vuelos_FromText(char* path, LinkedList* pArrayList_vuelos)
{
    int ret = 0;
    FILE* pFile;

    pFile = fopen(path,"r");

    if ( pFile != NULL)
    {
        if (pArrayList_vuelos != NULL && parser_vuelos_FromText(pFile,pArrayList_vuelos) )
        {
            ret = 1;
        }
        fclose(pFile);
    }
    return ret;
}
/// ok!!

int controller_Molinari_load_vuelos_FromBinary(char* path, LinkedList* pArrayList_vuelos)
{
    int ret = 0;
    FILE* pFile;

    pFile = fopen(path,"rb");

    if ( pFile != NULL)
    {
        if (pArrayList_vuelos != NULL && parser_vuelos_FromBinary(pFile,pArrayList_vuelos) )
        {
            ret = 1;
        }
        fclose(pFile);
    }
    return ret;
}
/// ok!!



int controller_Molinari_add_vuelos(LinkedList* pArrayList_vuelos)
{
    int ret = 0;

    if ( pArrayList_vuelos != NULL)
    {

        if (ll_add(pArrayList_vuelos,vuelos_load(pArrayList_vuelos)) == 0)
        {
            ret = 1;
        }
    }

    return ret;
}
/// ok!!

/*
int controller_edit_vuelos(LinkedList* pArrayList_vuelos)
{
    int ret = 0;
    int i;
    int index = -1;
    int id;

    vuelos* vuelos_Aux;
    vuelos user;

    /// tamaño de la lista
    int len = ll_len(pArrayList_vuelos);

    /// pido id
    UTN_getNumberInt(&id,"\nIngrese el id del usuario que quiere modifiar: ","\nError, id fuera de rango..",0,len,3);

    /// busco index del id
    for ( i=0;i<len;i++)
    {
        if ( vuelos_find_by_id( ll_get(pArrayList_vuelos,i) ,id) == 1 )
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {

        /// obtengo el empleado en ese index y lo copio en aux
        vuelos_Aux = (vuelos*)ll_get(pArrayList_vuelos,index);

        /// si no obtengo NULL
        if (vuelos_Aux != NULL)
        {
            printf("\n%4s%25s%15s\n", "id", "nick", "popularidad");
            printf("%4d%25s%15d\n\n",vuelos_Aux->id,vuelos_Aux->nick,vuelos_Aux->popularidad);

            user = *vuelos_Aux;
            /// modifico el empleado auxiliar
            ret = modificar_vuelos(&user);

            if (ret==1)
            {
                *vuelos_Aux = user;
            }
        }
    }

    return ret;
}
/// ok!!
*/


int controller_Molinari_remove_vuelos(LinkedList* pArrayList_vuelos)
{
    int ret = 0;
    int index = -1;
    int id = -1;
    int max;

    int i;
    int len;

    if (pArrayList_vuelos != NULL)
    {
        len = ll_len(pArrayList_vuelos);
        max = vuelos_calcular_id(pArrayList_vuelos);
        max--;

        UTN_getNumberInt(&id,"Ingrese el id que quiere remover: ","\nError,el id esta fuera de rango.\n",0,max,3);///

        if(id != -1)
        {
                   /// busco index del id
                for ( i=0;i<len;i++)
                {
                    if ( vuelos_find_by_id( ll_get(pArrayList_vuelos,i) ,id) == 1 )
                    {
                        index = i;
                        break;
                    }
                }

                ll_remove(pArrayList_vuelos,index);
                ret = 1;
        }


    }

    return ret;
}
/// ok!!

int controller_Molinari_List_vuelo_determinado(LinkedList* pArrayList_vuelos,char* destinoStr)
{
    int ret = 0;
    int i;
    vuelos* aux;

    if (pArrayList_vuelos != NULL)
    {
        int size = ll_len(pArrayList_vuelos);

        for(i=0; i<size; i++)
        {

            if(i==0)
            {
                printf("%15s %15s %25s %15s %15s %15s %15s %15s\n",
                       "idVuelo",
                       "idAvion",
                       "idPiloto",
                       "fecha",
                       "destino",
                       "cantPasajeros",
                       "horaDespegue",
                       "horaLlegada");
            }

            aux =(vuelos*) ll_get(pArrayList_vuelos, i);


            if( strcmpi(aux->destino,destinoStr) == 0 )
            {
                printf("%15d %15d %25d %10s %15s %15d %15d %15d\n",
                aux->idVuelo,
                aux->idAvion,
                aux->idPiloto,
                aux->fecha,
                aux->destino,
                aux->cantPasajeros,
                aux->horaDespegue,
                aux->horaLlegada);
                ret = 1;
            }

        }
    }

    return ret;
}


int controller_Molinari_List_vuelos(LinkedList* pArrayList_vuelos,LinkedList* pArrayLista_pilotos)
{
    int ret = 0;

    if (pArrayList_vuelos != NULL)
    {
        ret = mostrar_todos_vuelos(pArrayList_vuelos,pArrayLista_pilotos);
    }

    return ret;
}
/// ok!!

int controller_Molinari_sort_vuelos(LinkedList* pArrayList_vuelos)
{
    int ret = 0;

    if(pArrayList_vuelos != NULL)
    {
        ret = ll_sort(pArrayList_vuelos,vuelos_CompareByDestino,1);
    }

    return ret;
}
/// ok!!


int controller_Molinari_vuelos_saveAsText(char* path, LinkedList* pArrayList_vuelos)
{
    int ret = 0;
    int i;
    vuelos* aux;
    FILE* pFile;

    char idVuelo[50];
    char idAvion[50];
    char idPiloto[50];

    char cantPasajeros[50];
    char horaDespegue[50];
    char horaLlegada[50];


    int size = ll_len(pArrayList_vuelos);

    pFile = fopen(path,"w");

    if ( pFile != NULL)
    {
        if( pArrayList_vuelos != NULL)
        {
            fprintf(pFile,"%s%s%s%s%s%s%s%s\n",
                       "idVuelo",
                       "idAvion",
                       "idPiloto",
                       "fecha",
                       "destino",
                       "cantPasajeros",
                       "horaDespegue",
                       "horaLlegada");

            for( i=0 ; i<size ; i++)
            {
                aux =(vuelos*) ll_get(pArrayList_vuelos, i);

                itoa(aux->idVuelo,idVuelo,10);
                itoa(aux->idAvion,idAvion,10);
                itoa(aux->idPiloto,idPiloto,10);


                itoa(aux->cantPasajeros,cantPasajeros,10);
                itoa(aux->horaDespegue,horaDespegue,10);
                itoa(aux->horaLlegada,horaLlegada,10);

                fprintf(pFile,"%s%s%s%s%s%s%s%s\n",idVuelo,idAvion,idPiloto,aux->fecha,aux->destino,cantPasajeros,horaDespegue,horaLlegada );
            }
        }
        fclose(pFile);
        ret = 1;
    }

    return ret;
}
/// ok!!

int controller_Molinari_vuelos_saveAsBinary(char* path, LinkedList* pArrayList_vuelos)
{
    int ret = 0;
    int i;
    vuelos* aux;

    FILE* pFile;

    int size = ll_len(pArrayList_vuelos);

    int size_load = 0;


    pFile = fopen(path,"wb");

    if ( pFile != NULL)
    {

        if( pArrayList_vuelos != NULL)
        {

            for( i=0 ; i<size ; i++)
            {
                aux =(vuelos*) ll_get(pArrayList_vuelos, i);

                size_load += fwrite(aux,sizeof(vuelos),1,pFile);

                ret = 1;

            }
            if(size_load != size)
            {
                ret = -1;
            }
        }

        fclose(pFile);
    }

    return ret;
}
/// ok!!

int controller_Molinari_load_pilotos_FromText(char* path , LinkedList* pArrayLista_pilotos)
{
    int ret = 0;
    FILE* pFile;

    pFile = fopen(path,"r");

    if ( pFile != NULL)
    {
        if (pArrayLista_pilotos != NULL && parser_pilotos_FromText(pFile,pArrayLista_pilotos) )
        {
            ret = 1;
        }
        fclose(pFile);
    }
    return ret;
}




