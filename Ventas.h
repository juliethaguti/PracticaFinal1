#include "ArrayList.h"
#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

typedef struct
{
        int idVentas;
        int idClientes;
        int codigoProducto;
        int cantidad;
        float precioUnitarioProducto;
        float montoFacturado;
        int estadoVentas;
}Ventas;

#endif // VENTAS_H_INCLUDED

#define ESTADO_VENTA_ACTIVA 1
#define ESTADO_VENTA_INACTIVA 0

#define TV_LG_32 1000
#define PS4 1001
#define IPHONE7 1002

#define PRECIO_1000 8999.99
#define PRECIO_1001 12999.99
#define PRECIO_1002 19480.99

Ventas* ventas_new(int idVentas,int idClientes,int codigoProducto,int cantidad,int estadoVentas);
void ventas_delete(Ventas* this);
int ventas_setIdVentas(Ventas* this,int idVentas);
int ventas_setIdClientes(Ventas* this,int idClientes);
int ventas_setCodigoProducto(Ventas* this,int codigoProducto);
int ventas_setCantidad(Ventas* this,int cantidad);
int ventas_setEstadoVentas(Ventas* this,int estadoVentas);
int ventas_setPrecioProducto(Ventas* this,float precioProducto);
int ventas_getIdVentas(Ventas* this);
int ventas_getIdClientes(Ventas* this);
int ventas_getCodigoProducto(Ventas* this);
int ventas_getCantidad(Ventas* this);
int ventas_getEstadoVentas(Ventas* this);
float ventas_getPrecioUnitario(Ventas* this);
Ventas* ventas_findByIdVentas(ArrayList* pArray,int idVentas);
Ventas* ventas_findByIdClientes(ArrayList* pArray,int idClientes);
Ventas* ventas_findByCodigoProducto(ArrayList* pArray,int codigoProducto);
Ventas* ventas_findByCantidad(ArrayList* pArray,int cantidad);
Ventas* ventas_findByEstadoVentas(ArrayList* pArray,int estadoVentas);
int ventas_compareByIdVentas(void* pA ,void* pB);
int ventas_compareByIdClientes(void* pA ,void* pB);
int ventas_compareByCodigoProducto(void* pA ,void* pB);
int ventas_compareByCantidad(void* pA ,void* pB);
int ventas_compareByEstadoVentas(void* pA ,void* pB);
void ventas_imprimeVenta(Ventas* auxVenta);
