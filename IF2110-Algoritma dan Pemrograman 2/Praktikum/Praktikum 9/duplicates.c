#include "list.h"
#include <stdio.h>
#include <stdlib.h>


List removeDuplicates(List l) {
    if (isEmpty(l)) {
        return l;
    }
    else if (isOneElmt(l)) {
        return l;
    }
    else {
        if (search(tail(l), head(l))) {
            deleteX(&l, head(l));
            return removeDuplicates(l);
        }
        else {
            return konso(head(l), removeDuplicates(tail(l)));
        }
    }
}

// #include <stdio.h>
// int main () {
//     Address l = NIL;
//     int n, val;
//     scanf("%d", &n);
//     for (int i = 0 ; i < n ; i++) {
//         scanf("%d", &val);
//         l = konsDot(l, val);
//     }

//     l = removeDuplicates(l);
//     displayList(l);
//     return 0;
// }