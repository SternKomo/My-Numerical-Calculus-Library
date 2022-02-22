#include <stdio.h>
#include <math.h>
#include "numerical-calculus.h"
int CG_Max_Iteration = 100;

double vec_prod(int n, double x[n], double y[n]){
  double ret = 0;
  for(int i=0; i<n; i++)
    ret += x[i]*y[i];
  return ret;
}
void matvec_prod(int n, double A[n][n], double b[n], double Ab[n]){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(j == 0){ Ab[i] = 0;}
      Ab[i] += A[i][j]*b[j];
    }
  }
}
void conjugate_gradient(int ndim, double a[ndim][ndim], double x[ndim], double b[ndim]){
  int kmax = CG_Max_Iteration;
  double eps = 1.0e-15;
  double alpha, beta;
  double bnorm, rnorm, rnorm_old;
  double r[ndim], p[ndim], ax[ndim], ap[ndim];
  // 初期化
  bnorm = sqrt(vec_prod(ndim, b, b));
  matvec_prod(ndim, a, x, ax);
  for(int i=0; i<ndim; i++){
    r[i] = b[i] - ax[i];
    p[i] = r[i];
  }
  rnorm = vec_prod(ndim, r, r);
  // Conjugate Gradient method
  for(int k=0; k<kmax; k++){
    //    for(int i=0; i<ndim; i++){ printf("%lf ", x[i]);} printf("\n");
    matvec_prod(ndim, a, p, ap);
    alpha = rnorm / vec_prod(ndim, p, ap);
    for(int i=0; i<ndim; i++){
      x[i] = x[i] + alpha*p[i];
      r[i] = r[i] - alpha*ap[i];
    }
    rnorm_old = rnorm;
    rnorm = vec_prod(ndim, r, r);
    if(rnorm <= eps*bnorm){
      return;
    }
    beta = rnorm / rnorm_old;
    for(int i=0; i<ndim; i++)
      p[i] = r[i] + beta*p[i];
  }
  printf("Not convergent\n");
}
/*
int main(void){
  int n = 3;
  double a[3][3], x[3], b[3];
  a[0][0]=1; a[0][1]=0; a[0][1]=0;
  a[1][0]=0; a[1][1]=2; a[1][2]=0;
  a[2][0]=0; a[2][1]=0; a[2][2]=1;
  x[0]=1; b[0]=4;
  x[1]=1; b[1]=5;
  x[2]=1; b[2]=6;

  conjugate_gradient(n, a, x, b);

  for(int i=0; i<n; i++)
    printf("%lf ", x[i]);
  printf("\n");

  return 0;
}
*/
