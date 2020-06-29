#ifndef Post_H_INCLUDED
#define Post_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int popularidad;
}Post;

/** \brief crea una entidad de tipo Empleado de manera dinamica (sin campos cargados)
 *
 * \return Post* el puntero a la entidad
 *
 */
Post* Post_new();

/** \brief crea una entidad de tipo Empleado de manera dinamica (cargando los campos)
 *
 * \param idStr char* campo id de la entidad
 * \param nombreStr char* campo nombre de la entidad
 * \param horasTrabajadasStr char* campo horas trabajadas de la entidad
 * \param popularidadStr char* campo popularidad de la entidad
 * \return Post* el puntero a la entidad
 *
 */
Post* Post_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* popularidadStr);

/** \brief remueve un empleado de la lista
 *
 * \param pArrayListPost LinkedList* puntero a la lista ligada
 * \param index int indice en el cual se encuentra el empleado
 *
 */
void Post_delete(LinkedList* pArrayListPost,int index);

/** \brief setea el campo id
 *
 * \param this Post* entidad empleado
 * \param id int dato a setear
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int Post_setId(Post* this,int id);

/** \brief obtiene el id del empleado
 *
 * \param this Post* entidad empleado
 * \param id int* puntero id donde se guardara el dato obtenido
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int Post_getId(Post* this,int* id);

/** \brief setea el nombre del empleado
 *
 * \param this Post* entidad empleado
 * \param nombre char* dato a setear
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int Post_setNombre(Post* this,char* nombre);

/** \brief obtiene el nombre del empleado
 *
 * \param this Post* entidad empleado
 * \param nombre char* puntero nombre donde se gurdara el dato obtenido
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int Post_getNombre(Post* this,char* nombre);

/** \brief setea las horas trabajadas del empleado
 *
 * \param this Post* entidad empleado
 * \param horasTrabajadas int dato a setear
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int Post_setHorasTrabajadas(Post* this,int horasTrabajadas);

/** \brief obtiene las oras trabajadas del empleado
 *
 * \param this Post* entidad empleado
 * \param horasTrabajadas int* puntero horas trabajadas donde se gurdara el dato obtenido
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int Post_getHorasTrabajadas(Post* this,int* horasTrabajadas);

/** \brief setea el popularidad del empleado
 *
 * \param this Post* entidad empleado
 * \param popularidad int dato a setear
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int Post_setpopularidad(Post* this,int popularidad);

/** \brief obtiene el popularidad del empleado
 *
 * \param this Post* entidad empleado
 * \param popularidad int* puntero popularidad donde se gurdara el dato obtenido
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int Post_getpopularidad(Post* this,int* popularidad);

/** \brief compara alfabeticamente a dos empleados por nombre
 *
 * \param e1 void* puntero a un empleado
 * \param e2 void* puntero a otro empleado
 * \return int 0 si los nombres son iguales, positivo si el primero es mayor al segundo, negativo si el primero es menor al segundo
 *
 */
int Post_CompareByName(void* e1, void* e2);

/** \brief compara a dos empleados por su id
 *
 * \param e1 void* puntero a un empleado
 * \param e2 void* puntero a otro empleado
 * \return int -10 si hubo un error [null pointer], 1 si el primero es mayor al segundo, 0 si el primero es menor al segundo
 *
 */
int Post_CompareById(void* e1, void* e2);

/** \brief crea un nuevo empleado seteando los campos
 *
 * \param pArrayListPost LinkedList* puntero a la lista ligada
 * \return Post* el empleado creado
 *
 */
Post* Post_load(LinkedList* pArrayListPost);

/** \brief calcula el id para un nuevo empleado
 *
 * \param pArrayListPost LinkedList* puntero a la lista ligada
 * \return int el id creado
 *
 */
int Post_calcular_id(LinkedList* pArrayListPost);

/** \brief modifica los datos de un empleado
 *
 * \param this Post* entidad empleado a modificar
 * \return int 0 si hubo un error [null pointer], 1 operacion exitosa
 *
 */
int modificar_empleado(Post* this);

/** \brief verifica si existe un empleado con determinado id
 *
 * \param this Post* entidad empleado
 * \param id int id a buscar
 * \return int 0 si hubo un error [null pointer], 1 si encontro el empleado segun el id
 *
 */
int Post_find_by_id(Post* this, int id);


#endif // Post_H_INCLUDED
