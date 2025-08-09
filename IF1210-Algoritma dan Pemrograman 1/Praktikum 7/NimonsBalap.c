#include <stdio.h>
#include "listkontigu.h" 

// Fungsi mencari nilai max dari "jendela"
int MAX(ListKontigu l, int first, int last){
    int max = ELMT(l, first);
    for (int i = first + 1 ; i <= last ; i++){
        if (max < ELMT(l, i)){
            max = ELMT(l, i);
        }
    }
    return max;
}

int main (){
    ListKontigu l, temp;
    int k, val;
    CreateList(&l);
    CreateList(&temp);
    readList(&l);
    scanf("%d", &k);
    // Secara traversal dari indeks 0 sampai indeks terakhir dapat mengandung k bilangan
    // indeks 0 sampai length-k
    for (int i = 0 ; i <= (listLength(l)-k) ; i++){
        int first = i; // Indeks pertama
        int last = i + k - 1; // Indeks terakhir (per set k)
        val = MAX(l, first , last);
        ELMT(temp, i) = val;
    }
    printList(temp);
    printf("\n");
    return 0;
}