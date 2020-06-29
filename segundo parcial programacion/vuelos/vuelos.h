#ifndef VUELOS_H_INCLUDED
#define VUELOS_H_INCLUDED

typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[20];
    char destino[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}vuelos;

int vuelos_calcular_id(LinkedList* pArrayList_vuelos);


/** \brief crea una entidad de tipo Empleado de manera dinamica (sin campos cargados)
 *
 * \return Post* el puntero a la entidad
 *
 */
vuelos* vuelos_new();

/** \brief crea una entidad de tipo Empleado de manera dinamica (cargando los campos)
 *
 * \param idStr char* campo id de la entidad
 * \param nombreStr char* campo nombre de la entidad
 * \param horasTrabajadasStr char* campo horas trabajadas de la entidad
 * \param popularidadStr char* campo popularidad de la entidad
 * \return Post* el puntero a la entidad
 *
 */
vuelos* vuelos_newParametros(char* idVueloStr,char* idAvionStr,char* idPilotoStr,char* fechaStr,char* destinoStr,char* cantPasajerosStr,char* horaDespegueStr,char* HoraLlegadaStr);

int ContadorPasajeros(void* element);

int mostrar_vuelo(LinkedList* pArrayList_vuelos,LinkedList* pArrayLista_pilotos,int index);

int mostrar_todos_vuelos(LinkedList* pArrayList_vuelos,LinkedList* pArrayLista_pilotos);

vuelos* vuelos_load(LinkedList* pArrayList_vuelos);

int set_idVuelo(vuelos* this,int idVuelo);
int set_idAvion(vuelos* this,int idAvion);
int set_idPiloto(vuelos* this,int idPiloto);
int set_fecha(vuelos* this,char* fecha);
int set_destino(vuelos* this,char* destino);
int set_cantPasajeros(vuelos* this,int cantPasajeros);
int set_horaDespegue(vuelos* this,int horaDespegue);
int set_horaLlegada(vuelos* this,int horaLlegada);


int get_idVuelo(vuelos* this,int* idVuelo);
int get_idAvion(vuelos* this,int* idAvion);
int get_idPiloto(vuelos* this,int* idPiloto);
int get_fecha(vuelos* this,char* fecha);
int get_destino(vuelos* this,char* destino);
int get_cantPasajeros(vuelos* this,int* cantPasajeros);
int get_horaDespegue(vuelos* this,int* horaDespegue);
int get_horaLlegada(vuelos* this,int* horaLlegada);


int vuelos_find_by_id(vuelos* this, int id);

int vuelos_CompareByDestino(void* e1, void* e2);

int vuelos_por_destino(void* e1);

int vuelos_cortos(void* e1);

int vuelos_por_piloto(void* e1);


#endif // VUELOS_H_INCLUDED
