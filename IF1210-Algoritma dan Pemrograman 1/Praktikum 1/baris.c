#include <stdio.h>

int main(){
    int N; int x = 1; int v = 1;
    int y = 1; // penambah ke kanan 
    int z = 1; // penambah ke bawah
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        y = i;
        int lewat = 0;
        int done = 0;
        if(y == N-1){
            lewat = 1;
            done = 1;
            y = N;
        }

        x = v;
        v = x;
        for(int j = 0; j < N; j++){
            printf("%d", x);
            if(j != N-1) printf(" ");
            if(lewat == 0){
                y += 1;
            } else{
                y -= 1;
            }
            x += y;
            if(y >= N-1 && done == 0){
                lewat = 1;
                done = 1;
                y++;
            }
        }
        z++;
        v += z;
        printf("\n");
    }
}