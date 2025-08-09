#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>


// void separateOddEven(List *l) {
//     List LOdd, LEven;
//     CreateList(&LOdd);
//     CreateList(&LEven);
//     Address p = *l;
//     while((p != NULL)) {
//         if (INFO(p) % 2 == 0) {
//             insertLast(&LEven, INFO(p));
//         }
//         else {
//             insertLast(&LOdd, INFO(p));
//         }
//         p = NEXT(p);
//     }
//     free(*l);
//     *l = concat(LOdd, LEven);
// }

void separateOddEven(List *l) {
    List LOdd, LEven;
    CreateList(&LOdd);
    CreateList(&LEven);

    Address p = *l;
    while (p != NULL) {
        if (INFO(p) % 2 == 0) {
            insertLast(&LEven, INFO(p));
        } else {
            insertLast(&LOdd, INFO(p));
        }
        p = NEXT(p);
    }

    // Dealokasi list lama jika perlu
    Address temp;
    while (*l != NULL) {
        temp = *l;
        *l = NEXT(*l);
        free(temp);
    }

    // Gabungkan dan assign kembali
    *l = concat(LOdd, LEven);  
}
