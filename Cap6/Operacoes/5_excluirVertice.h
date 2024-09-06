#ifndef EXCLUIR_VERTICE_H
#define EXCLUIR_VERTICE_H

/* --------------------------- */
void excluirVertice(pDGrafo grafo, void* info, FuncaoComparacao fc){
    pVertice vExcluir = buscarVertice(grafo,info,fc);
    pVertice vertice;
    pNoh pAux = grafo->listaVertices->primeiro;

    if(vExcluir == NULL){
        printf("Vertice não encontrado no grafo");
        return;
    }

    while (pAux != NULL)
    {
        vertice = pAux->info;
        excluirInfo(vertice->listaAdjacencias,vExcluir,fc);
        pAux = pAux->prox;
    }
    
    excluirInfo(grafo->listaVertices,vExcluir,fc);
    destruirLista(vExcluir->listaAdjacencias);
    free(vExcluir->listaAdjacencias);
    free(vExcluir);

}
#endif
