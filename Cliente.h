#include "ArrayList.h"
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
        int idCliente;
        char nombre[50];
        char apellido[50];
        char dni[50];
        int estadoCliente;
}Cliente;

#endif // CLIENTE_H_INCLUDED

#define ESTADO_CLIENTE_ACTIVO 1
#define ESTADO_CLIENTE_INACTIVO 0


Cliente* cliente_new(int idCliente,char* nombre,char* apellido,char* dni,int estadoCliente);
void cliente_delete(Cliente* this);
int cliente_setIdCliente(Cliente* this,int idCliente);
int cliente_setNombre(Cliente* this,char* nombre);
int cliente_setApellido(Cliente* this,char* apellido);
int cliente_setDni(Cliente* this,char* dni);
int cliente_setEstadoCliente(Cliente* this,int estadoCliente);
int cliente_getIdCliente(Cliente* this);
char* cliente_getNombre(Cliente* this);
char* cliente_getApellido(Cliente* this);
char* cliente_getDni(Cliente* this);
int cliente_getEstadoCliente(Cliente* this);
Cliente* cliente_findByIdCliente(ArrayList* pArray,int idCliente);
Cliente* cliente_findByNombre(ArrayList* pArray,char* nombre);
Cliente* cliente_findByApellido(ArrayList* pArray,char* apellido);
Cliente* cliente_findByDni(ArrayList* pArray,char* dni);
Cliente* cliente_findByEstadoCliente(ArrayList* pArray,int estadoCliente);
int cliente_compareByIdCliente(void* pA ,void* pB);
int cliente_compareByNombre(void* pA ,void* pB);
int cliente_compareByApellido(void* pA ,void* pB);
int cliente_compareByDni(void* pA ,void* pB);
int cliente_compareByEstadoCliente(void* pA ,void* pB);

