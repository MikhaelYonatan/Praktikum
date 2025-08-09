#include <stdio.h>

void InputArray (int T[], int N){
    for (int i = 0 ; i < N ; i++){
        scanf("%d", &T[i]);
    }
}

int BinarySearch(int arr[], int left, int right, int target){
    int mid, result = -1;
    while (left <= right){
        mid = (left + right) / 2;
        if (arr[mid] == target){
            result = mid;
            right = mid-1;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }
    return result;
}

int main (){
    int N, Q, QQue, x ;
    scanf("%d", &N);
    int T[N];
    InputArray(T, N);
    scanf("%d", &Q);
    int Tab[Q];
    for (int i = 0 ; i < Q ; i++){
        scanf("%d", &QQue);
        x = BinarySearch(T, 0, (N-1), QQue);
        Tab[i] = x;
    }
    printf("[");
    for (int i = 0 ; i < Q ; i++){
        printf("%d", Tab[i]);
        if (i < Q - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    return 0;
}