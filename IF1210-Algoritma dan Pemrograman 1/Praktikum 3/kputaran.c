#include <stdio.h>
void InputArray (int T[], int N){
    for (int i = 0 ; i < N ; i++){
        scanf("%d", &T[i]);
    }
}

void MemutarArray(int T1 [], int T2 [], int N, int k){
    k = k % N;
    for (int i = 0 ; i < N ; i++){
        T2[(i + k) % N] = T1[i];
    }
    for (int i = 0 ; i < N ; i++){
        printf("%d", T2[i]);
        if (i < N - 1){
            printf(" ");
        }
    }
    printf("\n");
}


int main (){
    int N, k;
    scanf("%d", &N);
    int T1[N], T2[N];
    scanf("%d", &k);
    InputArray(T1, N);
    MemutarArray(T1, T2, N, k);
    return 0;
}
