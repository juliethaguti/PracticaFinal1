
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Ventas.h"

Ventas* ventas_new(int idVentas,int idClientes,int codigoProducto,int cantidad,int estadoVentas)
{
        Ventas* this = malloc(sizeof(Ventas));

        if(this != NULL)
        {

                ventas_setIdVentas(this,idVentas);
                ventas_setIdClientes(this,idClientes);
                ventas_setCodigoProducto(this,codigoProducto);
                ventas_setCantidad(this,cantidad);
                if(codigoProducto == TV_LG_32)
                {
                    ventas_setPrecioProducto(this,PRECIO_1000);
                }
                if(codigoProducto == PS4)
                {
                    ventas_setPrecioProducto(this,PRECIO_1001);
                }
                if(codigoProducto == IPHONE7)
                {
                    ventas_setPrecioProducto(this,PRECIO_1002);
                }
                ventas_setEstadoVentas(this,estadoVentas);

        }
        return this;
}

void ventas_delete(Ventas* this)
{
        free(this);
}

int ventas_setIdVentas(Ventas* this,int idVentas)
{
        this->idVentas = idVentas;
        return 0;
}

int ventas_setIdClientes(Ventas* this,int idClientes)
{
        this->idClientes = idClientes;
        return 0;
}

int ventas_setCodigoProducto(Ventas* this,int codigoProducto)
{
        this->codigoProducto = codigoProducto;
        return 0;
}

int ventas_setCantidad(Ventas* this,int cantidad)
{
        this->cantidad = cantidad;
        return 0;
}

int ventas_setEstadoVentas(Ventas* this,int estadoVentas)
{
        this->estadoVentas = estadoVentas;
        return 0;
}

int ventas_setPrecioProducto(Ventas* this,float precioProducto)
{
        this->precioUnitarioProducto = precioProducto;
        return 0;
}

int ventas_getIdVentas(Ventas* this)
{
        return this->idVentas;
}

int ventas_getIdClientes(Ventas* this)
{
        return this->idClientes;
}

int ventas_getCodigoProducto(Ventas* this)
{
        return this->codigoProducto;
}

int ventas_getCantidad(Ventas* this)
{
        return this->cantidad;
}

int ventas_getEstadoVentas(Ventas* this)
{
        return this->estadoVentas;
}

float ventas_getPrecioUnitario(Ventas* this)
{
    return this-> precioUnitarioProducto;
}

Ventas* ventas_findByIdVentas(ArrayList* pArray,int idVentas)
{

        int i;
        Ventas* aux;
        Ventas* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idVentas == ventas_getIdVentas(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Ventas* ventas_findByIdClientes(ArrayList* pArray,int idClientes)
{

        int i;
        Ventas* aux;
        Ventas* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idClientes == ventas_getIdClientes(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Ventas* ventas_findByCodigoProducto(ArrayList* pArray,int codigoProducto)
{

        int i;
        Ventas* aux;
        Ventas* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(codigoProducto == ventas_getCodigoProducto(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Ventas* ventas_findByCantidad(ArrayList* pArray,int cantidad)
{

        int i;
        Ventas* aux;
        Ventas* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(cantidad == ventas_getCantidad(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Ventas* ventas_findByEstadoVentas(ArrayList* pArray,int estadoVentas)
{

        int i;
        Ventas* aux;
        Ventas* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(estadoVentas == ventas_getEstadoVentas(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int ventas_compareByIdVentas(void* pA ,void* pB)
{

        int retorno = 0;

        if(ventas_getIdVentas(pA) > ventas_getIdVentas(pB))
                retorno = 1;
        else if(ventas_getIdVentas(pA) < ventas_getIdVentas(pB))
                retorno = -1;

        return retorno;
}

int ventas_compareByIdClientes(void* pA ,void* pB)
{

        int retorno = 0;

        if(ventas_getIdClientes(pA) > ventas_getIdClientes(pB))
                retorno = 1;
        else if(ventas_getIdClientes(pA) < ventas_getIdClientes(pB))
                retorno = -1;

        return retorno;
}

int ventas_compareByCodigoProducto(void* pA ,void* pB)
{

        int retorno = 0;

        if(ventas_getCodigoProducto(pA) > ventas_getCodigoProducto(pB))
                retorno = 1;
        else if(ventas_getCodigoProducto(pA) < ventas_getCodigoProducto(pB))
                retorno = -1;

        return retorno;
}

int ventas_compareByCantidad(void* pA ,void* pB)
{

        int retorno = 0;

        if(ventas_getCantidad(pA) > ventas_getCantidad(pB))
                retorno = 1;
        else if(ventas_getCantidad(pA) < ventas_getCantidad(pB))
                retorno = -1;

        return retorno;
}

int ventas_compareByEstadoVentas(void* pA ,void* pB)
{

        int retorno = 0;

        if(ventas_getEstadoVentas(pA) > ventas_getEstadoVentas(pB))
                retorno = 1;
        else if(ventas_getEstadoVentas(pA) < ventas_getEstadoVentas(pB))
                retorno = -1;

        return retorno;
}

void ventas_imprimeVenta(Ventas* auxVentas)
{
    float montoFacturado;
    montoFacturado = ventas_getCantidad(auxVentas) * ventas_getPrecioUnitario(auxVentas);
    printf("\n\nID: %d - CANTIDAD %d: - MONTO FACTURADO: %.2f",ventas_getIdVentas(auxVentas),ventas_getCantidad(auxVentas),montoFacturado);

}
