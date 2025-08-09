#include <stdio.h>
// void countPrime(int A, int B, int *total){
//     int false = 0;
//     for (int i = A ; i <= B ; i++){
//         for (int j = 2 ;  j <= i ; j++){
//             if (i % j == 0){
//                 if (j != i){
//                     false = 1;
//                 }
//             }
//         }
//         if (false == 0){
//             *total += 1;
//         }
//         else{
//             false = 0;
//         }
//     }
// }

void countPrime(int A, int B, int *total){
    for (int i = A ; i <= B ; i++){
        if (i > 1) {
            int false = 0;
            for (int j = 2 ;  j <= i ; j++){
                if (i % j == 0){
                    if (j != i){
                        false = 1;
                        break;
                    }
                }
            }
            if (false == 0){
                *total += 1;
            }
        }
    }
}



int main () {
    int A, B, total = 0;
    scanf("%d", &A);
    scanf("%d", &B);
    countPrime (A, B, &total);
    printf("%d\n", total);
    return 0;
}