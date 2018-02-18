#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"
#include "Cliente.h"
#include "Ventas.h"
#include "Informes.h"

static ArrayList* nominaClientes;
static ArrayList* nominaVentas;
static int proximoIdClientes=0;
static int proximoIdVentas = 0;
static int getNewIdClientes();
static int setNewIdClientes(int id);
static int getNewIdVentas();
static int setNewIdVentas(int id);

void cont_init()
{
    nominaClientes = al_newArrayList();
    nominaVentas = al_newArrayList();
    setNewIdClientes(dm_readAllClientes(nominaClientes) + 1);
    setNewIdVentas(dm_readAllVentas(nominaVentas) + 1);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaClientes (char* nombre,char* apellido,char* dni)
{
    Cliente* auxCliente;

    auxCliente = cliente_new(getNewIdClientes(),nombre,apellido,dni,ESTADO_CLIENTE_ACTIVO);
    if(auxCliente != NULL)
    {
        al_add(nominaClientes,auxCliente);
    }
    dm_saveAllClientes(nominaClientes);
    return 0;
}

int cont_bajaClientes (int id)
{
    Ventas* auxVenta;
    Cliente* auxCliente;

    auxCliente = cliente_findByIdCliente(nominaClientes,id);
    auxVenta = ventas_findByIdClientes(nominaVentas,id);

    if(auxVenta == NULL && cliente_getEstadoCliente(auxCliente) == ESTADO_CLIENTE_ACTIVO)
    {
        cliente_setEstadoCliente(auxCliente,ESTADO_CLIENTE_INACTIVO);
        dm_saveAllClientes(nominaClientes);
    }
    else
    {
        printf("No es posible dar de baja a es Id!");
    }

    return 0;
}


int cont_modificarClientes (int id, char* nombre,char* apellido,char* dni)
{
    Cliente* auxCliente = cliente_findByIdCliente(nominaClientes,id);

    if(auxCliente != NULL)
    {
        cliente_setApellido(auxCliente,apellido);
        cliente_setDni(auxCliente,dni);
        cliente_setNombre(auxCliente,nombre);
        dm_saveAllClientes(nominaClientes);
    }
    else
    {
        printf("El id no existe");
    }

    return 0;
}

int cont_listarClientes ()
{
    vista_mostrarCliente(nominaClientes);

    return 0;
}

int cont_ordenarClientes ()
{

    return 0;
}

static int getNewIdClientes()
{
    return proximoIdClientes++;
}

static int setNewIdClientes(int id)
{
    proximoIdClientes = id;
    return 0;
}

int con_verificaExistenciaCliente(int id)
{
    int retorno = -1;

    if(cliente_findByIdCliente(nominaClientes,id) != NULL)
    {
        retorno = 1;
    }
    return retorno;
}

//VENTAS


int cont_altaVentas (int id,int codigo,int cantidad)
{
    Ventas* auxVenta;

    auxVenta = ventas_new(getNewIdVentas(),id,codigo,cantidad,ESTADO_VENTA_ACTIVA);

    if(auxVenta != NULL && (codigo == 1000 || codigo == 1001 || codigo == 1002))
    {
        al_add(nominaVentas,auxVenta);
    }
    dm_saveAllVentas(nominaVentas);
    return 0;
}

int cont_bajaVentas (int id)
{
    Ventas* auxVenta;
    int retorno = -1;;

    auxVenta = ventas_findByIdVentas(nominaVentas,id);

    if(auxVenta != NULL)
    {
        ventas_setEstadoVentas(auxVenta,ESTADO_VENTA_INACTIVA);
        retorno = 1;
    }

    dm_saveAllVentas(nominaVentas);
//printf("%d",ventas_getEstadoVentas(auxVenta));
    return retorno;
}


int cont_listarVentas ()
{
    vista_mostrarVenta(nominaVentas,nominaClientes);

    return 0;
}

int cont_ordenarVentas ()
{

    return 0;
}

void cont_informarVentaPorProducto(int codigoProducto)
{
    info_ventaPorProducto(nominaVentas, codigoProducto);
}

void cont_informeVentasporCliente()
{
    info_ventasPorCliente(nominaVentas,nominaClientes);
}
static int getNewIdVentas()
{
    return proximoIdVentas++;
}

static int setNewIdVentas(int id)
{
    proximoIdVentas = id;
    return 0;
}
