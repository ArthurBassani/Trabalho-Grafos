#ifndef GET_ALL_CAMINHOS_H
#define GET_ALL_CAMINHOS_H

pDLista getAllCaminhos(pDGrafo grafo,void* idOrig,void*idDest,FuncaoComparacao fc,FuncaoAlocacao fa){ 
    pDLista pListaCaminhos = criarLista(),caminho = criarLista(),caminhoParcial;
    pDPilha pendentes = criarPilha();
    pVertice vOrigem = buscarVertice(grafo,idOrig,fc);
    pVertice vDestino = buscarVertice(grafo,idDest,fc);
    if (vOrigem == NULL || vDestino == NULL || vOrigem == vDestino) return pListaCaminhos;
    pVertice v1,v2,vAux;
    pNoh n1,n2,nAux;

    incluirInfo(caminho,vOrigem);
    empilharInfo(pendentes,caminho);
    while (pilhaVazia(pendentes) > 0)
    {
        caminho = desempilharInfo(pendentes);
        nAux = caminho->ultimo;
        vAux = nAux->info;
        n1 = vAux->listaAdjacencias->primeiro;
        while (n1 != NULL)
        {
            caminhoParcial = duplicarLista(caminho,fa);
            if(contemInfo(caminhoParcial,n1->info,fc) == 0){
                incluirInfo(caminhoParcial,n1->info);
                if(fc(n1->info,vDestino) == 0){
                    incluirInfo(pListaCaminhos,caminhoParcial);
                }else{
                    empilharInfo(pendentes,caminhoParcial);
                }
            }else{
                destruirLista(caminhoParcial);
            }
            n1 = n1->prox;
            
        }
        if(fc(vAux,vDestino) != 0)
            destruirLista(caminho);
    }

    return pListaCaminhos;
}

#endif