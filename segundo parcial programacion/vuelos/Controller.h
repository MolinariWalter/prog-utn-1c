
/** \brief carga los datos de los vuelos y los agrega a una lista ligada
 *
 * \param path char* ruta del archivo desde donde se cargaran los datos
 * \param pArrayList_vuelos LinkedList* puntero a la lista ligada
 * \return int 0 si no pudo cargar desde el archivo [null pointer], 1 si la carga fue exitosa
 *
 */
int controller_Molinari_load_vuelos_FromText(char* path , LinkedList* pArrayList_vuelos);

/** \brief carga los datos de los vuelos y los agrega a una lista ligada
 *
 * \param path char* ruta del archivo desde donde se cargaran los datos
 * \param pArrayList_vuelos LinkedList* puntero a la lista ligada
 * \return int 0 si no pudo cargar desde el archivo [null pointer], 1 si la carga fue exitosa
 *
 */
int controller_Molinari_load_vuelos_FromBinary(char* path , LinkedList* pArrayList_vuelos);

/** \brief agrega un vuelos a la lista
 *
 * \param pArrayList_vuelos LinkedList* puntero a la lista ligada
 * \return int 0 si no pudo agregar el vuelos [null pointer], 1 si la carga fue exitosa
 *
 */
int controller_Molinari_add_vuelos(LinkedList* pArrayList_vuelos);

/** \brief edita los datos de un vuelos
 *
 * \param pArrayList_vuelos LinkedList* puntero a la lista ligada
 * \return int 0 error al editar [null pointer], -1 si la operacion fue cancelada, 1 si modifico los datos con exito
 *
 */
int controller_Molinari_edit_vuelos(LinkedList* pArrayList_vuelos);

/** \brief remueve a un vuelos de la lista
 *
 * \param pArrayList_vuelos LinkedList* puntero a la lista ligada
 * \return int 0 error al remover [null pointer], 1 si la operacion fue exitosa
 *
 */
int controller_Molinari_remove_vuelos(LinkedList* pArrayList_vuelos);

/** \brief muestra por consola la lista de los vuelos
 *
 * \param pArrayList_vuelos LinkedList* puntero a la lista ligada
 * \return int 0 error al mostrar [null pointer], 1 si la operacion fue exitosa
 *
 */
int controller_Molinari_List_vuelos(LinkedList* pArrayList_vuelos,LinkedList* pArrayLista_pilotos);


int controller_Molinari_List_vuelo_determinado(LinkedList* pArrayList_vuelos,char* destinoStr);




/** \brief ordena la lista de vuelos
 *
 * \param pArrayList_vuelos LinkedList* puntero a la lista ligada
 * \return int 0 si la operacion fue exitosa
 *
 */
int controller_Molinari_sort_vuelos(LinkedList* pArrayList_vuelos);

/** \brief guarda los cambio realizados en el archivo en modo texto
 *
 * \param path char* ruta del archivo desde donde se cargaran los datos
 * \param pArrayList_vuelos LinkedList* puntero a la lista ligada
 * \return int 0 error al gurdar [null pointer], 1 si la operacion fue exitosa
 *
 */
int controller_Molinari_vuelos_saveAsText(char* path , LinkedList* pArrayList_vuelos);

/** \brief guarda los cambio realizados en el archivo en modo binario
 *
 * \param path char* ruta del archivo desde donde se cargaran los datos
 * \param pArrayList_vuelos LinkedList* puntero a la lista ligada
 * \return int 0 error al remover [null pointer], 1 si la operacion fue exitosa
 *
 */
int controller_Molinari_vuelos_saveAsBinary(char* path , LinkedList* pArrayList_vuelos);



int controller_Molinari_load_pilotos_FromText(char* path , LinkedList* pArrayLista_pilotos);

