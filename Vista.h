#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n\n1. Alta de Cliente \n2. Modificacion de Cliente \n3.Baja de Cliente\n4. Listar Cliente\
                                        \n5. Realiza una venta \n6. Anular venta\n7. Informar venta\n8. Informar venta por producto.\
                                        \n9. Generar informe de ventas\n10. Informar cantidad de ventas por cliente\n11. Salir \nElija una opcion:"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"




int vista_init (int idioma);
int vista_mostrarMenu();
void mostrarError(char * mensaje);
void vista_mostrarCliente(ArrayList* pListaSocios);
void vista_mostrarVenta(ArrayList* pListaVentas, ArrayList* pListaClientes);



