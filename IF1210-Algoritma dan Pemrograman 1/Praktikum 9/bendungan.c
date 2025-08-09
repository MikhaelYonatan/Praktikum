#include <stdio.h>
#include "stack.h"

// int terbesar(Stack *S, int N){
//     int idxMax = 0;
//     for (int i = 0 ; i < N ; i++){
//         if(S->T[idxMax] < S->T[i]){
//             idxMax = i;
//         }
//     }
//     return idxMax;
// } 

// int main (){
//     Stack S;
//     int N, idx, decrease = 0, sum = 0;
//     scanf("%d", &N);
//     for (int i = 0 ; i < N ; i++){
//         scanf("%d", &S.T[i]);
//     }
//     int idxMax = terbesar(&S, N);
//     if (idxMax == 0 && idxMax == N-1){
//         if(S.T[0] < S.T[N-1]){
//             idx = 0;
//         }
//         else{
//             idx = N-1;
//         }
//     }

//     for (int i = 0+1 ; i < idxMax ; i++){
//         decrease += S.T[i];
//     }
//     sum = S.T[idx] * (N-2) - decrease;
//     printf("%d\n", sum);

//     return 0;
// }

#include "stack.h"
#include <stdio.h>

int main() {
    Stack p1, p2, p3, p4, t, q, r, r2, s;
    CreateEmpty(&p1);
    CreateEmpty(&p2);
    CreateEmpty(&p3);
    CreateEmpty(&p4);
    CreateEmpty(&t);
    CreateEmpty(&q);
    CreateEmpty(&r);
    CreateEmpty(&r2);
    CreateEmpty(&s);

    int n, d;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d);
        Push(&p1, d);
        Push(&p2, d);
        Push(&p3, d);
        Push(&p4, d);
    }
    for (int i = 0; i < n; i++) {
        Pop(&p1, &d);
        Push(&t, d);
    }

    int m = -1;
    for (int i = 0; i < n; i++) {
        Pop(&t, &d);
        if (m == -1 || d > m) m = d;
        Push(&q, m);
    }
    m = -1;
    for (int i = 0; i < n; i++) {
        Pop(&p3, &d);
        if (m == -1 || d > m) m = d;
        Push(&r, m);
    }
    
    // Reverse r
    for (int i =0 ; i < n; i++) {
        Pop(&r, &d);
        Push(&r2, d);
    }

    int d2;
    for(int i = 0; i < n; i++) {
        Pop(&q, &d);
        Pop(&r2, &d2);
        if (d2 > d) Push(&s, d);
        else Push(&s, d2);
    }
    
    // S - P3
    int sum = 0;
    for (int i = 0; i < n; i++) {
        Pop(&s, &d);
        Pop(&p4, &d2);
        sum += d - d2;
    }
    printf("%d\n", sum);
}