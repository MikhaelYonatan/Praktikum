#include <stdio.h>
#include "graph.h"

int main() {
    int N, M, x, u, v;
    Graph g;
    AdrNode pn;
    boolean first = true;
    scanf ("%d %d", &N, &M);

    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &x);
        if (first) {
            CreateGraph(x, &g);
            first = false;
        }
        else {
            insertNode(&g, x, &pn);
        }
    }

    for (int i = 0 ; i < M ; i++) {
        scanf("%d %d", &u, &v);
        insertEdge(&g, u, v);
    }

    pn = g.first;
    for (int i = 0 ; i < N ; i++) {
        printf("%d %d\n", pn->id, pn->nPred);
        pn = pn->next;
    }
    return 0;
}