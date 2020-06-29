#include <stdlib.h>
#include "Post.h"
#include <string.h>
#include "Functions.h"


Post* Post_new()
{
    Post* emp = NULL;

    emp = (Post*) malloc(sizeof(Post));

    return emp;
}
/// ok!!

Post* Post_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* popularidadStr)
{
    Post* emp = Post_new();
    if ( emp != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && popularidadStr != NULL)
    {
        Post_setId(emp,atoi(idStr));
        Post_setNombre(emp,nombreStr);
        Post_setHorasTrabajadas(emp,atoi(horasTrabajadasStr));
        Post_setpopularidad(emp,atoi(popularidadStr));
    }
    return emp;
}
/// ok!!

int Post_setNombre(Post* this,char* nombre)
{
    int ret = 0;

    if ( this != NULL && nombre != NULL )
    {
        strcpy(this->nombre, nombre);
        ret = 1;
    }

    return ret;
}
/// ok!!

int Post_getNombre(Post* this,char* nombre)
{
    int ret = 0;

    if ( this != NULL && strcmp(nombre, strcpy(nombre, this->nombre)    ) == 0 )
    {
        ret = 1;
    }

    return ret;
}
/// ok!!

int Post_setpopularidad(Post* this,int popularidad)
{
    int ret = 0;

    if ( this != NULL)
    {
        this->popularidad = popularidad;
        ret = 1;
    }

    return ret;
}
/// ok!!

int Post_getpopularidad(Post* this,int* popularidad)
{
    int ret = 0;

    if ( this != NULL)
    {
        *popularidad = this->popularidad;
        ret = 1;
    }

    return ret;
}
/// ok!!

int Post_setId(Post* this,int id)
{
    int ret = 0;

    if ( this != NULL)
    {
        this->id = id;
        ret = 1;
    }
    return ret;
}
/// ok!!

int Post_getId(Post* this,int* id)
{
    int ret = 0;

    if ( this != NULL)
    {
        *id = this->id;
        ret = 1;
    }
    return ret;
}
/// ok!!

int Post_setHorasTrabajadas(Post* this,int horasTrabajadas)
{
    int ret = 0;

    if ( this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        ret = 1;
    }

    return ret;
}
/// ok!!

int Post_getHorasTrabajadas(Post* this,int* horasTrabajadas)
{
    int ret = 0;

    if ( this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        ret = 1;
    }

    return ret;
}
/// ok!!

int Post_CompareByName(void* e1, void* e2)
{
    int ret = 0;
    Post* emp1 = (Post*)e1;
    Post* emp2 = (Post*)e2;

    if ( emp1 != NULL && emp2 != NULL)
    {
        ret = strcmp(emp1->nombre, emp2->nombre);
    }

    return ret;
}
/// ok!!

int Post_CompareById(void* e1, void* e2)
{
    int ret = -10;
    Post* emp1 = (Post*)e1;
    Post* emp2 = (Post*)e2;

    if (emp1 != NULL && emp2 != NULL)
    {
        if(emp1->id > emp2->id)
        {
            ret = 1;
        }else
            {
                if(emp1->id < emp2->id)
                {
                    ret = -1;
                } else
                    {
                        ret = 0;
                    }
            }
    }

    return ret;
}
/// ok!!

Post* Post_load(LinkedList* pArrayListPost)
{
    Post* empAux = NULL;
    char id[20];
    char nombre[50];
    char horas[50];
    char popularidad[50];

    int horasAux;
    int popularidadAux;
    int idAux;

    if (pArrayListPost != NULL)
    {
        if ( UTN_getStringName(nombre,sizeof(nombre),"Ingrese el nombre del empleado: ","Error.\n",3) &&
            UTN_getNumberInt(&horasAux,"Ingrese las horas trabajadas del empleado: ","Error.\n",1,100,3) &&
            UTN_getNumberInt(&popularidadAux,"Ingrese el popularidad del empleado: ","Error.\n",1000,100000,3) )
        {
            itoa(horasAux,horas,10);
            itoa(popularidadAux,popularidad,10);
            idAux = Post_calcular_id(pArrayListPost);
            itoa(idAux,id,10);

            empAux = Post_newParametros(id,nombre,horas,popularidad);
        }
    }
    return empAux;
}
/// ok!!

int Post_calcular_id(LinkedList* pArrayListPost)
{
    int len;
    int i;
    int max;
    Post* aux;

    if ( pArrayListPost != NULL)
    {
        len = ll_len(pArrayListPost);
        for(i=0;i<len;i++)
         {
             aux = ll_get(pArrayListPost,i);

             if(i==0 || aux->id > max)
             {
                 max = aux->id;
             }
         }

    }

    return max+1;
}
/// ok!!

void Post_delete(LinkedList* pArrayListPost,int index)
{
    ll_remove(pArrayListPost,index);
}
/// ok!!

int modificar_empleado(Post* this)
{
    int ret = 0;

    char nombre[50];
    int horas;
    int popularidad;

    int opcion;
    char salir = 'n';
    char guardar;

    do
    {
        UTN_getNumberInt(&opcion,"1.Modificar nombre\n2.Modificar horas trabajadas\n3.Modificar popularidad\n4.Guardar cambios\nElija que dato desea modificar :","Error, opcion incorrecta\n",0,4,5);

        switch(opcion)
        {
            case 1:
                    if (UTN_getStringName(nombre,sizeof(nombre),"Ingrese el nombre :","Error.\n",3))
                    {
                        ret = Post_setNombre(this,nombre);
                    }
            break;
            case 2:
                    if (UTN_getNumberInt(&horas,"Ingrese las horas trabajadas: ","Error.\n",0,100,3))
                    {
                        ret = Post_setHorasTrabajadas(this,horas);
                    }
            break;
            case 3:
                    if (UTN_getNumberInt(&popularidad,"Ingrese el popularidad: ","Error.\n",1000,100000,3))
                    {
                        ret = Post_setpopularidad(this,popularidad);
                    }
            break;
            case 4:

                    if (UTN_getOption_char(&guardar,"Desea gurdar los cambios realizados?: s/n","\nError, ingrese s/n.\n",'s','n',3) )
                    {
                        if (guardar=='s')
                        {
                            salir = 's';
                            ret = 1;

                        }else if (guardar=='n')
                            {
                                salir = 's';
                                ret = -1;
                            }
                    }

            break;
        }

    }while(salir != 's');

    return ret;
}
/// ok!!

int Post_find_by_id(Post* this, int id)
{
    int ret = -1;

    if ( this->id == id)
    {
        ret = 1;
    }

    return ret;
}
/// ok!!




