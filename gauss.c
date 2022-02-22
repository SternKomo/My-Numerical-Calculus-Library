#include <stdio.h>
#include <stdlib.h>
#include "numerical-calculus.h"

double gauss_prod_sum(int n, int k, double a[n][n], double x[n]){
  double ret = 0;
  for(int j=k+1; j<n; j++)
    ret += a[k][j] * x[j];
  return ret;
}
void gauss(int n, double a[n][n], double x[n], double b[n]){
  // 対角成分が0の時の処理
  for(int k=0; k<n-1; k++){
    if(a[k][k] == 0){
      for(int i=k+1; i<n; i++)
        if(a[i][k] != 0){
          double temp;
          for(int j=0; j<n; j++){
            temp = a[i][j]; a[i][j] = a[k][j]; a[k][j] = temp;
          }
          temp = b[i]; b[i] = b[k]; b[k] = temp;
        }
    }
    // 前進消去法 (Forward elimination)
    for(int i=k+1; i<n; i++){
      double m = a[i][k] / a[k][k];
      a[i][k] = 0;
      for(int j=k+1; j<n; j++)
        a[i][j] = a[i][j] - m*a[k][j];
      b[i] = b[i] - m*b[k];
    }
    /*
    for(int i=0; i<n; i++)
      printf("%lf %lf %lf %lf %lf\n", a[i][0], a[i][1], a[i][2], x[i], b[i]);
    printf("--------------------\n");
    */
  }
  // 後退代入法 (Backward substitution)
  for(int k=n-1; k>=0; k--)
    x[k] = (b[k] - gauss_prod_sum(n, k, a, x)) / a[k][k];
}

/*
int main(void){
  int n = 3;
  double a[n][n];
  double x[n];
  double b[n];

  a[0][0]=3; a[0][1]=6; a[0][2]=2;
  a[1][0]=1; a[1][1]=2; a[1][2]=8;
  a[2][0]=7; a[2][1]=3; a[2][2]=3;
  x[0] = 0; x[1] = 0; x[2] = 0;
  b[0]=32;
  b[1]=40;
  b[2]=35;

  a[0][0]=2; a[0][1]=3; a[0][2]=4;
  a[1][0]=1; a[1][1]=5; a[1][2]=3;
  a[2][0]=3; a[2][1]=0; a[2][2]=2;
  x[0] = 0; x[1] = 0; x[2] = 0;
  b[0]=2;
  b[1]=1;
  b[2]=4;

  for(int i=0; i<n; i++)
    printf("%lf %lf %lf %lf %lf\n", a[i][0], a[i][1], a[i][2], x[i], b[i]);
  printf("--------------------\n");
  
  gauss(n, a, x, b);

  for(int i=0; i<n; i++)
    printf("%lf %lf %lf %lf %lf\n", a[i][0], a[i][1], a[i][2], x[i], b[i]);

  return 0;
}
*/
