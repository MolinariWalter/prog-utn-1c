


/** \brief carga en un arrayList los datos desde un archivo de texto
 *
 * \param pFile FILE* puntero al archivo
 * \param pArrayList_vuelos LinkedList* puntero al arrayList
 * \return int retorna 1 si cargo los vuelos desde el archivo o 0 si hubo error
 *
 */
int parser_vuelos_FromText(FILE* pFile , LinkedList* pArrayList_vuelos);

/** \brief carga en un arrayList los datos desde un archivo binario
 *
 * \param pFile FILE* puntero al archivo
 * \param pArrayList_vuelos LinkedList* puntero al arrayList
 * \return int 1 si cargo los vuelos desde el archivo o 0 si hubo error
 *
 */
int parser_vuelos_FromBinary(FILE* pFile , LinkedList* pArrayList_vuelos);


int parser_pilotos_FromText(FILE* pFile , LinkedList* pArrayList_pilotos);
