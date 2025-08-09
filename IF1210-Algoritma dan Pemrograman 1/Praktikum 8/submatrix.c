#include <stdio.h>
#include "matrix.h"

int sum(Matrix M, int idxi, int idxj, int K){
    int sumi = 0;
    for (int i = idxi; i < K + idxi; i++){
        for (int j = idxj; j < K + idxj; j++){
            sumi += ELMT(M, i, j);
        }   
    }
    return sumi;
}

int main(){
    Matrix matrix;
    int N, M, K, X, tot = 0;
    scanf("%d %d %d %d", &N, &M, &K, &X);
    readMatrix(&matrix, N, M);
    for (int i = 0; i < N - K + 1; i++){
        for (int j = 0; j < M - K + 1; j++){
            if (sum(matrix, i, j, K) <= X){
                tot++;
            }
        }
    }
    printf("%d\n", tot);
    return 0;
}