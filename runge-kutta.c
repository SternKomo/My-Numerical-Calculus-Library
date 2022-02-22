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
