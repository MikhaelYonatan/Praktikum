#include "cycle.h"
#include "listlinier.h"
#include "Boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * I.S. List l terdefinisi
 * F.S. Mengembalikan address node yang merupakan entrypoint dari cycle
 * Jika tidak ada cycle, kembalikan NULL
 */
Address findCycleEntryPoint(List l) {
    Address p = l;

    // boolean udah[10000000];

    List Udah;
    CreateList(&Udah);

    while (p != NULL)
    {
        
        int integerP = (int)p;
        // if (udah[integerP]) {
        //     break;
        // }
        // udah[integerP] = TRUE;
        if (indexOf(Udah, integerP) != IDX_UNDEF) {
            break;
        }
        insertFirst(&Udah, integerP);
        p = p->next;
    }

    return p;

    // if (p == NULL) {
    //     return NULL;
    // }
    // else {
    //     p = l;
    //     int count = 0;
    //     while(p != NULL) {
    //         count++;
    //         int integerP = (int)p;
    //         if (udah[integerP] == 2) {
    //             return p;
    //         }
    //     }
    // }
    
}

// int main() {
//     List l;
//     CreateList(&l);
//     insertLast(&l, 10);
//     printf("%d", &l);
// }