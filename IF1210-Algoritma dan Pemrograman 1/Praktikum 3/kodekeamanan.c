#include <stdio.h>
void InputArray (long long T[], long long N){
    for (int i = 0 ; i < N ; i++){
        scanf("%lld", &T[i]);
    }
}

void MencariAngka (long long T[], long long N, long long target){
    long long hasil;
    int found = 0;
    for (long long i = 0 ; i < N && found == 0 ; i++){
        for (long long j = 0 ; j < N ; j++){
            if (i != j){
                hasil = T[i] + T[j];
                if (hasil == target){
                    if (i >= j){
                        printf("[%lld, %lld]\n", j, i);
                    }
                    else{
                        printf("[%lld, %lld]\n", i, j);
                    }
                    found = 1;
                    break;
                }
            }
        }
    }
}

int main (){
    long long N, target;
    scanf("%lld", &N);
    long long T[N];
    InputArray(T, N);
    scanf("%lld", &target);
    MencariAngka(T, N, target);
    return 0; 
}