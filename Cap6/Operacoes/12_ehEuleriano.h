#ifndef EH_EULERIANO_H
#define EH_EULERIANO_H


int ehEuleriano(pDGrafo grafo,FuncaoComparacao fc){
    pNoh pAux = grafo->listaVertices->primeiro;
    
    while (pAux != NULL) {
        pVertice vertice = (pVertice)pAux->info;

        int grauEntrada = 0, grauSaida = 0;
        pNoh adjacencia = grafo->listaVertices->primeiro;

        // Calcula o grau de entrada e saída
        while (adjacencia != NULL) {
            pVertice vAdj = (pVertice)adjacencia->info;
            if (vAdj != vertice) {
                if (buscarNohInfo(vAdj->listaAdjacencias, vertice,fc) != NULL) {
                    grauEntrada++;
                }
            }
            adjacencia = adjacencia->prox;
        }
        grauSaida = vertice->listaAdjacencias->quantidade;
        if (grauEntrada != grauSaida) {
            return 0;
        }
        pAux = pAux->prox;
    }
    return 1;
}
#endif // 12_EH_EULERIANO_H
