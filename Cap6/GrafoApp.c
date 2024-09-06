#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Grafo.h"
#include "../Cap3/Utils.h"


void main(){

    int vertices[] = {1,2,3,4,5,6};

    int opcao, vOrigem, vDestino;
    int *pv;

    pDGrafo grafo = criarGrafo();

    do{
        printf("\n 0  - Criar grafo \n");
        printf("  1  - Incluir Vertice \n");
        printf("  2  - Incluir Aresta \n");
        printf("  3  - Excluir Vertice [implementar] \n");
        printf("  4  - Excluir Aresta  [implementar] \n");
        printf("  5  - Mostrar grafo \n");
        printf("  6  - Busca em profundidade \n");
        printf("  7  - Busca em amplitude [implementar]\n");
        printf("  8  - Existe caminho?  (entre dois vertices) \n");
        printf("  9  - Encontra caminho (entre dois vertices) \n");
        printf("  10  - Eh Euleriano \n");
        printf("  11  - Eh Hamiltoniano \n");
        printf("  12  - Eh Conexo \n");
        printf("  13  - Eh Bipartido \n");
        printf("  14  - Encontra todos os caminhos (entre dois vertices) \n");
        printf("  15  - Colorir Grafo \n");
        printf("17 - Sair \n");

        scanf ("%d", &opcao);

        switch (opcao){

         case 0 :
            incluirVertice(grafo, &vertices[0], comparaVertice);
            incluirVertice(grafo, &vertices[1], comparaVertice);
            incluirVertice(grafo, &vertices[2], comparaVertice);
            incluirVertice(grafo, &vertices[3], comparaVertice);
            incluirVertice(grafo, &vertices[4], comparaVertice);
            incluirVertice(grafo, &vertices[5], comparaVertice);

            incluirAresta(grafo, &vertices[0], &vertices[1], comparaVertice);
            incluirAresta(grafo, &vertices[0], &vertices[3], comparaVertice);
            incluirAresta(grafo, &vertices[1], &vertices[2], comparaVertice);
            incluirAresta(grafo, &vertices[2], &vertices[3], comparaVertice);
            incluirAresta(grafo, &vertices[3], &vertices[4], comparaVertice);
            incluirAresta(grafo, &vertices[4], &vertices[0], comparaVertice);

            mostrarGrafo(grafo, imprimeVertice);
            break;

        case 1 :

            pv = (int *)malloc(sizeof(int));
            printf ("ID do v�rtice : ");
            scanf("%d", pv);
            incluirVertice(grafo, pv, comparaVertice);

            mostrarGrafo(grafo, imprimeVertice);
            getch();
            break;

        case 2 :

            printf ("\nID do v�rtice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do v�rtice destino : ");
            scanf("%d", &vDestino);
            incluirAresta(grafo, &vOrigem, &vDestino, comparaVertice);

            mostrarGrafo(grafo,imprimeVertice);
            getch();
            break;

        case 3:
            printf ("\nID do v�rtice : ");
            scanf("%d", &vOrigem);
            excluirVertice(grafo,&vOrigem,comparaVertice);
            mostrarGrafo(grafo,imprimeVertice);
            getch();
            break;

        case 4:
            printf ("\nID do v�rtice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do v�rtice destino : ");
            scanf("%d", &vDestino);
            excluirAresta(grafo, &vOrigem, &vDestino, comparaVertice);
            mostrarGrafo(grafo,imprimeVertice);
            getch();
            break;

        case 5 :
            mostrarGrafo(grafo, imprimeVertice);
            getch();
            break;

        case 6 :
            buscaEmProfundidade(grafo, comparaVertice, imprimeVerticeSemAdjacencias);
            getch();
            break;

        case 7:
            buscaAmplitude(grafo,comparaVertice,imprimeVerticeSemAdjacencias);
            getch();
            break;

        case 8 :
            printf ("\nID do v�rtice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do v�rtice destino : ");
            scanf("%d", &vDestino);

            int result = existeCaminho(grafo, &vOrigem, &vDestino, comparaVertice);
            // existe um caminho
            if (result != 0)
                printf("Existe caminho!");
            else
                printf("N�o existe caminho!");

            getch();
            break;
        case 9 :
            printf ("\nID do v�rtice origem : ");
            scanf("%d", &vOrigem);
            printf ("\nID do v�rtice destino : ");
            scanf("%d", &vDestino);

            pDLista caminho = getCaminho(grafo, &vOrigem, &vDestino, comparaVertice, alocaInfoVertice);
            if (caminho->quantidade > 0){
                printf("\n Existe um caminho: ");
                imprimirLista(caminho, imprimeVerticeSemAdjacencias);
            }
            else
                printf("\n *** N�O existe um caminho. *** ");

            getch();
            break;
        
            case 10:
                if(ehEuleriano(grafo,comparaVertice))
                    printf("\nGrafo Eh Euleriano\n");
                else
                    printf("\nGrafo Nao Eh Euleriano\n");
                getch();
                break;

            case 11:
                if(ehHamiltoniano(grafo,comparaVertice,alocaInfoVertice))
                    printf("\nGrafo Eh Hamiltoniano\n");
                else
                    printf("\nGrafo Nao Eh Hamiltoniano\n");
                getch();
                break;

            case 12:
                if(ehConexo(grafo,comparaVertice))
                    printf("\nGrafo Conexo\n");
                else
                    printf("\nGrafo Nao Conexo\n");
                getch();
                break;

            case 13:
                if(ehBipartido(grafo,comparaVertice,alocaInfoVertice))
                    printf("\nGrafo Bipartido\n");
                else
                    printf("\nGrafo Nao Bipartido\n");

                getch();
                break;
            
            case 14 :
                printf ("\nID do v�rtice origem : ");
                scanf("%d", &vOrigem);
                printf ("\nID do v�rtice destino : ");
                scanf("%d", &vDestino);

                pDLista caminhos = getAllCaminhos(grafo, &vOrigem, &vDestino, comparaVertice, alocaInfoVertice);
                if (caminhos->quantidade > 0){
                    printf("\n Caminhos existentes: ");
                    pNoh n = caminhos->primeiro;
                    pDLista pd;
                    printf("\n[");
                    while (n != NULL)
                    {
                        pd = n->info;
                        imprimirLista(pd, imprimeVerticeSemAdjacencias);
                        printf("\n  ]");
                        n = n->prox;
                    }
                }
                else
                    printf("\n *** N�O existe um caminho. *** ");

                getch();
            break;
            
            case 15:
                int k = colorirGrafo(grafo,comparaVertice,alocaInfoVertice);
                printf("Total de cores utilizadas: %d\n",k);
                getch();
                break;
            
        }

    }while (opcao != 17);

}
