#include "prioritas.h"
#include "queue.h"
#include <stdio.h>

// void prioritizeValue(Queue *q, int x){
//     Queue temp;
//     int sumx = 0;
//     CreateQueue(&temp);
//     for(int i = 0; i < length(*q); i++){
//         if(q->buffer[i] == x){
//             sumx += x;
//         }
//     }
//     int banyakx = sumx / x;
//     for(int i = 0; i < banyakx; i++){
//         enqueue(&temp, x);
//     }
//     for(int i = 0; i < length(*q); i++){
//         if(q->buffer[i] != x){
//             enqueue(&temp, q->buffer[i]);
//         }
//     }
// }

// void prioritizeValue(Queue *q, int x){
//     Queue temp;
//     int val;
//     CreateQueue(&temp);
//     IDX_HEAD(temp) = IDX_HEAD(*q);
//     IDX_TAIL(temp) = IDX_TAIL(*q);

//     for(int i = 0; i < length(*q); i++){
//         if(q->buffer[i] == x){
//             enqueue(&temp, x);
//         }
//     }
//     for(int i = 0; i < length(*q); i++){
//         if(q->buffer[i] != x){
//             enqueue(&temp, q->buffer[i]);
//         }
//     }
    
//     for (int i = 0 ; i < length(*q) ; i++){
//         dequeue(&temp, &val);
//         enqueue(q, val);
//     }
//     displayQueue(*q);
// }
// void prioritizeValue(Queue *q, int x) {
//     Queue temp;
//     CreateQueue(&temp);
    
//     ElType val;
//     int len = length(*q);

//     // Salin ke array temporer sambil memisahkan prioritas
//     for (int i = 0; i < len; i++) {
//         dequeue(q, &val);
//         if (val == x) {
//             enqueue(&temp, val);
//         }
//         enqueue(q, val); // Simpan ulang untuk loop kedua
//     }

//     // Loop kedua: enqueue non-prioritas ke temp
//     for (int i = 0; i < len; i++) {
//         dequeue(q, &val);
//         if (val != x) {
//             enqueue(&temp, val);
//         }
//     }

//     // Salin temp ke q (overwrite q)
//     CreateQueue(q); // kosongkan q
//     while (!isEmpty(temp)) {
//         dequeue(&temp, &val);
//         enqueue(q, val);
//     }

//     displayQueue(*q);
// }


// int main() {
//     Queue q;
//     CreateQueue(&q);

//     int n, x, val;
//     scanf("%d", &n);  

//     for (int i = 0; i < n; i++) {
//         scanf("%d", &val);
//         enqueue(&q, val);
//     }

//     scanf("%d", &x);  

//     prioritizeValue(&q, x);  

//     return 0;
// }

#include <stdio.h>
#include "prioritas.h"

void prioritizeValue(Queue *q, int x){
    Queue p, r;
    int N, d;
    // scanf("%d", &N);
    // CreateQueue(q);
    // for (int i = 0; i < N; i++) {
    //     scanf("%d", &d);
    //     enqueue(q, d);
    // }
    N = length(*q);
    CreateQueue(&p);
    CreateQueue(&r);
    for (int i=0; i<N;i++){
        dequeue(q, &d);
        if (d == x) enqueue(&r,d);
        else enqueue(&p,d);
    }
    int lenP = length(p);
    for (int i = 0; i< lenP;i++){
        // displayQueue(r);
        dequeue(&p,&d);
        enqueue(&r,d);
    }
    for (int i = 0; i < N; i++) {
        dequeue(&r, &d);
        enqueue(q, d);
    }
    // displayQueue(r);
}