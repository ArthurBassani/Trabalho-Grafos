#ifndef EH_CONEXO_H 
#define EH_CONEXO_H

int ehConexo(pDGrafo grafo,FuncaoComparacao fc){
    pVertice vertice,vOrig,vDest;   
    pNoh pAux,pAux2;
    int cont1 = 0;
    int cont2 = 0;
    pAux = grafo->listaVertices->primeiro;
    while (pAux != NULL)
    {
        vOrig = pAux->info;
        pAux2 = grafo->listaVertices->primeiro;
        while (pAux2 != NULL)
        {
            cont2++;
            vDest = pAux2->info;
            if(!existeCaminho(grafo,vOrig->info,vDest->info,fc)) return 0;
            pAux2 = pAux2->prox;
        }
        pAux = pAux->prox;
        cont2 = 0;
        cont1++;
    }

    return 1;
}

#endif