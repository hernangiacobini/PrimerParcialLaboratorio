#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "abm_aviso.h"
#include "abm_cliente.h"

#define TOPE_CLIENTES 100
#define TOPE_AVISOS 1000



int alta_cliente(tbl_cliente* clientes, int tope)
{
    int i;
    int auxID;
    char auxNombre[15];
    char auxApellido[20];
    char auxCuit[13];

    for(i=0;i<tope;i++)
    {
        if(clientes[i].isEmpty==1)
        {

            if(getValidString("\nEscriba su nombre:\n","No valido","Debe ingresar un maximo de 15 caracteres",auxNombre,15,3)==0)
            {
                strcpy(clientes[i].nombre_cli,auxNombre);
                if(getValidString("\nEscriba su apellido:\n","No valido","Debe ingresar un maximo de 20 caracteres",auxApellido,20,3)==0)
                {
                    strcpy(clientes[i].apellido_cli,auxApellido);
                    if(getValidString("\nEscriba su CUIT:\n","No valido","Debe ingresar un maximo de 13 caracteres",auxCuit,13,3)==0)
                    {
                        strcpy(clientes[i].CUIT,auxCuit);
                        auxID=proximoIdCliente();
                        clientes[i].idCliente=auxID;
                        clientes[i].isEmpty=0;
                        break;
                    }
                }
            }
        }
    }
    printf("ID generado: %d\n\n",auxID);
    return 0;
}

int modifica_cliente(tbl_cliente* clientes, int tope, int auxIdCli)
{
    int i;
    char auxNombre[15];
    char auxApellido[20];
    char auxCuit[13];
    int retorno=-1;

    for(i=0;i<tope;i++)
    {
        if(auxIdCli==clientes[i].idCliente && clientes[i].isEmpty==0)
        {
            if(getValidString("\nEscriba su nombre:\n","No valido","Debe ingresar un maximo de 15 caracteres",auxNombre,15,3)==0)
            {
                strcpy(clientes[i].nombre_cli,auxNombre);
                if(getValidString("\nEscriba su apellido:\n","No valido","Debe ingresar un maximo de 20 caracteres",auxApellido,20,3)==0)
                {
                    strcpy(clientes[i].apellido_cli,auxApellido);
                    if(getValidString("\nEscriba su CUIT:\n","No valido","Debe ingresar un maximo de 13 caracteres",auxCuit,13,3)==0)
                    {
                        strcpy(clientes[i].CUIT,auxCuit);
                    }
                }
            }
            retorno=0;
            break;
        }
    }

    return retorno;
}

int baja_cliente(tbl_cliente* clientes, int tope, int auxIdCli)
{
    int i;
    int retorno=-1;

    for(i=0;i<tope;i++)
    {
        if((clientes[i].isEmpty==0) && auxIdCli==clientes[i].idCliente)
        {
            clientes[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

int proximoIdCliente(void)
{
    static int id=-1;

    id++;
    return id;
}


int inicializar_clientes(tbl_cliente* clientes, int tope)
{
    int retorno = -1;
    int i;
    if(tope > 0 && clientes != NULL)
    {
        retorno = 0;
        for(i=0;i<tope;i++)
        {
            clientes[i].isEmpty=1;
        }
    }
    return retorno;
}


int buscaCliente(tbl_cliente* clientes, int tope, int idCliente)
{
    int i;

    for(i=0;i<tope;i++)
    {
        if(clientes[i].idCliente==idCliente)
        {
            return idCliente;
        }
    }
    return 0;
}
