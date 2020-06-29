#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Functions.h"

#include "LinkedList.h"
#include "piloto.h"



piloto* piloto_new(void)
{
    piloto* aux = NULL;

    aux = (piloto*)malloc(sizeof(piloto));

    return aux;
}

piloto* piloto_newParametros(char* idPilotoStr,char* nombrestr)
{
    piloto* aux = piloto_new();


    if (idPilotoStr != NULL && nombrestr != NULL )
    {

        piloto_set_idPiloto(aux, atoi(idPilotoStr) );
        piloto_set_nombre_piloto(aux,nombrestr);
    }
    return aux;
}

int pilotos_new_harcodeado(LinkedList* pArrayLista_pilotos)
{
    int ret = 0;
    int i;
    int id[5]={1,2,3,4,5};
    char nombreAux[5][30]={"Alex Lifeson","Richard Bach","John Kerry","Erwin Rommel","Stephen Coonts"};

    for(i=0;i<5;i++)
    {
         piloto* aux = piloto_new();

         piloto_set_idPiloto(aux,id[i]);
         piloto_set_nombre_piloto(aux,nombreAux[i]);

         ll_add(pArrayLista_pilotos,aux);
         ret = 1;
    }

    return ret;
}




int piloto_set_idPiloto(piloto* this, int idPiloto)
{
    int ret = 0;

    if ( this != NULL)
    {
        this->idPiloto = idPiloto;
        ret = 1;
    }
    return ret;
}

int piloto_set_nombre_piloto(piloto* this, char* nombre)
{
    int ret = 0;

    if ( this != NULL)
    {
        strcpy(this->nombre,nombre);
        ret = 1;
    }
    return ret;
}

int piloto_get_idPiloto(piloto* this, int* idPiloto)
{
    int ret = 0;

    if ( this != NULL)
    {
        *idPiloto = this->idPiloto;
        ret = 1;
    }
    return ret;
}

int piloto_get_nombre_piloto(piloto* this, char* nombre)
{
    int ret = 0;

    if ( this != NULL && strcmp(nombre, strcpy(nombre, this->nombre) ) == 0 )
    {
        ret = 1;
    }
    return ret;
}


int piloto_por_nombre(void* element,char* parametro)
{
    int ret = 0;
    piloto* aux = (piloto*)element;
    char nombre[50];

    if(element != NULL && parametro != NULL)
    {
        piloto_get_nombre_piloto(aux,nombre);
        ret = stricmp(nombre,parametro);
    }

    return ret;
}
