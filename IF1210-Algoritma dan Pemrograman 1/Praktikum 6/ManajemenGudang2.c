#include <stdio.h>
#include "liststatik.h"

int main (){
    int aksi, berat, indeks;
    ListStatik Gudang;
    CreateListStatik(&Gudang);
    for(;;){
        scanf("%d", &aksi);
        if (aksi == -1) break;
        else if (aksi == 1){
            scanf("%d %d", &berat, &indeks);
            if (listLength(Gudang) < CAPACITY && indeks >= 0 && indeks <= listLength(Gudang)){
                insertAt(&Gudang, berat, indeks);
                printList(Gudang);
                printf("\n");
            }
            else{
                printf("Aw, gabisa ngelakuin aksi itu\n");
                printList(Gudang);
                printf("\n");
            }
        }
        else if (aksi == 0){
            scanf("%d", &indeks);
            if (listLength(Gudang) != 0 && indeks >= 0 && indeks < listLength(Gudang)){
                deleteAt(&Gudang, &berat, indeks);
                printList(Gudang);
                printf("\n");
            }
            else{
                printf("Aw, gabisa ngelakuin aksi itu\n");
                printList(Gudang);
                printf("\n");
            }
        }
    }
    return 0;
}

