#include <stdio.h>
#include "listkontigu.h" 

// Fungsi cek sort
boolean CekSorted(ListKontigu l){
    for (int i = 1 ; i < listLength(l) ; i++){
        if (ELMT(l, i) < ELMT(l, i-1)){ // Jika ada yang tidak terurut menaik maka false
            return FALSE;
        }
    }
    return TRUE; // Terurut sampai akhir
}

// Prosedur mengecek apakah jika di reverse maka terurut
void ReverseOnce(ListKontigu *l){
    int length = listLength(*l);
    int left = 0, right = length-1;

    // Cek dari kiri
    while (left < length-1 && ELMT(*l, left) <= ELMT(*l, left+1)){
        left++;
    }
    // Jika sudah terurut naik sampai akhir maka left akan = length-1
    if (left == length-1){
        printf("YA\n");
        return;
    }

    // Cek dari kanan
    while (right > 0 && ELMT(*l, right) >= ELMT(*l, right-1)){
        right--;
    }

    int leftres = left;
    int rightres = right;
    // Reverse segmen [left..right]
    while (left < right) {
        int temp = ELMT(*l, left);
        ELMT(*l, left) = ELMT(*l, right);
        ELMT(*l, right) = temp;
        left++;
        right--;
    }

    // Setelah reverse apakah jadi terurut menaik
    if(CekSorted(*l)){
        printf("YA\n");
        printf("%d %d\n", leftres, rightres);
    }
    else printf("TIDAK\n");
}

int main (){
    ListKontigu l;
    CreateList(&l);
    readList(&l);
    ReverseOnce(&l);
    return 0;
}

