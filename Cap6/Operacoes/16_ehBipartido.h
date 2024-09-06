#ifndef EH_BIPARTIDO_H
#define EH_BIPARTIDO_H

int ehBipartido(pDGrafo grafo,FuncaoComparacao fc,FuncaoAlocacao fa){ 
    if (grafo->listaVertices->quantidade == 1) return 0;
    
    pNoh pAux,pAdj;
    pDPilha pendentes = criarPilha();
    pVertice vAdj,vAux;
    //Lista de vertices pertencentes a um conjunto x
    pDLista conjunto[2],pLista,pAdjacencias;
    conjunto[0] = criarLista();
    conjunto[1] = criarLista();

    int flag = 0;
    pAux = grafo->listaVertices->primeiro;
    vAux = pAux->info;
    incluirInfo(conjunto[0],vAux);
    while (pAux != NULL)
    {
        vAux = pAux->info;
        if(contemInfo(conjunto[0],vAux,fc) == 0 && contemInfo(conjunto[1],vAux,fc) == 0)
            empilharInfo(pendentes,vAux);

        pAdjacencias = vAux->listaAdjacencias;
        pAdj = pAdjacencias->primeiro;

        while (pAdj != NULL)
        {
            vAdj = pAdj->info;
            if(contemInfo(conjunto[0],vAdj,fc) == 0 && contemInfo(conjunto[1],vAdj,fc) == 0)
                empilharInfo(pendentes,vAdj);

            pAdj = pAdj->prox;
        }
            
        while (pilhaVazia(pendentes) > 0)
        {   
            vAux = desempilharInfo(pendentes);
            pLista = unirListas(buscarVerticesIncidentes(grafo,vAux,fc),
                                vAux->listaAdjacencias,fa);
            flag = 0;
            for (int i = 0; i < 2; i++)
            {
                pAdj = pLista->primeiro;
                while (pAdj != NULL)
                {
                    vAdj = pAdj->info;
                    if(contemInfo(conjunto[i],vAdj,fc) != 0){
                        pAdj = NULL;
                        flag++;
                    }else{
                        pAdj = pAdj->prox;
                    }
                    
                }
                if(flag == 0){
                    incluirInfo(conjunto[0],vAux);
                    break;
                }
                
            }
            if(flag == 2) return 0;
            if(flag == 1) incluirInfo(conjunto[1],vAux);
        }
        pAux = pAux->prox;
    }

    return 1;
}


#endif