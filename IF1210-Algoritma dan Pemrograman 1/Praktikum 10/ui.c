#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
// Diperbolehkan membuat fungsi antara jika dibutuhkan!

void dealokasiList(List *l) {
    Address p_current = FIRST(*l); // Dapatkan pointer ke elemen pertama
    Address p_next;

    while (p_current != NULL) {
        p_next = NEXT(p_current); // Simpan pointer ke elemen berikutnya
        free(p_current);          // Bebaskan memori elemen saat ini
        p_current = p_next;       // Pindah ke elemen berikutnya
    }

    *l = NULL; // Setelah semua node dibebaskan, set pointer list utama ke NULL
}

void insertSorted(List *l, ElType val) {
    Address p = *l;
    int i = 0;
    while(p != NULL) {
        if (INFO(p) > val) {
            break;
        }
        p = NEXT(p);
        i++;
    }
    insertAt(l, val, i);
}

List getUnion(List l1, List l2) {
    List l3;
    CreateList(&l3);
    Address p1 = l1;
    Address p2 = l2;
    while(p1 != NULL) {
        if (indexOf(l3, INFO(p1)) == IDX_UNDEF) {
            insertSorted(&l3, INFO(p1));   
        }
        p1 = NEXT(p1);
    }
    while(p2 != NULL) {
        if (indexOf(l3, INFO(p2)) == IDX_UNDEF) {
            insertSorted(&l3, INFO(p2));
        }
        p2 = NEXT(p2);
    }

    return l3;
}

List getIntersect(List l1, List l2) {
    List l3;
    CreateList(&l3);
    Address p1 = l1;
    Address p2 = l2;
    while(p1 != NULL) {
        if ((indexOf(l3, INFO(p1)) == IDX_UNDEF) && (indexOf(l2, INFO(p1)) != IDX_UNDEF)) {
            insertSorted(&l3, INFO(p1));   
        }
        p1 = NEXT(p1);
    }
    while(p2 != NULL) {
        if ((indexOf(l3, INFO(p2)) == IDX_UNDEF) && (indexOf(l1, INFO(p2)) != IDX_UNDEF)) {
            insertSorted(&l3, INFO(p2));
        }
        p2 = NEXT(p2);
    }

    return l3;
}

void getData(List *Union, List *Irisan) {
    int n;
    scanf("%d", &n);
    int j = 0;
    while(j < n) {
        List L;
        CreateList(&L);
        int x;
        scanf("%d", &x);
        int i = 0;
        while(i < x) {
            int temp;
            scanf("%d", &temp);
            insertLast(&L, temp);
            i++;
        }
        if (j == 0) {
            *Union = getUnion(L,L);
            *Irisan = getIntersect(L,L);
        }
        else {
            *Union = getUnion(*Union, L);
            *Irisan = getIntersect(*Irisan,L);
        }
        dealokasiList(&L);
        j++;
    }
    
}