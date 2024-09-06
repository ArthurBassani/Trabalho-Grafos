#ifndef UNIR_LISTA_H
#define UNIR_LISTA_H

pDLista unirListas(pDLista lista1, pDLista lista2, FuncaoAlocacao fa)
{
    pDLista pNovaLista = criarLista();
    pNoh aux,info;

    aux = lista1->primeiro;
    while (aux != NULL)
    {
        incluirInfo(pNovaLista,fa(aux->info));
        aux = aux->prox;
    }

    aux = lista2->primeiro;
    while (aux != NULL)
    {
        incluirInfo(pNovaLista,fa(aux->info));
        aux = aux->prox;
    }

    return pNovaLista;
}

#endif
