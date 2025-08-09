#include "queue.h"
#include <stdio.h>

int main(){
    int N;
    Queue q;
    scanf("%d", &N);
    CreateQueue(&q);
    for(int i = 0; i< N; i++){
        scanf("%d", &q.buffer[i]);
    }

    if(N == 0){
        printf("[]\n");
    }else{
        q.idxHead = 0;
        q.idxTail = N- 1;
        for(int i = 0; i < N - 1; i++){
            for(int j = N-1 ; j > i ; j--){
                if(q.buffer[j] > q.buffer[j - 1]){
                    int temp = q.buffer[j];
                    q.buffer[j] = q.buffer[j-1];
                    q.buffer[j-1] = temp;
                }
            }
        }
        displayQueue(q);

    }
    return 0;
}