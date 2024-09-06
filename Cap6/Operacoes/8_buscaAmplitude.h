#ifndef BUSCA_AMPLITUDE_H
#define BUSCA_AMPLITUDE_H

/* --------------------------- */
void buscaAmplitude(pDGrafo grafo, FuncaoComparacao fc, FuncaoImpressao fi){
    if(grafo->listaVertices->primeiro == NULL){
        printf("Grafo Vazio");
        return;
    }
    pDFila verticesPendentes;
    pDLista verticesVisitados;
    pVertice vertice;
    pNoh pAux;

    verticesPendentes = criarFila();
    verticesVisitados = criarLista();
    
    enfileirarInfo(verticesPendentes,grafo->listaVertices->primeiro->info);    

    while (filaVazia(verticesPendentes) != 0)
    {
        vertice = desenfileirarInfo(verticesPendentes);

        if(contemInfo(verticesVisitados,vertice,fc) == 0){
            fi(vertice);
            incluirInfo(verticesVisitados,vertice);
        }

        pAux = vertice->listaAdjacencias->primeiro;

        while (pAux != NULL)
        {
            if(contemInfo(verticesVisitados,pAux->info,fc) == 0){
                enfileirarInfo(verticesPendentes,pAux->info);
            }
            pAux = pAux->prox;
        }

    }
    


}
#endif
