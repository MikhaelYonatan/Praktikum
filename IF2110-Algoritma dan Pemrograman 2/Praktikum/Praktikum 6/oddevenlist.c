/* File: problem.c */
/* Implementasi fungsi untuk menyusun ulang linked list berdasarkan posisi ganjil dan genap */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk menyusun ulang elemen-elemen linked list sehingga
 * semua elemen pada posisi ganjil (1, 3, 5, ...) muncul lebih dulu,
 * diikuti oleh elemen pada posisi genap (2, 4, 6, ...).
 * Urutan relatif antar elemen ganjil maupun antar elemen genap
 * harus tetap dipertahankan.
 *
 * I.S.  : l terdefinisi, mungkin kosong
 * F.S.  : Elemen-elemen dalam list l diubah urutannya secara in-place
 *          tanpa alokasi/dealokasi node baru.
 *
 * Contoh:
 * Jika l adalah [1,2,3,4,5], maka setelah oddEvenLinkedList(&l), l menjadi [1,3,5,2,4]
 * Jika l adalah [10,20,30,40,50,60], maka hasilnya [10,30,50,20,40,60]
 * Jika l adalah [7], maka tetap [7]
 * Jika l adalah [], maka tetap []

*/

void oddEvenLinkedList(List *l) {
    // Kalo kosong return aja
    if (*l == NULL) return;

    // Kalo 1 elemen return aja
    if (NEXT(*l) == NULL) return;

    /* KAMUS LOKAL */
    Address lastOdd; // elemen ganjil yang terakhir kali diproses
    Address even; // elemen genap yang sedag diproses
    Address odd; // elemen ganjil yang sedang diproses

    // elemen pertama adalah elemen ganjil
    odd = *l;

    // elemen kedua adalah elemen genap yang akan diproses
    even = NEXT(odd);

    // elemen ganjil yang terakhir diproses adalah elemen pertama
    lastOdd = odd;

    // kalo masih ada elemen ganjil
    while (NEXT(even) != NULL) {

        // elemen ganjil yang sekarang diproses adalah suksesor elemen genap yang sedang diproses
        odd = NEXT(even);

        // suksesor elemen genap yang sedang diproses adalah elemen genap selanjutnya
        NEXT(even) = NEXT(odd);

        // tukar posisi elemen ganjil yang sedang diproses menjadi suksesor elemen ganjil terakhir
        NEXT(odd) = NEXT(lastOdd);
        NEXT(lastOdd) = odd;

        // elemen ganjil sekarang menjadi elemen ganjil yang terakhir diproses
        lastOdd = odd;

        // elemen genap yang akan diproses adalah suksesor elemen genap sekarang
        even = NEXT(even);

        // kalo habis, selesai
        if (even == NULL) break;
    }
}
