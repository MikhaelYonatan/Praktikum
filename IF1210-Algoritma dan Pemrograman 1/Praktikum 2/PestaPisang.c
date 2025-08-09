#include <stdio.h>
int TotalPisang (int K, int S, int P, int B, int T){
    return (K + S + P + B + T);
}

float MeanPisang (float TP){
    return (TP / 5);
}

void PesanPesta (float MP){
    if (MP >= 10){
        printf("Pesta Nimons Sukses!\n");
    }
    else{
        printf("Pesta Nimons Gagal, kumpulkan lebih banyak pisang!\n");
    }
}


int main (){
    int K, S, P, B , T;
    scanf("%d %d %d %d %d", &K, &S, &P, &B, &T);
    printf("%d\n", TotalPisang(K, S, P, B, T));
    printf("%.6f\n", MeanPisang(TotalPisang(K, S, P, B, T)));
    PesanPesta(MeanPisang(TotalPisang(K, S, P, B, T)));
    return 0;
}
