#include<stdio.h>

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    long long a[n];
    long long aurut[n];
    long long max;
    long long pembanding;
    max=0;
    pembanding=0;
    int i;
    
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        aurut[i]=a[i];    
    }

    if(a[0]>=a[n-1]){
        max+=a[0];
    }
    else if(a[n-1]>a[0]){
        max+=a[n-1];
    }

    int j;
    int min;
    int temp;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(aurut[min]>aurut[j]){
                min=j;
            }
        }
        temp=aurut[i];
        aurut[i]=aurut[min];
        aurut[min]=temp;
    }
    
    if(max==aurut[n-1]){
        max+=aurut[n-2];
    }
    else if(max<aurut[n-1]){
        max+=aurut[n-1];
    }

    //karena lakuinnya berapa pun k minimal 2 kali jadi tes yang max nya cuman 2 kali, lalu sisanya k+1 kali
    
    if(k>1){ //apakah ambil lebih dari 1 atau tidak
        int countk=k+1; // selalu 1 lebih dari k
        for(i=n-1;i>=0;i--){
            if(aurut[i]<0 && countk<k-1){ //minimal lakukan 2 kali, kalau di bawah 2 kali negatif pun harus ditambahkan
                break; 
            }
            pembanding+=aurut[i];
            countk-=1;
            if(countk==0){
                break;
            }
        }
    }

    if(max>=pembanding){
        printf("%lld\n",max);
    }
    else{
        printf("%lld\n",pembanding);
    }
    return 0;
}