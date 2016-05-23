#include <stdio.h>

void push(int **A);
const int n = 4;
int main(void){
  int A[n][3];
  int i,j;

  int *B[n];
  for (i=0;i<n;i++) B[i] = A[i];
  push(B);

  for (i=0;i<n;i++){
    for (j=0;j<3;j++) printf("%d ",A[i][j]);
    puts("");
  }
  return 0;
}

void push(int **A){
  int i,j,k;
  for (i=0,k=0;i<n;i++){
    for (j=0;j<3;j++,k++) A[i][j] = k;
  }
}
