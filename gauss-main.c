#include <stdio.h>
#include "numerical-calculus.h"

int main(void){
  int n = 3;
  double A[n][n], x[n], b[n];
  /*
  A[0][0]=1; A[0][1]=-1; A[0][2]=2;
  A[1][0]=0; A[1][1]=1; A[1][2]=-2;
  A[2][0]=2; A[2][1]=-2; A[2][2]=5;
  b[0]=-8;
  b[1]=5;
  b[2]=-15;
  */

  A[0][0]=1; A[0][1]=-2; A[0][2]=-1;
  A[1][0]=1; A[1][1]=-1; A[1][2]=-1;
  A[2][0]=-2; A[2][1]=2; A[2][2]=2;
  b[0]=1;
  b[1]=4;
  b[2]=-7;

  gauss(n, A, x, b);

  for(int i=0; i<n; i++)
    printf("%lf\n", x[i]);

  return 0;
}
