#include <stdio.h>
#include "matrix.h"

int min (Matrix M, int idx){ // Nilai minimum pada baris
    int minval = ELMT(M, idx, 0);
    for (int j = 1 ; j < M.colEff ; j++){
        if (ELMT(M, idx, j) < minval){
            minval = ELMT(M, idx, j);
        }
    }
    return minval;
}

int max (Matrix M, int idx){ // Nilai maksimum pada kolom
    int maxval = ELMT(M, 0, idx);
    for (int j = 1 ; j < M.rowEff ; j++){
        if (ELMT(M, j, idx) > maxval){
            maxval = ELMT(M, j, idx);
        }
    }
    return maxval;
}

int main (){
    int row, col, count = 0;
    Matrix M;
    scanf("%d %d", &row, &col);
    readMatrix(&M, row, col);
    for (int i = 0 ; i < row ; i++){
        for (int j = 0 ; j < col ; j++){
            if (ELMT(M, i, j) == min(M, i) && ELMT(M, i, j) == max(M, j)){
                printf("(%d,%d,%d)\n", i, j, ELMT(M, i, j));
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}