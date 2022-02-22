#pragma once
/*
 * ガウスの消去法 Ax = b
 * input : n, A[n][n], x[n], b[n]
 * output: x に格納
 * 解を持たない場合は異常終了する ( rank(A) < rank(A b) なら異常終了)
 */
void gauss(int n, double a[n][n], double*, double*);
/*
 * ルンゲクッタ法
 * input: dim, x[dim], tmin, tmax, n, function
 */
void RungeKutta(int, double*, double, double, int, void(*)(double, double*, double*));
