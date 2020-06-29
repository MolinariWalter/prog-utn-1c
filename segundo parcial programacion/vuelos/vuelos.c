#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Functions.h"

#include "LinkedList.h"
#include "vuelos.h"
#include "piloto.h"

vuelos* vuelos_new()
{
    vuelos* vuelo = NULL;

    vuelo = (vuelos*)malloc(sizeof(vuelos));

    return vuelo;
}

int vuelos_calcular_id(LinkedList* pArrayList_vuelos)
{
    int len;
    int i;
    int max;
    vuelos* aux;

    if ( pArrayList_vuelos != NULL)
    {
        len = ll_len(pArrayList_vuelos);
        for(i=0;i<len;i++)
         {
             aux = ll_get(pArrayList_vuelos,i);

             if(i==0 || aux->idVuelo > max)
             {
                 max = aux->idVuelo;
             }
         }

    }

    return max+1;
}

vuelos* vuelos_newParametros(char* idVueloStr, char* idAvionStr, char* idPilotoStr, char* fechaStr, char* destinoStr, char* cantPasajerosStr, char* horaDespegueStr, char* HoraLlegadaStr)
{
    vuelos* vuelo = vuelos_new();
    if ( vuelo != NULL && idVueloStr != NULL && idAvionStr != NULL && idPilotoStr != NULL && fechaStr != NULL &&  destinoStr != NULL && cantPasajerosStr != NULL && horaDespegueStr != NULL && HoraLlegadaStr != NULL )
    {
        set_idVuelo(vuelo,atoi(idVueloStr));
        set_idAvion(vuelo,atoi(idAvionStr));
        set_idPiloto(vuelo,atoi(idPilotoStr));

        set_fecha(vuelo,fechaStr);
        set_destino(vuelo,destinoStr);

        set_cantPasajeros(vuelo,atoi(cantPasajerosStr));
        set_horaDespegue(vuelo,atoi(horaDespegueStr));
        set_horaLlegada(vuelo,atoi(HoraLlegadaStr));
    }
    return vuelo;
}


int mostrar_vuelo(LinkedList* pArrayList_vuelos,LinkedList* pArrayLista_pilotos,int index)
{
    int ret = 0;

    vuelos* aux;
    piloto* auxPiloto;

    int i;
    int lenPilotos;

    int idVueloAux;
    int idAvionAux;
    int idPilotoAux;
    char fechaAux[50];
    char destinoAux[50];
    int cantPasajerosAux;
    int horaPartidaAux;
    int horaLLegadaAux;

    if(pArrayList_vuelos != NULL)
    {
        aux =(vuelos*) ll_get(pArrayList_vuelos, index);
        lenPilotos = ll_len(pArrayLista_pilotos);

        get_idVuelo(aux,&idVueloAux);
        get_idAvion(aux,&idAvionAux);
        get_idPiloto(aux,&idPilotoAux);
        get_fecha(aux,fechaAux);
        get_destino(aux,destinoAux);
        get_cantPasajeros(aux,&cantPasajerosAux);
        get_horaDespegue(aux,&horaPartidaAux);
        get_horaLlegada(aux,&horaLLegadaAux);

        for(i=0;i<lenPilotos;i++)
        {
            auxPiloto = (piloto*)ll_get(pArrayLista_pilotos,i);
            if(idPilotoAux == auxPiloto->idPiloto)
            {
                printf("%15d %15d %25s %15s %15s %15d %15d %15d\n",
                                                            idVueloAux,
                                                            idAvionAux,
                                                            auxPiloto->nombre,
                                                            fechaAux,
                                                            destinoAux,
                                                            cantPasajerosAux,
                                                            horaPartidaAux,
                                                            horaLLegadaAux);
                ret = 1;
                break;
            }

        }



    }

    return ret;
}

int mostrar_todos_vuelos(LinkedList* pArrayList_vuelos,LinkedList* pArrayLista_pilotos)
{
 int ret = 0;

    int i;
    int cont = 1;

    if (pArrayList_vuelos != NULL)
    {
        int size = ll_len(pArrayList_vuelos);

        for(i=0; i<size; i++)
        {
            if ( cont %45 == 0)
            {
                system("pause");
                printf("%15s %15s %25s %15s %15s %15s %15s %15s\n",
                       "idVuelo",
                       "idAvion",
                       "Piloto",
                       "fecha",
                       "destino",
                       "cantPasajeros",
                       "horaDespegue",
                       "horaLlegada");
            }
            cont++;

            if(i==0)
            {
                printf("%15s %15s %25s %15s %15s %15s %15s %15s\n",
                       "idVuelo",
                       "idAvion",
                       "Piloto",
                       "fecha",
                       "destino",
                       "cantPasajeros",
                       "horaDespegue",
                       "horaLlegada");
            }

            ret = mostrar_vuelo(pArrayList_vuelos,pArrayLista_pilotos,i);
        }
    }

    return ret;
}


vuelos* vuelos_load(LinkedList* pArrayList_vuelos)
{
    vuelos* Aux = NULL;

    int idVueloAux;
    int idAvionAux;
    int idPilotoAux;
    char fechaAux[50];
    char destinoAux[50];
    int cantPasajerosAux;
    int horaPartidaAux;
    int horaLLegadaAux;


    if (pArrayList_vuelos != NULL)
    {
        if (UTN_getNumberInt(&idAvionAux,"\n id avion :","\nError.",0,10000,3) &&
                UTN_getNumberInt(&idPilotoAux,"\n id piloto :","\nError.",0,10000,3) &&
                UTN_getStringName(fechaAux,sizeof(Aux->fecha),"\n fecha :","\nError.",3) &&
                UTN_getStringName(destinoAux,sizeof(Aux->destino),"\n destino :","\nError.",3) &&
                UTN_getNumberInt(&cantPasajerosAux,"\n cantidad de pasajeros :","\nError.",0,10000,3)&&
                UTN_getNumberInt(&horaPartidaAux,"\n hora despegue :","\nError.",0,24,3) &&
                UTN_getNumberInt(&horaLLegadaAux,"\n hora llegada :","\nError.",0,24,3)   )
        {

            Aux = vuelos_new();

            idVueloAux = vuelos_calcular_id(pArrayList_vuelos);

            set_idVuelo(Aux,idVueloAux);
            set_idAvion(Aux,idAvionAux);
            set_idPiloto(Aux,idPilotoAux);
            set_fecha(Aux,fechaAux);
            set_destino(Aux,destinoAux);
            set_cantPasajeros(Aux,cantPasajerosAux);
            set_horaDespegue(Aux,horaPartidaAux);
            set_horaLlegada(Aux,horaLLegadaAux);

        }
    }
    return Aux;}



/********* setters **********/
int set_idVuelo(vuelos* this, int idVuelo)
{
    int ret = 0;

    if ( this != NULL)
    {
        this->idVuelo = idVuelo;
        ret = 1;
    }
    return ret;
}

int set_idAvion(vuelos* this, int idAvion)
{
    int ret = 0;

    if ( this != NULL)
    {
        this->idAvion = idAvion;
        ret = 1;
    }
    return ret;
}

int set_idPiloto(vuelos* this, int idPiloto)
{
    int ret = 0;

    if ( this != NULL)
    {
        this->idPiloto = idPiloto;
        ret = 1;
    }
    return ret;
}

int set_fecha(vuelos* this, char* fecha)
{
    int ret = 0;

    if ( this != NULL)
    {
        strcpy(this->fecha,fecha);
        ret = 1;
    }
    return ret;
}

int set_destino(vuelos* this, char* destino)
{
    int ret = 0;

    if ( this != NULL)
    {
        strcpy(this->destino,destino);
        ret = 1;
    }
    return ret;
}

int set_cantPasajeros(vuelos* this, int cantPasajeros)
{
    int ret = 0;

    if ( this != NULL)
    {
        this->cantPasajeros = cantPasajeros;
        ret = 1;
    }
    return ret;
}

int set_horaDespegue(vuelos* this, int horaDespegue)
{
    int ret = 0;

    if ( this != NULL)
    {
        this->horaDespegue = horaDespegue;
        ret = 1;
    }
    return ret;
}

int set_horaLlegada(vuelos* this, int horaLlegada)
{
    int ret = 0;

    if ( this != NULL)
    {
        this->horaLlegada = horaLlegada;
        ret = 1;
    }
    return ret;
}


/********* getters **********/
int get_idVuelo(vuelos* this, int* idVuelo)
{
    int ret = 0;

    if ( this != NULL)
    {
        *idVuelo = this->idVuelo;
        ret = 1;
    }
    return ret;
}

int get_idAvion(vuelos* this, int* idAvion)
{
     int ret = 0;

    if ( this != NULL)
    {
        *idAvion = this->idAvion;
        ret = 1;
    }
    return ret;
}

int get_idPiloto(vuelos* this, int* idPiloto)
{
    int ret = 0;

    if ( this != NULL)
    {
        *idPiloto = this->idPiloto;
        ret = 1;
    }
    return ret;
}

int get_fecha(vuelos* this, char* fecha)
{
    int ret = 0;

    if ( this != NULL && strcmp(fecha, strcpy(fecha, this->fecha) ) == 0 )
    {
        ret = 1;
    }
    return ret;
}

int get_destino(vuelos* this, char* destino)
{
    int ret = 0;

    if ( this != NULL && strcmp(destino, strcpy(destino, this->destino) ) == 0 )
    {
        ret = 1;
    }
    return ret;
}

int get_cantPasajeros(vuelos* this, int* cantPasajeros)
{
    int ret = 0;

    if ( this != NULL)
    {
        *cantPasajeros = this->cantPasajeros;
        ret = 1;
    }
    return ret;
}

int get_horaDespegue(vuelos* this, int* horaDespegue)
{
    int ret = 0;

    if ( this != NULL)
    {
        *horaDespegue = this->horaDespegue;
        ret = 1;
    }
    return ret;
}

int get_horaLlegada(vuelos* this, int* horaLlegada)
{
    int ret = 0;

    if ( this != NULL)
    {
        *horaLlegada = this->horaLlegada;
        ret = 1;
    }
    return ret;
}


int ContadorPasajeros(void* element)
{
    int ret;

    if(element != NULL)
    {
        get_cantPasajeros(element,&ret);
        //ret = (vuelos*)element->cantPasajeros;
    }


    return ret;
}

int vuelos_find_by_id(vuelos* this, int id)
{
    int ret = -1;

    if ( this->idVuelo == id)
    {
        ret = 1;
    }

    return ret;
}

int vuelos_CompareByDestino(void* e1, void* e2)
{
    int ret = 0;
    vuelos* aux1 = (vuelos*)e1;
    vuelos* aux2 = (vuelos*)e2;

    if ( aux1 != NULL && aux2 != NULL)
    {
        ret = strcmp(aux1->destino, aux2->destino);
    }

    return ret;
}

int vuelos_por_destino(void* e1)
{
    int ret = 0;
    char destino[] = "Irlanda";
    vuelos* aux = (vuelos*)e1;

    if ( aux != NULL )
    {
        ret = strcmp(aux->destino,destino);
    }

    return ret;
}
int vuelos_cortos(void* e1)
{
    int ret = 0;

    vuelos* aux = (vuelos*)e1;

    if ( aux != NULL )
    {
        if( (aux->horaLlegada)-(aux->horaDespegue) < 3)
        {
            ret = 1;
        }
    }

    return ret;
}

int vuelos_por_piloto(void* e1)
{
    int ret = 0;
    int id = 1;
    vuelos* aux = (vuelos*)e1;

    if ( aux != NULL && aux->idPiloto == id)
    {

        ret = 1;
    }

    return ret;
}
