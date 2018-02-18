#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Informes.h"
#include "ArrayList.h"
#include "Cliente.h"
#include "Ventas.h"

void info_ventaPorProducto(ArrayList* nominaVentas, int codigoProducto)
{
    int i;
    Ventas* auxVentas;

    if(codigoProducto == 1000)
    {
        printf("\nTV_LG_32 $8999.99");
    }
    if(codigoProducto == 1001)
    {
        printf("\nPS4 $12999.99");
    }
    if(codigoProducto == 1002)
    {
        printf("\nIPHONE7 $19480.99");
    }

    for(i = 0; i < al_len(nominaVentas); i++)
    {
        auxVentas = al_get(nominaVentas,i);

        if(ventas_getCodigoProducto(auxVentas) == codigoProducto)
        {
            ventas_imprimeVenta(auxVentas);
        }
    }
}


void info_ventasPorCliente(ArrayList* pListaVentas,ArrayList* pListaClientes)
{
    int i,j;
    Cliente* auxCliente;
    Ventas* auxVenta;
    int idCliente;
    float montoFacturado;

    for(i = 0; i < al_len(pListaClientes); i++)
    {
        auxCliente = al_get(pListaClientes,i);
        idCliente = cliente_getIdCliente(auxCliente);

        if(auxCliente != NULL)
        {
            printf("\n\nDNI: %s - NOMBRE: %s - APELLIDO: %s\n",cliente_getDni(auxCliente),cliente_getNombre(auxCliente),cliente_getApellido(auxCliente));
        }

        for(j = 0; j < al_len(pListaVentas); j++)
        {
            auxVenta = al_get(pListaVentas,j);
            if(idCliente == ventas_getIdClientes(auxVenta))
            {
                montoFacturado = ventas_getCantidad(auxVenta) * ventas_getPrecioUnitario(auxVenta);
                printf("\nIDVENTA: %d - CODIGO PRODUCTO: %d - CANTIDAD: %d - MONTO FACTURADO: %f",ventas_getIdVentas(auxVenta),ventas_getCodigoProducto(auxVenta),ventas_getCantidad(auxVenta),montoFacturado);
            }

        }
    }
}
