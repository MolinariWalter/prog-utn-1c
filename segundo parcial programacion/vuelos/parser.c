#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
//#include "Post.h"

#include "vuelos.h"
#include "piloto.h"

#include <string.h>


int parser_vuelos_FromText(FILE* pFile, LinkedList* pArrayList_vuelos)
{
    int ret = 0;
    char idVuelo[50];
    char idAvion[50];
    char idPiloto[50];
    char fecha[20];
    char destino[50];
    char cantPasajeros[50];
    char horaDespegue[50];
    char horaLlegada[50];


    fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);

    if ( pFile != NULL && pArrayList_vuelos != NULL)
    {
        while( !feof(pFile))
        {
            if ( pFile != NULL )
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
                if (ll_add(pArrayList_vuelos, vuelos_newParametros(idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada)) == 0 )
                {
                    ret = 1;
                }
            }
        }
    }
    return ret;
}

int parser_vuelos_FromBinary(FILE* pFile, LinkedList* pArrayList_vuelos)
{
    int ret = 0;

    vuelos* aux;
    int len;
    int leido = 0;
    int agregado = 0;

    if ( pFile != NULL && pArrayList_vuelos != NULL)
    {

        while( !feof(pFile))
        {

            aux = vuelos_new();

            leido += fread(aux,sizeof(vuelos),1,pFile);

            if (ll_add(pArrayList_vuelos, aux) == 0)
            {
                agregado++;
                ret = 1;
            }

        }

        if ( leido != agregado)
        {
            len = ll_len(pArrayList_vuelos);
            ll_remove(pArrayList_vuelos,len);
        }

    }

    return ret;
}


int parser_pilotos_FromText(FILE* pFile, LinkedList* pArrayList_pilotos)
{
    int ret = 0;

    char idPiloto[50];
    char nombre[20];


    fscanf(pFile,"%[^,],%[^\n]\n",idPiloto,nombre);

    if ( pFile != NULL && pArrayList_pilotos != NULL)
    {
        while( !feof(pFile))
        {
            if ( pFile != NULL )
            {
                fscanf(pFile,"%[^,],%[^\n]\n",idPiloto,nombre);
                if (ll_add(pArrayList_pilotos, piloto_newParametros(idPiloto,nombre)) == 0 )
                {
                    ret = 1;
                }
            }
        }
    }
    return ret;
}

