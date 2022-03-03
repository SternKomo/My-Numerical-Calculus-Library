#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numerical-calculus.h"

void RungeKutta( int dim, double *x, double tmin, double tmax, int n,
                 void (*function)(double, double*, double*) ){
  double t=tmin, t_old, th2;
  double h = (tmax - tmin) / n;
  double h2 = h / 2, h6 = h / 6;

  double *x_old = (double*)malloc(n * sizeof(double));
  double xk1[n], xk2[n], xk3[n];

  double *k1 = (double*)malloc(n * sizeof(double));
  double *k2 = (double*)malloc(n * sizeof(double));
  double *k3 = (double*)malloc(n * sizeof(double));
  double *k4 = (double*)malloc(n * sizeof(double));

  printf("# Runge-Kutta method\n");
  printf("# t, x1, x2\n");
  for(int k=0; k<n; k++){
    t_old = t;
    for(int i=0; i<dim; i++){
      x_old[i] = x[i];
    }
    t += h;
    th2 = t_old + h2;

    function(t_old, x, k1);

    for(int i=0; i<dim; i++){
      xk1[i] = x_old[i] + h2*k1[i];
    }
    function(th2, xk1, k2);

    for(int i=0; i<dim; i++){
      xk2[i] = x_old[i] + h2*k2[i];
    }
    function(th2, xk2, k3);

    for(int i=0; i<dim; i++){
      xk3[i] = x_old[i] + h*k3[i];
    }
    function(t, xk3, k4);

    for(int i=0; i<dim; i++){
      x[i] = x_old[i] + h6*(k1[i] + 2*k2[i] + 2*k3[i] + k4[i]);
    }
    printf("%lf", t);
    for(int i=0; i<dim; i++)
      printf(", %lf", x[i]);
    printf("\n");
  }
  free(k1); free(k2); free(k3); free(k4);
}

/*
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
*/
