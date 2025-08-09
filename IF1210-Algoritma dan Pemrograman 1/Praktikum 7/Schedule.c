#include <stdio.h>
#include "listkontigu.h" 

int main (){
    ListKontigu l;
    CreateList(&l);
    int n, val, indeks;
    scanf("%d", &n);
    // Kalau kosong (n = 0) ternyata gak usah ngapa-ngapain :)
    // Kalau gak kosong baru minta input, insert, dan print
    for (int i = 0 ; i < n ; i++){
        scanf("%d", &val);
        if (isEmpty(l)){ // Jika array masih kosong, taruh aja di indeks 0
            insertAt(&l, val, 0);
        }
        else{ // Sudah ada isi 
            boolean found = FALSE;
            for (int j = 0 ; j < listLength(l) && !(found) ; j++){ // Cek untuk diurutkan
                if (getElmt(l, j) > val){
                    indeks = j;
                    found = TRUE;
                    break;
                }
            }
            if (found) insertAt(&l, val, indeks); // Jika ketemu, maka taro di indeks itu
            else setElmt(&l, listLength(l), val); // Gak ketemu berarti val paling besar jadi taruh di akhir
        }
        printList(l);
        printf("\n");        
    } 
    return 0;
}