#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

typedef struct Nimons{
    int ID;
    int success;
    int value;
} Nimons;

// selection sort prioritas 2 dan 3
void SelectionSort(Nimons arr[], int N){
    Nimons temp;
    int Imin;
    for (int pass = 0 ; pass < N-1 ; pass++){
        Imin = pass;
        for (int i = pass + 1 ; i < N ; i++){
            if (arr[i].value < arr[Imin].value || (arr[i].value == arr[Imin].value && arr[i].ID < arr[Imin].ID)) {
                Imin = i;
            }
        }
        temp = arr[Imin];
        arr[Imin] = arr[pass];
        arr[pass] = temp;
    }
}


int main() {
    init();
    FILE *f_int, *f_que;
    int Nmax = 1000;
    int ID, success, value, i = 0, j = 0, a, b;
    Nimons Tab0[Nmax], Tab1[Nmax];
    f_int = fopen("input.txt", "r");
    f_que = fopen("query.txt", "r");

    // prioritas 1, membaginya ke 2 array berbeda untuk success = 0 dan success = 1
    while (fscanf(f_int, "%d %d %d", &ID, &success, &value) == 3){
        if (ID == -1 && success == 0 && value == 0) break;
        if (success == 0){
            Tab0[i].ID = ID;
            Tab0[i].success = success;
            Tab0[i].value = value;
            i++;
        }
        else{
            Tab1[j].ID = ID;
            Tab1[j].success = success;
            Tab1[j].value = value;
            j++;
        }
    }


    // mengurutkan kedua array berdasarkan prioritas 2 dan 3
    SelectionSort(Tab0, i);
    SelectionSort(Tab1, j);

    // menggabungkan kedua array terurut
    int x = 0;
    while (x < j){
        Tab0[i] = Tab1[x];
        i++;
        x++;
    }
    
    // membaca kueri
    fscanf(f_que, "%d", &a);
    int y = 1;
    while (y <= a){
        fscanf(f_que, "%d", &b);
        printf("%d %d\n", Tab0[b-1].ID, Tab0[b-1].value);
        y++;
    }

    fclose(f_que);
    fclose(f_int);
    return 0;
}