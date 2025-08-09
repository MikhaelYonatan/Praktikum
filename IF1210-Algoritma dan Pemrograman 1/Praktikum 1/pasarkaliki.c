// #include <stdio.h>
// int main (){
//     int n, k, x, i, j, a, b, c, m, l, s;
//     long long p;
//     scanf("%d", &n);
//     if (n == 1){
//         printf("1\n");
//     }
//     else{ // n > 1
//         x = n-1;
//         for (i = 1 ; i <= x ; i ++)
//             printf(" ");
//         printf("1\n");

//         for (i = 1 ; i <= x ; i++){
//             for (s = 0 ; s <= (n - i - 2) ; s ++){
//                 printf(" ");
//             }
//             for (j = 0 ; j <= i ; j++){
//                 if (j == 0) {
//                     printf("1");
//                 }
//                 else {
//                     if (i == j){
//                         printf(" 1");
//                     }
//                     else{
//                         b = i;
//                         c = j;
//                         for (k = (i-1) ; k >= 1 ; k--){
//                             b = b * k;
//                         }
//                         for (l = (j-1) ; l >= 1 ; l--){
//                             c = c * l;
//                         }
//                         a = i - j;
//                         for (m = (a-1) ; m >= 1 ; m--){
//                             a = a * m;
//                         }
//                         p = b / (c*a);
//                         printf(" %lld", p);
//                     }

//                 }
//             }
//             printf("\n");
//         }

//     }
//     return 0;
// }

// #include <stdio.h>

// int main() {
//     int N;
//     scanf("%d", &N);
    
// //    unsigned int pascal[N][N];
//     long long pascal [N][N];
    
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N - i - 1; j++) {
//             printf(" "); 
//         }
//         for (int j = 0; j <= i; j++) {
//             if (j == 0 || j == i) {
//                 pascal[i][j] = 1;
//             } else {
//                 pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
//             }
//             if (j > 0){
//                 printf(" ");
//             } 
//             printf("%lld", pascal[i][j]);
//         }
//         printf("\n");
//     }
    
//     return 0;
// }

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        long long num = 1;
        for (int j = N-1; j > i; j--) {
            printf(" ");
        }
        printf("%lld", num);
        for (int j = 1; j <= i; j++) {
            num *= i - (j-1);
            num /= (j-1) + 1;
            printf(" %lld", num);
        }
        printf("\n");
    }
}