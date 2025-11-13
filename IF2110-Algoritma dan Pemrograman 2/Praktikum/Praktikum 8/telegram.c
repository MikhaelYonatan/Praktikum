/* File: telegram.c */
/* Implementasi fungsi untuk memproses dan menghitung biaya telegram */

#include "mesinkata.h"
#include "boolean.h"
#include "string.h"
#include <stdio.h>

/*
 * Fungsi untuk membandingkan apakah sebuah Word sama dengan string tertentu
 * Dua kata dikatakan sama jika panjang dan urutan karakternya identik
 * I.S. K1 dan str terdefinisi
 * F.S. Mengembalikan true jika K1 sama dengan str, false jika tidak
 *
 * Contoh:
 * - K1 = "KOMA", str = "KOMA" -> return true
 * - K1 = "TITIK", str = "KOMA" -> return false
 * - K1 = "", str = "" -> return true
 */
boolean IsKataSama(Word K1, char *str) {
    /* KAMUS LOKAL */
    // TODO: Deklarasikan variabel yang diperlukan

    /* ALGORITMA */
    // TODO: Implementasikan pengecekan kesamaan antara Word dan string
  int str_len = strlen(str);
  if (K1.Length != str_len) {
    return false;
  }
  for (int i = 0; i < K1.Length; i++) {
    if (K1.TabWord[i] != str[i]) {
        return false;
    }
  }
  return true;
}

/*
 * Fungsi utama untuk memproses telegram
 * Program membaca input telegram, menampilkan hasil konversi,
 * dan menghitung biaya berdasarkan aturan berikut:
 *
 * Aturan penulisan telegram:
 * - Setiap kata dipisahkan oleh satu atau lebih spasi.
 * - Tanda baca dituliskan dalam bentuk kata: "KOMA" dan "TITIK".
 * - Pita karakter diakhiri dengan karakter titik '.'.
 *
 * Aturan biaya telegram:
 * - Perhitungan biaya didasarkan pada jumlah kata yang dikirim (tanda baca tidak dihitung).
 * - Kata reguler (< 10 karakter) → biaya Rp1000
 * - Kata panjang (>= 10 karakter) → biaya Rp1500
 * - Jika jumlah kata (termasuk tanda baca) > 10 → potongan 10%.
 *
 * Output yang harus ditampilkan:
 * - Isi telegram setelah dikonversi ("KOMA" → ',', "TITIK" → '.')
 * - Jumlah kata reguler
 * - Jumlah kata panjang
 * - Total biaya yang harus dibayar
 *
 * Contoh:
 * Input  : SEGERA PULANG KOMA ADIK SAKIT TITIK.
 * Output :
 * SEGERA PULANG, ADIK SAKIT.
 * 4
 * 0
 * 4000
 *
 * Input  : APA KABAR TITIK SAYA SENANG MENERIMA TAWARANNYA KOMA SEGERA KIRIM PROPOSAL KE KANTOR BANDUNG TITIK.
 * Output :
 * APA KABAR. SAYA SENANG MENERIMA TAWARANNYA, SEGERA KIRIM PROPOSAL KE KANTOR BANDUNG.
 * 11
 * 1
 * 11250
 */
void processTelegram() {
    /* KAMUS LOKAL */
    // TODO: Deklarasikan variabel yang dibutuhkan
  int countReguler = 0;
  int countLong = 0;
  int totalKata = 0;
  int totalCost = 0;
  boolean firstWord = true;
  boolean discount = false;

    /* ALGORITMA */
    // TODO: Implementasikan langkah-langkah berikut:
    // Hint: Gunakan STARTWORD() untuk memulai pembacaan kata

    // 1. Selama belum EndWord:
    //    - Jika kata adalah "KOMA" → cetak ','
    //    - Jika kata adalah "TITIK" → cetak '.'
    //    - Jika bukan tanda baca → cetak kata (dengan 1 spasi antar kata)
    //      serta tambahkan ke hitungan kata reguler/panjang
    // 2. Hitung total biaya berdasarkan aturan:
    //      totalCost = countRegular*1000 + countLong*1500
    //      Jika countTotal > 10 → beri potongan 10%
    // 3. Cetak hasil akhir sesuai format contoh.
  STARTWORD();
  while(!EndWord) {
    boolean currPunc = false;
    if (IsKataSama(currentWord, "KOMA") || IsKataSama(currentWord, "TITIK")) {
      currPunc = true;
    }

    if (firstWord) {
      firstWord = false;
    }
    else {
      if (!currPunc) {
        printf(" ");
      }
    }

    if (IsKataSama(currentWord, "KOMA")) {
        printf(",");

    }
    else if (IsKataSama(currentWord, "TITIK")) {
        printf(".");
    }
    else {
      if (currentWord.Length < 10) {
        countReguler++;
      }
      else {
        countLong++;
      }
      for (int i = 0 ; i < currentWord.Length ; i++) {
        printf("%c", currentWord.TabWord[i]);
      }
    }
    totalKata++;
    ADVWORD();
  }
  printf("\n");
  printf("%d\n", countReguler);
  printf("%d\n", countLong);
  if (totalKata > 10) {
      discount = true;
  }
  
  totalCost = countReguler * 1000 + countLong * 1500;
  if (discount) {
      totalCost = (totalCost * 90) / 100;
  }

  printf("%d\n", totalCost);
}