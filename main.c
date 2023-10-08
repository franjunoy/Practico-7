#include <stdio.h>
#include <stdlib.h>
#include "arbolbinario.h"

void inserta(arbol **A, int x)
{
    if (*A == NULL)
    {
        *A = (arbol *)malloc(sizeof(arbol));
        (*A)->dato = x;
        (*A)->h_izq = NULL;
        (*A)->h_der = NULL;
    }
    else
    {
        if (x < (*A)->dato)
            inserta(&((*A)->h_izq), x);
        else if (x > (*A)->dato)
            inserta(&((*A)->h_der), x);
    }
}
int suprime_min(arbol **A)
{
    int v_ref;
    if ((*A)->h_izq == NULL)
    {
        v_ref = (*A)->dato;
        arbol *tmp = *A;
        *A = (*A)->h_der;
        free(tmp);
        return v_ref;
    }
    else
    {
        return suprime_min(&((*A)->h_izq));
    }
}
