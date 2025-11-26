/* File: problem.c */
/* Implementasi fungsi untuk merotasi linked list ke kanan sebanyak k posisi */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk merotasi linked list ke kanan sebanyak k posisi.
 * Rotasi ke kanan artinya elemen-elemen terakhir dipindahkan ke depan.
 * 
 * I.S.  : l terdefinisi, mungkin kosong; k >= 0
 * F.S.  : Mengembalikan list baru yang merupakan hasil rotasi l sebanyak k posisi ke kanan.
 *         List asli l tidak dimodifikasi (fungsional approach).
 *         Jika k lebih besar dari panjang list, gunakan k modulo panjang list.
 *
 * Contoh:
 * Jika l adalah [1,2,3,4,5] dan k=2, maka hasil [4,5,1,2,3]
 * Jika l adalah [1,2,3,4,5] dan k=0, maka hasil [1,2,3,4,5]
 * Jika l adalah [1,2,3,4,5] dan k=7, maka hasil [4,5,1,2,3] (karena 7 % 5 = 2)
 */

List rotateRight(List l, int k) {
  if (isEmpty(l)) {
    return l;
  }
  else {
    if (k % length(l) == 0) {
      return l;
    }
    else {
      List p = NIL;
      while (NEXT(l) != NIL) {
        p = konsDot(p, head(l));
        l = NEXT(l);
      }
      l = concat(l, p);    
      return rotateRight(l, (k % length(l)) - 1);
    }
  }
}

// #include <stdio.h>
// int main () {
//     List l = NIL;
//     int n, k, val;
//     scanf("%d", &n);
//     for (int i = 0 ; i < n ; i++) {
//         scanf("%d", &val);
//         l = konsDot(l, val);
//     }
//     scanf("%d", &k);

//     l = rotateRight(l, k);
//     displayList(l);
//     return 0; 
// }