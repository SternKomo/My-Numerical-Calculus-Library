#include <stdio.h>
#include "numerical-calculus.h"

double LVa=1, LVb=0.03, LVc=1, LVd=0.025;
void Lotka_Volerra(double t, double *x, double *y){
  y[0] = LVa*x[0] - LVb*x[0]*x[1];
  y[1] = -LVc*x[1] + LVd*x[0]*x[1];
}

double La=10, Lb=28, Lc=8/3;
void Lorenz(double t, double *x, double *y){
  y[0] = La*(x[1] - x[0]);
  y[1] = Lb*x[0] - x[1] -x[0]*x[2];
  y[2] = x[0]*x[1] - Lc*x[2];
}

int main(void){
  double tmin, tmax;
  int nmax;
  tmin = 0.0;
  tmax = 30;
  nmax = tmax*10;

  //  double x[2];
  //  x0[0] = 10; x0[1] = 7;
  //  RungeKutta(2, x0, tmin, tmax, nmax, Lotka_Volerra);

  double x0[3];
  x0[0] = 0; x0[1] = 2; x0[2] = 0;
  RungeKutta(3, x0, tmin, tmax, nmax, Lorenz);

  return 0;
}
