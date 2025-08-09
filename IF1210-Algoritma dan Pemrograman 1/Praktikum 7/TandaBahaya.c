#include <stdio.h>
#include "listkontigu.h" 

int main (){
    ListKontigu l;
    CreateList(&l);
    readList(&l);
    boolean found = FALSE;
    for (int i = firstIdx(l) ; i < (listLength(l)-2) ; i++){ // Digit pertama
        for (int j = i+1 ; j < (listLength(l)-1) ; j++){ // Digit kedua
            for (int k = j+1 ; k < listLength(l) ; k++){ // Digit ketiga
                if (ELMT(l, i) < ELMT(l, k) && ELMT(l, k) < ELMT(l, j) && !(found)){ // Jika memenuhi syarat
                    found = TRUE;
                }
            }
        }
    }
    if (found){
        printf("Nyalakan\n");
    }
    else{
        printf("Santai\n");
    }
    return 0;
}
