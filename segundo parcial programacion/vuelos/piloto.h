#ifndef PILOTO_H_INCLUDED
#define PILOTO_H_INCLUDED

typedef struct
{
    int idPiloto;
    char nombre[50];

}piloto;

piloto* piloto_new(void);
int pilotos_new_harcodeado(LinkedList* pArrayLista_pilotos);
piloto* piloto_newParametros(char* idPilotoStr,char* nombrestr);



int piloto_set_idPiloto(piloto* this,int idPiloto);
int piloto_set_nombre_piloto(piloto* this,char* nombre);


int piloto_get_idPiloto(piloto* this,int* idPiloto);
int piloto_get_nombre_piloto(piloto* this,char* nombre);

int piloto_por_nombre(void* element,char* parametro);
#endif // PILOTO_H_INCLUDED
