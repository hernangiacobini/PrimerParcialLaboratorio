#ifndef ABM_CLIENTE_H_INCLUDED
#define ABM_CLIENTE_H_INCLUDED

typedef struct
{
    int idCliente;
    char nombre_cli[15];
    char apellido_cli[20];
    char CUIT[13];
    int isEmpty;

}tbl_cliente;




#endif // ABM_CLIENTE_H_INCLUDED
int inicializar_clientes(tbl_cliente* clientes, int tope);
int alta_cliente(tbl_cliente* clientes, int tope);
int modifica_cliente(tbl_cliente* clientes, int tope, int auxIdCli);
int baja_cliente(tbl_cliente* clientes, int tope, int auxIdCli);
int buscaCliente(tbl_cliente* clientes, int tope, int idCliente);

int proximoIdCliente(void);
