#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "abm_aviso.h"
#include "abm_cliente.h"

#define TOPE_CLIENTES 100
#define TOPE_AVISOS 1000


int alta_aviso(tbl_aviso* avisos, int topeA, tbl_cliente* clientes, int topeC, int auxIdCliente)
{
    int i;
    int auxID;
    int auxRubro;
    char auxtexto[64];
    int retorno=-1;

    if(buscaCliente(clientes,topeC,auxIdCliente)>=0)
    {
        for(i=0;i<topeA;i++)
        {
            if(avisos[i].isEmpty==1)
            {
                if(getValidInt("\nEscriba el rubro:\n","No valido",&auxRubro,1,5,99)==0)
                {
                    avisos[i].rubro=auxRubro;
                    if(getValidString("\nEscriba el texto del aviso:\n","No valido","Debe ingresar un maximo de 64 caracteres",auxtexto,64,3)==0)
                    {
                        strcpy(avisos[i].texto,auxtexto);
                        auxID=proximoId();
                        avisos[i].idAviso=auxID;
                        avisos[i].idCliente=auxIdCliente;
                        avisos[i].isEmpty=0;
                        retorno= 0;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("El cliente no esta registrado");
    }
    return retorno;
}

int modifica_aviso(tbl_aviso* avisos, int tope, int auxIdAviso)
{
    int i;
    int retorno=-1;

    for(i=0;i<tope;i++)
    {

    }

    return retorno;
}


int proximoId(void)
{
    static int id=-1;

    id++;
    return id;
}

int inicializar_avisos(tbl_aviso* avisos, int tope)
{
    int retorno = -1;
    int i;
    if(tope > 0 && avisos != NULL)
    {
        retorno = 0;
        for(i=0;i<tope;i++)
        {
            avisos[i].isEmpty=1;
        }
    }
    return retorno;
}



