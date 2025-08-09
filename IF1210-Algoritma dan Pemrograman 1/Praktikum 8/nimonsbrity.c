#include <stdio.h>
#include "matrix.h"

int main (){
    int N, id = -1;
    Matrix M;
    boolean nimonsbrity;
    scanf("%d", &N);
    readMatrix(&M, N, N);
    if (N == 1){
        printf("0\n");
    }
    else{
        for (int i = 0 ; i < N ; i++){
            nimonsbrity = TRUE;
            // Cek terlebih dahulu setiap KOLOM, 1 semua artinya dikenal semua
            for (int j = 0 ; j < N ; j++){
                if (ELMT(M, j, i) == 0){ // Ada yang gak kenal
                    nimonsbrity = FALSE;
                    break;
                }
            }
            // Cek kalau kenal semua, apakah dia kenal yang lain
            if (nimonsbrity){
                for (int j = 0 ; j < N ; j++){
                    if (i != j && ELMT(M, i, j) == 1){ // Ada yang dikenal
                        nimonsbrity = FALSE;
                        break;
                    }
                }
            }
            // Semua kenal, dan dia gak kenal semua
            if (nimonsbrity){
                id = i;
                break;
            }
        }
        printf("%d\n", id);
    }
    return 0;
}