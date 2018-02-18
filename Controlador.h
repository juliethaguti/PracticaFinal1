void cont_init();
int cont_altaClientes (char* a,char* b,char* c);
int cont_bajaClientes (int id);
int cont_modificarClientes (int id, char* a,char* b,char* c);
int cont_listarClientes ();
int cont_ordenarClientes ();
int con_verificaExistenciaCliente(int id);

int cont_altaVentas (int id,int codigo,int cantidad);
int cont_bajaVentas (int id);
int cont_listarVentas ();
int cont_ordenarVentas ();
void cont_informarVentaPorProducto(int codigoProducto);
void cont_informeVentasporCliente();



