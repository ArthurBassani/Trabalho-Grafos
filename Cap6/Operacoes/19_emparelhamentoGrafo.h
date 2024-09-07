#ifndef EMPARELHAMENTO_GRAFO_H
#define EMPARELHAMENTO_GRAFO_H

pDLista emparelhamentoGrafo(pDGrafo grafo,FuncaoComparacao fc){
    pDLista emparelhamentos = criarLista(),aresta = criarLista(),pd;
    pDPilha arestas = criarPilha();
    pVertice vOrigem,vDestino,vAresta[2];
    pNoh nOrigem,nDestino,nAux;

    nOrigem = grafo->listaVertices->primeiro;
    while (nOrigem != NULL)
    {
        vOrigem = nOrigem->info; //1

        nDestino = vOrigem->listaAdjacencias->primeiro;
        while (nDestino != NULL)    
        {
            vDestino = nDestino->info; //2
            
            incluirInfo(aresta,vOrigem);
            incluirInfo(aresta,vDestino);

            empilharInfo(arestas,aresta);

            aresta = criarLista();

            nDestino = nDestino->prox;  
        }
        nOrigem = nOrigem->prox;
    }
    
    aresta = desempilharInfo(arestas);
    incluirInfo(emparelhamentos,aresta);
    int flag = 0;
    while (pilhaVazia(arestas) > 0)
    {
        aresta = desempilharInfo(arestas);
        nAux = emparelhamentos->primeiro;
        flag = 0;
        while (nAux != NULL)
        {
            pd = nAux->info;
            vAresta[0] = aresta->primeiro->info;
            vAresta[1] = aresta->ultimo->info;
            
            if(contemInfo(pd,vAresta[0],fc) == 0 && contemInfo(pd,vAresta[1],fc) == 0){
                incluirInfo(pd,vAresta[0]);
                incluirInfo(pd,vAresta[1]);
                flag = 1;
            }
            nAux = nAux->prox;
        }
        if(!flag) incluirInfo(emparelhamentos,aresta);
    }
    
    nAux = emparelhamentos->primeiro;
    while (nAux != NULL)
    {
        if(listasIguais(grafo->listaVertices,nAux->info,fc)) return nAux->info;
        nAux = nAux->prox;
    }
    
    return NULL;
}


#endif
