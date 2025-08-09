#include <stdio.h>

long long kombinasi(int n, int k){
    if (k > (n-k)){
        k = n-k;
    }
    long long res = 1;
    for (int i = 0 ; i < k ; i++){
        res = res * (n-i) / (i+1);
    }
    return res;
}

long long catalan(int n){
    return (kombinasi(2*n, n) / (n+1));
}

int main (){
    int n, k;
    scanf ("%d %d", &n, &k);
    printf("%lld", kombinasi(n, k));
    return 0;
}