#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "abm_aviso.h"
#include "abm_cliente.h"

#define TOPE_CLIENTES 100
#define TOPE_AVISOS 1000



int main()
{

    tbl_cliente clientes[TOPE_CLIENTES];
    tbl_aviso avisos[TOPE_AVISOS];

    inicializar_clientes(clientes, TOPE_CLIENTES);
    inicializar_avisos(avisos, TOPE_AVISOS);

    int opcion=0;
    int auxIdCliente;
    int auxIdAviso;
    char continuar='s';

    do
    {
        getValidInt("MENU\n---------------\n1-ALTA CLIENTE\n2-MODIFICAR DATOS DEL CLIENTE\n3-BAJA DEL CLIENTE\n"
        "4-PUBLICAR AVISO\n5-PAUSAR AVISO\n6-REANUDAD AVISO\n"
        "7-IMPRIMIR CLIENTES\n8-IMPRIMIR AVISOS\n9-INFORMAR CLIENTES\n10-INFORMAR AVISOS\n11-SALIR\n\n","Opcion invalida"
        ,&opcion,1,11,99);


        switch(opcion)
        {
        case 1:
            alta_cliente(clientes, TOPE_CLIENTES);
            break;
        case 2:
            if(getValidInt("Ingrese ID de cliente","No valido",&auxIdCliente,0,TOPE_CLIENTES-1,99)==0)
            {
                modifica_cliente(clientes, TOPE_CLIENTES, auxIdCliente);
            }

            break;
        case 3:
            if(getValidInt("Ingrese ID de cliente","No valido",&auxIdCliente,0,TOPE_CLIENTES-1,99)==0)
            {
               baja_cliente(clientes, TOPE_CLIENTES, auxIdCliente);
            }

            break;
        case 4:
            if(getValidInt("Ingrese el ID de cliente","No valido",&auxIdCliente,0,99,99)==0)
            {
                alta_aviso(avisos,TOPE_AVISOS,clientes,TOPE_CLIENTES,auxIdCliente);
            }
            break;
        case 5:
             if(getValidInt("Ingrese el ID de aviso","No valido",&auxIdAviso,0,99,99)==0)
            {
                modifica_aviso(avisos,TOPE_AVISOS,auxIdAviso);
            }
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            continuar='n';
            break;
        }
    }while(continuar=='s');







    return 0;
}


