#pragma once
/*
 * ルンゲクッタ法
 * input: dim, x[], tmin, tmax, n, function
 */
void RungeKutta(int, double*, double, double, int, void(*)(double, double*, double*));
