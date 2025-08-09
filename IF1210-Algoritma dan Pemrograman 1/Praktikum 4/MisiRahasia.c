#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

int main() {
    init();
    FILE *f;
    int ID, success, value, total_misi = 0, total_success = 0, total_nilai = 0;
    f = fopen("input.txt", "r");
    fscanf(f, "%d %d %d", &ID, &success, &value);
    while (ID != -1){
        total_misi++;
        if (success == 1){
            total_success++;
            total_nilai += value;
        }
        fscanf(f, "%d %d %d", &ID, &success, &value);
    }
    printf("Total Misi: %d\n", total_misi);
    printf("Misi Berhasil: %d\n", total_success);
    printf("Total Nilai Misi: %d\n", total_nilai);
    fclose(f);
    return 0;
}