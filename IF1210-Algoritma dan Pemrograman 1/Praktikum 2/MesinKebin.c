#include <stdio.h>
void countPrime(int A, int B, int *total){
    int false = 0, p = 1;
    while (A <= B){
        while (p <= A){
            if (A % p == 0){
                if (p != 1 && p != A){
                    false = 1;
                }
            }
            p++;
        }
        if (false == 1){
            false = 0;
            p = 1;
            A++;
        }
        else{
            A++;
            p = 1;
            (*total)++;
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