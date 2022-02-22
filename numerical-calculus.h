#pragma once
/*
 * ガウスの消去法 Ax = b
 * input : n, A[n][n], x[n], b[n]
 * output: x に格納
 * 解を持たない場合は異常終了する ( rank(A) < rank(A b) なら異常終了)
 */
void gauss(int n, double a[n][n], double*, double*);
/*
 * 共役勾配法 Ax = b
 * input : ndim, A[ndim][ndim], x[ndim], b[ndim]
 * output: x に格納
 * CG_Max_Iteration 回繰り返して、収束しなければメッセージを出力
 */
void conjugate_gradient(int ndim, double a[ndim][ndim], double x[ndim], double b[ndim]);
/*
 * ルンゲクッタ法
 * input: dim, x[dim], tmin, tmax, n, function
 */
void RungeKutta(int, double*, double, double, int, void(*)(double, double*, double*));
