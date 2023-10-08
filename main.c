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
void suprime(arbol **A, int x)
{
    if (*A != NULL)
    {
        if (x < (*A)->dato)
            suprime(&((*A)->h_izq), x);
        else if (x > (*A)->dato)
            suprime(&((*A)->h_der), x);
        else if ((*A)->h_izq == NULL && (*A)->h_der == NULL)
        {
            arbol *tmp = *A;
            *A = NULL;
            free(tmp);
        }
        else if ((*A)->h_izq == NULL)
        {
            arbol *tmp = *A;
            *A = (*A)->h_der;
            free(tmp);
        }
        else if ((*A)->h_der == NULL)
        {
            arbol *tmp = *A;
            *A = (*A)->h_izq;
            free(tmp);
        }
        else
        {
            (*A)->dato = suprime_min(&((*A)->h_der));
        }
    }
}
int es_miembro(arbol *A, int x)
{
    if (A == NULL)
        return -1;
    else if (A->dato == x)
        return 1;
    else if (A->dato > x)
        return es_miembro(A->h_izq, x);
    else
        return es_miembro(A->h_der, x);
}
void preOrden(arbol *arb)
{
    if (arb != NULL)
    {
        printf("%d\n", arb->dato);
        preOrden(arb->h_izq);
        preOrden(arb->h_der);
    }
}
void inOrden(arbol *arb)
{
    if (arb != NULL)
    {
        inOrden(arb->h_izq);
        printf("%d\n", arb->dato);
        inOrden(arb->h_der);
    }
}
void postOrden(arbol *arb)
{
    if (arb != NULL)
    {
        postOrden(arb->h_izq);
        postOrden(arb->h_der);
        printf("%d\n", arb->dato);
    }
}
int main()
{
    arbol *raiz;
    raiz = NULL;
    int opcion, a, b;
    do
    {
        printf("Menu\n");
        printf("1) Agregar un elemento\n");
        printf("2) Eliminar un elemento\n");
        printf("3) Mostrar por Pre-Orden\n");
        printf("4) Mostrar por Post-Orden\n");
        printf("5) Mostrar por In-Orden\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("Ingrese un elemento\n");
            scanf("%d", &a);
            inserta(&raiz, a);
            if (es_miembro(raiz, a) == 1)
            {
                printf("El elemento buscado existe en el arbol\n");
            }
            else
            {
                printf("No existe\n");
            }
            break;
        case 2:
            printf("Ingrese un elemento para eliminar\n");
            scanf("%d", &a);
            suprime(&raiz, a);
            break;
        case 3:
            printf("Pre-Orden:\n");
            preOrden(raiz);
            break;
        case 4:
            printf("PostOrden: \n");
            postOrden(raiz);
            break;
        case 5:
            printf("InOrden: \n");
            inOrden(raiz);
            break;
        }
    } while (opcion != 0);
    return 0;
}