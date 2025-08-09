#include <stdio.h>
#include "tester.h" // Comment this when developing in local
int main () {
    init(); // Comment this when developing in local
    FILE *f_a, *f_b;
    int ID_a, jumlah_a, ID_b, jumlah_b;
    f_a = fopen("file_a.txt", "r");
    f_b = fopen("file_b.txt", "r");
    fscanf(f_a, "%d %d", &ID_a, &jumlah_a);
    fscanf(f_b, "%d %d", &ID_b, &jumlah_b);
    while (ID_a != -1 && ID_b != -1){
        if (ID_a <= ID_b){
            printf("%d %d\n", ID_a, jumlah_a);
            fscanf(f_a, "%d %d", &ID_a, &jumlah_a);
        }
        else{
            printf("%d %d\n", ID_b, jumlah_b);
            fscanf(f_b, "%d %d", &ID_b, &jumlah_b);
        }
    }
    while (ID_a != -1){
        printf("%d %d\n", ID_a, jumlah_a);
        fscanf(f_a, "%d %d", &ID_a, &jumlah_a);
    }
    while (ID_b != -1){
        printf("%d %d\n", ID_b, jumlah_b);
        fscanf(f_b, "%d %d", &ID_b, &jumlah_b);
    }
    
    fclose(f_a);
    fclose(f_b);
    return 0;
}