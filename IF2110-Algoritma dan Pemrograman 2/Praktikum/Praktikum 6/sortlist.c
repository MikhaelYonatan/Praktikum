#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Fungsi yang melakukan pengurutan dengan urutan menaik jika asc = true
 * dan menurun jika asc = false
 * 
 * I.S. List l terdefinisi dan berisi setidaknya 1 elemen
 * F.S. List l terurut secara urutan tertentu
 * 
 * Contoh: 
 * - Untuk l = [1, 5, 2, 3, 3], maka setelah sort(&l, true), l menjadi [1, 2, 3, 3, 5]
 */

int max(List *l) {
    Address p = FIRST(*l);
    int idx = 0, idx_target = 0;
    int val;
    int maksimum = INFO(p);

    while (p != NULL) {
        if (INFO(p) > maksimum) {
            maksimum = INFO(p);
            idx_target = idx;
        }
        p = NEXT(p);
        idx++;
    }
    deleteAt(l, idx_target, &val);
    return maksimum;
}

int min(List *l) {
    Address p = FIRST(*l);
    int idx = 0, idx_target = 0;
    int val;
    int minimum = INFO(p);

    while (p != NULL) {
        if (INFO(p) < minimum) {
            minimum = INFO(p);
            idx_target = idx;
        }
        p = NEXT(p);
        idx++;
    }
    deleteAt(l, idx_target, &val);
    return minimum;
}

void sort(List *l, boolean asc) {
    List sorted;
    CreateList(&sorted);
    int val;

    while (!isEmpty(*l)) {
        if (asc) val = min(l);
        else val = max(l);

        insertLast(&sorted, val);
    }

    FIRST(*l) = FIRST(sorted);
}
