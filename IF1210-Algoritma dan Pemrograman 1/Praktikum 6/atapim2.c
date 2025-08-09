int main (){
    int temp, result1, result2, k;
    ListDin L;
    readList(&L);
    k = -1;
    for (int i = 0 ; i < (listLength(L)-1) ; i++){
        result1 = abs(L.buffer[i] - L.buffer[i+1]);
        result2 = abs(L.buffer[i+1] - L.buffer[i+2]);
        temp = GCD(result1, result2);
        if (temp > k){
            k = temp;
        }
    }
    printf("%d\n", k);
    return 0;
}