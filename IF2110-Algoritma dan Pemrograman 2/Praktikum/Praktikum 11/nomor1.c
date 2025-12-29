#include <stdio.h>
#include "graph.h"

int main() {
    int N, M, u, v;
    Graph g;
    AdrNode pn;
    boolean first = true;

    scanf("%d %d", &N, &M);
    int x = 1;
    for (int i = 0 ; i < N ; i++) {
        if (first) {
            CreateGraph(x, &g);
            first = false;
        }
        else {
            insertNode(&g, x, &pn);
        }
        x++;
    }

    for (int i = 0 ; i < M ; i++) {
        scanf("%d %d", &u, &v);
        insertEdge(&g, u, v);
    }

    int A, B;
    scanf ("%d %d", &A, &B);
    AdrNode nodeA = searchNode(g, A);
    AdrNode nodeB = searchNode(g, B);
    AdrAdjNode trailA = nodeA->trail;
    AdrAdjNode trailB = nodeB->trail;
    AdrAdjNode pA, pB;
    boolean firstRes = true;
    boolean same = false;

    pA = trailA;
    while (pA != NULL) {
        pB = trailB;
        while (pB != NULL) {
            if (pA->succId == pB->succId) {
                if (firstRes) {
                    printf("%d", pA->succId);
                    firstRes = false;
                    same = true;
                }
                else {
                    printf(" %d", pA->succId);
                }
            }
            pB = pB->next;
        }
        pA = pA->next;
    }

    if (!same) {
        printf("0");
    }
    printf("\n");

    return 0;
}