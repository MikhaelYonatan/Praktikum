#include <stdio.h>
int main(){
    int N, a, digit1, balik = 0;
    scanf("%d", &N);
    a = N;

    while (a>0){
        digit1 = a%10;
        balik = balik* 10 + digit1;
        a = a/10;
       
    }
    if (N == balik){
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}

// //Ini nilainya 80
// int main () {
//     int N, i, x, y, z, first, count, n;
//     scanf("%d", &N);
//     i = 1;
//     x = 1;
//     count = 0;
//     first = 1;
//     z = N;
//     // Mencari ada berapa banyak digit dengan cara membagi z = N sampai 0, namun nilai i dan count terakhir disimpan
//     while (z != 0){
//         i = i*10;
//         z = N / (i);
//         count += 1;
//     }
//     // Menggunakan nilai i sebelumnya dan dibagi 10 untuk mencari pembagi agar mendapatkan digit pertama
//     i = i/10;
//     y = N;
//     n = 0;
//     // selama n != count, maka dilakukan pengecekan tiap digitnya. Yang x dari belakang yang i dari depan
//     while (n != count){
//         if (((N/(x)) % 10) != (y/i)){
//             printf("0\n");
//             break;
//         }
//         else {
//             // x dikali 10 sehingga pengecekan terus maju (dari digit akhir ke paling awal)
//             // sementara y dimodulo i sehingga digit awal yang sudah diperiksa akan hilang dan i dibagi 10 sehingga pengecekan mundur (dari awal ke akhir)
//             x = x * 10;
//             y %= i;
//             i /= 10;
//             n += 1;
//         }
//     }
//     // program akan keluar dari loop while apabila n == count, dan ketika n == count maka artinya digit awal dan akhir selalu sama
//     if (n == count) {
//         printf("1\n");
//     }
//     return 0;
// }
