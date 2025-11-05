#include <stdio.h>

int valid (int X, int Y){
  if (Y < X){
    return 0;
  }
  else if (X == 0){
    return 1;
  }
  else{
    return valid(X-1, Y) + valid(X, Y-1);
  }
}

int main(){
  int N, x;
  scanf("%d", &N);

  if (N == 0) {
    x = 0;
  }
  else {
    x = valid(N, N);
  }
  printf("%d\n", x);
  return 0;
}