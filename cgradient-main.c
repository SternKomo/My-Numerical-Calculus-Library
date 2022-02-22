#include <stdio.h>
#include "numerical-calculus.h"

int main(void){
  int n=5;
  double a[n][n], x[n], b[n];
  a[0][0]=10; a[0][1]=  3; a[0][2]= 1; a[0][3]= 2; a[0][4]= 4;
  a[1][0]= 3; a[1][1]= 18; a[1][2]= 2; a[1][3]=-1; a[1][4]= 5;
  a[2][0]= 1; a[2][1]=  2; a[2][2]=12; a[2][3]= 1; a[2][4]= 1;
  a[3][0]= 2; a[3][1]= -1; a[3][2]= 1; a[3][3]= 9; a[3][4]=-4;
  a[4][0]= 4; a[4][1]=  5; a[4][2]= 1; a[4][3]=-4; a[4][4]=14;
  x[0]=1; b[0]= 19;
  x[1]=1; b[1]= 2;
  x[2]=1; b[2]= 34;
  x[3]=1; b[3]=-49;
  x[4]=1; b[4]= 83;

  conjugate_gradient(n, a, x, b);
  //  gauss(n, a, x, b);

  for(int i=0; i<n; i++)
    printf("%lf ", x[i]);
  printf("\n");

  return 0;
}
