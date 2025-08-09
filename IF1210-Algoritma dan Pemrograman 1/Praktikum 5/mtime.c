#include "time.h"
#include "boolean.h"
#include <stdio.h>

int main (){
    int input;
    TIME T1, T2, MAX, MIN;
    scanf("%d", &input);
    for (int i = 1 ; i <= input ; i++){
        printf("[%d]\n", i);
        BacaTIME(&T1);
        BacaTIME(&T2);
        if (TIMEToDetik(T1) > TIMEToDetik(T2)){
            printf("%ld\n", Durasi(T2, T1));
            if (i == 1){
                MAX = T1;
                MIN = T2;
            }
            else{
                if(TIMEToDetik(T1) > TIMEToDetik(MAX)){
                    MAX = T1;
                }
                if (TIMEToDetik(T2) < TIMEToDetik(MIN)){
                    MIN = T2;
                }
            }
        }
        else{
            printf("%ld\n", Durasi(T1, T2));
            if (i == 1){
                MAX = T2;
                MIN = T1;
            }
            else{
                if(TIMEToDetik(T2) > TIMEToDetik(MAX)){
                    MAX = T2;
                }
                if (TIMEToDetik(T1) < TIMEToDetik(MIN)){
                    MIN = T1;
                }
            }
        }
    }
    TulisTIME(MIN);
    printf("\n");
    TulisTIME(MAX);
    printf("\n");
    return 0;
}