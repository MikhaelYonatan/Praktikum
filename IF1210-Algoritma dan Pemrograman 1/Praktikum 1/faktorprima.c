#include <stdio.h>
int main () {
    int bil, p, temp, first;
    scanf("%d", &bil);
    p = 2;
    temp = 0;
    first = 1;
    while (bil != 1){
        if (bil % p == 0){
            do {
                bil = bil/p;
                temp = temp + 1;
            } while (bil % p == 0);
            if (first == 1){
                if (temp > 1){
                    printf("%d^%d", p, temp);
                    first = 0;
                }
                else {
                    printf("%d", p);
                    first = 0;
                }
            }
            else{
                if (temp > 1){
                    printf(" * ");
                    printf("%d^%d", p, temp);
                }
                else {
                    printf (" * ");
                    printf("%d", p);
                }
            }
            temp = 0;
            p = p + 1;
        }
        else{
            p = p + 1;
        }
    }
    printf("\n");
    return 0;
}
