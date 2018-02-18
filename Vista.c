#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "Cliente.h"
#include "Ventas.h"

static void opcionAltaCliente();
static void opcionBajaCliente();
static void opcionModificacionCliente();
static void opcionListadoCliente();
static void opcionOrdenarCliente();
static void opcionRealizarVenta();
static void opcionAnularVenta();
static void opcionInformarVentas();
static void opcionInformarVentaPorProducto();
static void opcionCantidadVentasPorCliente();
static int idiomaVista;

int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 11)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionAltaCliente();
                break;
            case 2:
                opcionModificacionCliente();
                break;
            case 3:
                opcionBajaCliente();
                break;
            case 4:
                opcionListadoCliente();
                break;
            case 5:
                opcionRealizarVenta();
                break;
            case 6:
                opcionAnularVenta();
                break;
            case 7:
                opcionInformarVentas();
                break;
            case 8:
                opcionInformarVentaPorProducto();
                break;
            case 9:
                break;
            case 10:
                opcionCantidadVentasPorCliente();
                break;
        }
    }

    return 0;
}

void vista_mostrarCliente(ArrayList* pListaSocios)
{
    int i;
    Cliente *auxCliente;

    for(i = 0; i < al_len(pListaSocios); i++)
    {
        auxCliente = al_get(pListaSocios,i);
        if(cliente_getEstadoCliente(auxCliente) == ESTADO_CLIENTE_ACTIVO)
        {
            printf("ID: %d - NOMBRE: %s - APELLIDO: %s - DNI: %s\n",cliente_getIdCliente(auxCliente),cliente_getNombre(auxCliente),cliente_getApellido(auxCliente),cliente_getDni(auxCliente));
        }
    }

}


void mostrarError(char * mensaje)
{

    printf("\nIMPRIMO ERROR\n");

}

static void opcionAltaCliente()
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    if(val_getString(auxNombre, "Nombre? ", "Error",2,50) == 0 &&
       val_getString(auxApellido, "Apellido? ", "Error",2,50) == 0 &&
       val_getInt(auxDni, "Dni? ", "Error",2,50) == 0)
    {
        cont_altaClientes(auxNombre,auxApellido,auxDni);
    }

}

static void opcionBajaCliente()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"\nId a dar de baja:" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaClientes(id);
    }

}

static void opcionModificacionCliente()
{
    char auxId[10];
    int id;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];

    if((val_getUnsignedInt(auxId,"Id a modificar" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(auxNombre, "Nombre? ", "Error",2,50) == 0 &&
           val_getString(auxApellido, "Apellido? ", "Error",2,50) == 0 &&
           val_getInt(auxDni, "Dni? ", "Error",2,50) == 0)
        {
            cont_modificarClientes(id,auxNombre,auxApellido,auxDni);
        }
    }


}

static void opcionListadoCliente()
{
    cont_listarClientes();
}


//VENTAS
void vista_mostrarVenta(ArrayList* pListaVentas, ArrayList* pListaClientes)
{
    int i;
    Ventas *auxVentas;
    Cliente* auxCliente;
    int idCliente;
    float montoFacturado;

    for(i = 0; i < al_len(pListaVentas); i++)
    {
        auxVentas = al_get(pListaVentas,i);
        if(ventas_getEstadoVentas(auxVentas) == ESTADO_VENTA_ACTIVA)
        {
            idCliente = ventas_getIdClientes(auxVentas);
            auxCliente = cliente_findByIdCliente(pListaClientes,idCliente);
            montoFacturado = ventas_getCantidad(auxVentas) * ventas_getPrecioUnitario(auxVentas);

            printf("ID: %d -NOMBRE: %s - APELLIDO: %s - DNI: %s - CODIGO PRODUCTO: %d - MONTO FACTURADO: %.2f\n",ventas_getIdVentas(auxVentas),cliente_getNombre(auxCliente),cliente_getApellido(auxCliente),
                   cliente_getDni(auxCliente),ventas_getCodigoProducto(auxVentas),montoFacturado);
        }
    }

}

static void opcionRealizarVenta()
{
    char auxCodigoProducto[10];
    char auxCantidad[10];
    char auxIdCliente[10];
    int idCliente;

    val_getInt(auxIdCliente,"Id del Cliente??","Error, reingrese!",2,10);
    idCliente = atoi(auxIdCliente);

    if(con_verificaExistenciaCliente(idCliente) != -1)
    {
        if(val_getInt(auxCodigoProducto, "Codigo Producto? ", "Error",2,10) == 0 &&
        val_getInt(auxCantidad, "Cantidad? ", "Error",2,10) == 0 )
        {
            if(atoi(auxCodigoProducto) == 1000 || atoi(auxCodigoProducto) == 1001 || atoi(auxCodigoProducto) == 1002)
            {
                 cont_altaVentas(idCliente,atoi(auxCodigoProducto),atoi(auxCantidad));
            }
            else
            {
                printf("\nEl codigo no es valido!\n");
            }
        }
    }
}

static void opcionAnularVenta()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"\nId de la venta a dar de baja:" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaVentas(id);
    }
}


static void opcionInformarVentas()
{
    cont_listarVentas();
}

static void opcionInformarVentaPorProducto()
{
    char auxCodigoProducto[10];
    int codigoProducto;

    if((val_getInt(auxCodigoProducto,"\nCodigo de producto?:" , "Error",2,10)==0))
    {
        codigoProducto = atoi(auxCodigoProducto);
        if(codigoProducto == 1000 || codigoProducto == 1001 || codigoProducto == 1002)
        {
            cont_informarVentaPorProducto(codigoProducto);
        }
        else
        {
            printf("El codigo del producto no se encuentra en el sistema");
        }
    }
}

static void opcionCantidadVentasPorCliente()
{
    cont_informeVentasporCliente();
}


