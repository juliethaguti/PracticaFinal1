#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Cliente.h"
#include "Ventas.h"
#include "Validaciones.h"

int dm_saveAllClientes(ArrayList* pArrayClientes)
{
    int i;
    int retorno=-1;
    FILE* pFile=fopen("clientes.csv","w");
    void* pClientes=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"id,first_name,last_name,dni\n");
        for(i=0;i<al_len(pArrayClientes);i++)
        {
            pClientes=al_get(pArrayClientes,i);

            if(cliente_getEstadoCliente(pClientes) == ESTADO_CLIENTE_ACTIVO)
            {
                 fprintf(pFile, "%d,%s,%s,%s\n", cliente_getIdCliente(pClientes),cliente_getNombre(pClientes), cliente_getApellido(pClientes), cliente_getDni(pClientes));
            }

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;
}


int dm_readAllClientes(ArrayList* pArrayClientes)
{
    int retorno=-1;
    FILE *pFile;
	Cliente* auxCliente;

    char var1[50],var2[50],var3[50],var4[50];

    pFile = fopen("clientes.csv","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4) >0)
			{
				if(val_validarInt(var1)!=-1 && val_validarString(var2)!=-1 && val_validarString(var3)!=-1 && val_validarUnsignedInt(var4)!=-1 )
				{
					auxCliente=cliente_new(atoi(var1), var2, var3,var4,ESTADO_CLIENTE_ACTIVO);
					al_add(pArrayClientes, auxCliente);
					retorno=atoi(var1);
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}

    return retorno;
}

//VENTAS

int dm_saveAllVentas(ArrayList* nominaVentas)
{
  int i;
    int retorno=-1;
    FILE* pFile=fopen("ventas.txt","w");
    void* pVentas=NULL;
    if(pFile!=NULL)
    {
		fprintf(pFile,"idVenta,idCliente,codProducto,cantidad\n");
        for(i=0;i<al_len(nominaVentas);i++)
        {
            pVentas = al_get(nominaVentas,i);
            fprintf(pFile, "%d,%d,%d,%d\n", ventas_getIdVentas(pVentas),ventas_getIdClientes(pVentas), ventas_getCodigoProducto(pVentas),
                    ventas_getCantidad(pVentas));

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;

}



int dm_readAllVentas(ArrayList* pArrayVentas)
{
    int retorno=-1;
    FILE *pFile;
	Ventas* auxVentas;

    char var1[50],var2[50],var3[50],var4[50];

    pFile = fopen("ventas.txt","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4) >0)
			{
				if(val_validarInt(var1)!=-1 && val_validarInt(var2)!=-1 && val_validarInt(var3)!=-1 && val_validarInt(var4)!=-1)
				{
					auxVentas = ventas_new(atoi(var1), atoi(var2), atoi(var3),atoi(var4),ESTADO_VENTA_ACTIVA);
					al_add(pArrayVentas, auxVentas);
					retorno=atoi(var1);
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}

    return retorno;
}
