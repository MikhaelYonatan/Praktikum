#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listdin.h"

int main(){
    int lomba, x;
    ListDin L;
    scanf("%d", &lomba); // input berapa kali lomba lari
    CreateListDin(&L, lomba*5); //inisialisasi list dinamis sebesar 5 (jumlah nimons) kali banyak lomba

    //Mengisi timeset tiap nimons per 5 data sebanyak jumlah lomba dalam satu array
    for (int i = 0 ; i < lomba ; i++){
        for (int j = 0 ; j < 5 ; j++){
            scanf("%d", &x);
            L.buffer[i*5+j] = x;
            L.nEff++;
        }
    }
    
    //Memasukkan lomba pertama dan terakhir ke array
    int first[5], last[5];
    for (int i = 0 ; i < 5 ; i++){
        first[i] = L.buffer[i];
        last[i] = L.buffer[(lomba-1)*5+i];
    }

    //Menghitung hasil mean dan memasukannya ke array hasil
    float hasil[5];
    int minIdx = 0;
    for (int i = 0 ; i < 5 ; i++){
        hasil[i] = ((float)(last[i] - first[i]))/lomba;
        if (hasil[i] < hasil[minIdx]){
            minIdx = i;
        }
    }

    //minIdx menentukan nimons mana yang meannya paling kecil
    char *nama[5] = {"Kebin", "Stewart", "Pop", "Luiy", "Toto"};
    printf("%s\n", nama[minIdx]);
    return 0;
}