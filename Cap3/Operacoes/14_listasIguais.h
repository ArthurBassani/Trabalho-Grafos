#ifndef LISTAS_IGUAIS_H
#define LISTAS_IGUAIS_H 

int listasIguais(pDLista lista1,pDLista lista2,FuncaoComparacao fc){
    if(lista1 == NULL || lista2 == NULL) return 0;
    if(lista1->quantidade != lista2->quantidade) return 0;
    pNoh p1;
    p1 = lista1->primeiro;
    while (p1 != NULL)
    {
        if(contemInfo(lista2,p1->info,fc) == 0) return 0;
        p1 = p1->prox;
    }
    return 1;
}

#endif
