#include <stdio.h>

long long kombinasi(int n, int k){
    long long pem = 1, pen = 1;
    for (int i = n ; i > k ; i--){
        pem *= i;
        pen *= (i-k);
    }
    return (pem/pen);
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