#include <stdio.h>
// // kalau j nya juga int maka 5/2 == 2 karena int/int = int dalam hal ini 5/2 = 2
// int main () {
//     int N, i, j, temp;
//     temp = 0;
//     scanf("%d", &N);
//     for (i = 1 ; i <= N ; i++) {
//         if (N % i == 0){
//             for (j = 1 ; j<=i ; j++){
//                 if (i/j == j){
//                     temp = temp + 1;
//                 }
//             }
//         }
//     }
//     printf("%d\n", temp);
//     return 0;
// }

// kalau j nya float maka aman 5/2 != 2 justru = 2.5 karena int/float maka int promosi ke float dan hasilnya float
int main () {
    int N, i, temp;
    float j;
    temp = 0;
    scanf("%d", &N);
    for (i = 1 ; i <= N ; i++) {
        if (N % i == 0){
            for (j = 1 ; j<= i ; j++){
                if (i/j == j){
                    temp = temp + 1;
                }
            }
        }
    }
    printf("%d\n", temp);
    return 0;
}