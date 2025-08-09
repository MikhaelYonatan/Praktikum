#include <stdio.h>
#include "stack.h"
int terbesar(Stack *S, int pengulang, int start){
    int max = S->T[start];
    for (int n = 0 ; n < pengulang ; n++){
        if(max < S->T[start + n]){
            max = S->T[start + n];
        }
    }
    return max;
}

int main(){
    int N;
    int sum = 0;
    scanf("%d", &N);
    Stack S;

    for(int i = 0; i < N; i++){
        scanf("%d", &S.T[i]);
        sum += S.T[i];
    }
    if(N>= 2){
        for(int i = 2; i <= N; i++){
            for(int j = 0; j <= N - i; j++){
                sum += terbesar(&S, i, j);
            }
        }
    }
    printf("%d\n", sum);
}


// #include <stdio.h>
// int terbesar(int t[], int pengulang, int start){
//     int max = t[start];
//     for (int n = 0 ; n < pengulang ; n++){
//         if(max < t[start + n]){
//             max = t[start + n];
//         }
//     }
//     return max;
// }

// int main(){
//     int N;
//     int sum = 0;
//     scanf("%d", &N);
//     int t[N];

//     for(int i = 0; i < N; i++){
//         scanf("%d", &t[i]);
//         sum += t[i];
//     }
//     if(N>= 2){
//         for(int i = 2; i <= N; i++){
//             for(int j = 0; j <= N - i; j++){
//                 sum += terbesar(t, i, j);
//             }
//         }
//     }
//     printf("%d\n", sum);
// }