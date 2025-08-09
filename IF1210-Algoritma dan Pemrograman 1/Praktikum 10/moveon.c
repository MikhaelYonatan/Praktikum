#include <stdio.h>
#include "listlinier.h"
#include "stdlib.h"

/*
 * Fungsi : removeAll
 * -------------------
 * Menghapus semua elemen dalam list yang memiliki nilai info sama dengan 'val'.
 *
 * Parameter:
 *  - l   : pointer ke list yang akan dimodifikasi
 *  - val : nilai elemen yang ingin dihapus dari list
 *
 * Deskripsi:
 *  - Fungsi ini melakukan traversal pada list l dan menghapus semua node
 *    yang memiliki nilai INFO(node) == val.
 *  - Penghapusan dilakukan dengan benar, termasuk menangani kasus:
 *      - Node yang dihapus berada di awal list
 *      - Node yang dihapus berada di tengah list
 *      - Node yang dihapus berada di akhir list
 *  - Setelah node dihapus, memori dari node tersebut harus di-dealokasi (menggunakan free).
 *
 * Aturan:
 *  - Tidak boleh menggunakan array tambahan, struktur data lain, atau rekursi.
 *  - Hanya boleh menggunakan operasi pointer dan fungsi dari ADT listlinier.h
 *  - Tidak memodifikasi nilai dari node lain, hanya menghapus node yang sesuai.
 *
 * Contoh:
 *  - Jika list l = [1, 2, 2, 3, 2, 4] dan val = 2,
 *    maka setelah removeAll(&l, 2), list menjadi [1, 3, 4]
 */
void removeAll(List *l, ElType val){
    Address p = *l;
    Address prev = NULL;
    while (p != NULL) {
        if (INFO(p) == val) {
            Address temp = p;
            if (prev == NULL) { // Node pertama
                *l = NEXT(p);
                p = NEXT(p);
            } else {
                NEXT(prev) = NEXT(p);
                p = NEXT(p);
            }
            free(temp);
        } else {
            prev = p;
            p = NEXT(p);
        }
    }
    displayList(*l);
    printf("\n");
}

// void removeAll(List *l, ElType val) {
//     while(1) {
//         Address p = *l;
//         int i = 0;
//         int val1;
//         int state = 1;
//         while((p != NULL) && (state)) {
//             if (INFO(p) == val) {
//                 deleteAt(l, i, &val1);
//                 state = 0;
//             }
//             i++;
//             p = NEXT(p);
//         }
//         if (p == NULL) {
//             break;
//         }
//     }
//     displayList(*l);
//     printf("\n");
// }


// int main(){
//     int N, val, X;
//     List L;
//     CreateList(&L);

//     scanf("%d", &N);
//     for (int i = 0 ; i < N ; i++){
//         scanf("%d", &val);
//         insertLast(&L, val);
//     }

//     scanf("%d", &X);
//     removeAll(&L, X);
//     return 0;
// }
