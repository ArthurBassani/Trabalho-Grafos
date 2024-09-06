#ifndef EH_HAMILTONIANO_H
#define EH_HAMILTONIANO_H

int ehHamiltoniano(pDGrafo grafo,FuncaoComparacao fc,FuncaoAlocacao fa){
    pNoh p1,p2,pc;
    pVertice vOrigem,vDestino;
    pDLista caminhos,caminho;
    p1 = grafo->listaVertices->primeiro; 
    while(p1 != NULL){
        vOrigem = p1->info;

        p2 = grafo->listaVertices->primeiro;
        while(p2 != NULL){
            vDestino = p2->info;
            caminhos = getAllCaminhos(grafo, vOrigem->info, vDestino->info, fc, fa);
            pc = caminhos->primeiro;
            while (pc != NULL)
            {   
                caminho = pc->info;
                if(listasIguais(grafo->listaVertices,caminho,fc)) {
                    destruirLista(caminho);
                    free(caminho);
                    return 1;
                }
                destruirLista(caminho);
                free(caminho);
                pc = pc->prox;
            }
            destruirLista(caminhos);
            free(caminhos);
            p2 = p2->prox;
        }
        p1 = p1->prox;
     }
    return 0;
}



#endif