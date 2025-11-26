#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void splitList(List l, List *left, List *right) {
    int len = length(l);
    int mid = len / 2; 
    int i = 0;
    *left = NIL;
    *right = NIL;
    List p = l;
    while (p != NIL) {
        if (i < mid) {
            *left = konsDot(*left, head(p));
        } else {
            *right = konsDot(*right, head(p));
        }
        p = tail(p);
        i++;
    }
}


List mergeSorted(List l1, List l2) {
    if (isEmpty(l1)) return copy(l2);
    if (isEmpty(l2)) return copy(l1);

    if (head(l1) <= head(l2)) {
        return konso(head(l1), mergeSorted(tail(l1), l2));
    } else {
        return konso(head(l2), mergeSorted(l1, tail(l2)));
    }
}

List mergeSort(List l) {
    if (isEmpty(l) || isOneElmt(l)) {
        return copy(l);
    } else {
        List left, right;
        splitList(l, &left, &right);
        List sortedLeft = mergeSort(left);
        List sortedRight = mergeSort(right);
        List merged = mergeSorted(sortedLeft, sortedRight);
        displayList(merged);
        printf("\n");
        return merged;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    List l = NIL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        l = konsDot(l, x);
    }

    mergeSort(l);

    return 0;
}
