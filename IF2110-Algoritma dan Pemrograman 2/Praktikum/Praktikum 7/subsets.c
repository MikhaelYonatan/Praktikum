#include <stdio.h>

void printSub(int* X, int n) {
  printf("[");
  for (int i = 0 ; i < n ; i ++) {
    printf("%d", X[i]);
    if (i < n-1) {
      printf(",");
    }
  }
  printf("]\n");
}

void subsets(int N, int* L, int i, int* subset, int subsetLength,int idx){
  if (subsetLength == i) {
    printSub(subset, subsetLength);
  }
  else {
    for (int j = idx ; j < N ; j++) {
      subset[subsetLength] = L[j];
      subsets(N, L, i, subset, subsetLength + 1, j+1);
    }
  }
}

int main() {
  int N;
  scanf("%d", &N);

  int L[N];
  int subset[N];
  for (int i = 0 ; i < N ; i++) {
    scanf("%d", &L[i]);
  }

  for (int i = 0 ; i <= N ; i++) {
    subsets(N, L, i, subset, 0, 0);
  }

  return 0;
}