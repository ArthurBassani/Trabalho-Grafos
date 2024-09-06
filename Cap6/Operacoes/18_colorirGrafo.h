#ifndef COLORIR_GRAFO_H
#define COLORIR_GRAFO_H

void resetaCoresGrafo(pDGrafo g){
    if(g->listaVertices->primeiro == NULL) return;
    pNoh n = g->listaVertices->primeiro;
    pVertice v;
    while (n != NULL)
    {
        v = n->info;
        v->grau = (-1);
        n = n->prox;
    }
}
//Vou utilizar o Grau dos vertices para representar as cores, pra não precisar criar um campo novo no vértice
int colorirGrafo(pDGrafo grafo,FuncaoComparacao fc,FuncaoAlocacao fa){
    if(grafo->listaVertices->quantidade == 0) return 0;
    resetaCoresGrafo(grafo);
    pVertice vAtual,vAux;
    pDLista incidentes,adjacentes;
    pNoh nAtual;
    int k = 1,i;
        
    vAux = (pVertice) malloc(sizeof(Vertice));
    vAux->listaAdjacencias = NULL;
    vAux->info = NULL;

    nAtual = grafo->listaVertices->primeiro;
    vAtual = nAtual->info;
    vAtual->grau = 0;
    nAtual = nAtual->prox;
    while (nAtual != NULL)
    {
        vAtual = nAtual->info;
        incidentes = buscarVerticesIncidentes(grafo,vAtual,fc);
        adjacentes = unirListas(incidentes,vAtual->listaAdjacencias,fa);

        for (i = 0; i <= k; i++)
        {
            vAux->grau = i;
            if(contemInfo(adjacentes,vAux,comparaGrauVertices) == 0){
                vAtual->grau = i;
                if(i == k) k++;
                break;
            }
        }
        destruirLista(incidentes);
        free(incidentes);
        destruirLista(adjacentes);
        free(adjacentes);
        nAtual = nAtual->prox;
    }
    imprimeGrafoColorido(grafo);
    return k;
}

#endif