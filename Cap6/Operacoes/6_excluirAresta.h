#ifndef EXCLUIR_ARESTA_H
#define EXCLUIR_ARESTA_H

/* --------------------------- */
int excluirAresta(pDGrafo grafo, void *vOrig, void *vDest, FuncaoComparacao fc){
    pVertice vOrigem  = buscarVertice(grafo, vOrig, fc);
    pVertice vDestino = buscarVertice(grafo, vDest, fc);
    if (vOrigem == NULL || vDestino == NULL){
        printf("Um dos v�rtices n�o existe! \n");
        return 0;
     }
    return excluirInfo(vOrigem->listaAdjacencias,vDestino,fc);
}

#endif
