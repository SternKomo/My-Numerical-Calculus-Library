#include <stdio.h>
#include <math.h>

double l_prod_sum(int n, double l[n][n], double y[n], int i){
  double ret = 0;
  for(int j=0; j<i; j++)
    ret += l[i][j]*y[j];
  return ret;
}
double u_prod_sum(int n, double u[n][n], double x[n], int i){
  double ret = 0;
  for(int j=i+1; j<n; j++){
    ret += u[i][j]*x[j];
    //    printf("%d %d: %lf*%lf = %lf ", i, j, u[i][j], x[j], ret);
  }
  //  printf(" => %lf\n", ret);
  return ret;
}

void lu_decomposition(int n, double a[n][n], double x[n], double b[n]){
  // 入れ替えた行を記憶する枢軸ベクトル p
  int p[n];
  for(int i=0; i<n; i++)
    p[i] = i;
  // PA = LU 
  double l[n][n], u[n][n], m[n][n];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      l[i][j] = u[i][j] = 0;
    l[i][i] = 1;
  }
  // 枢軸選択付きLU分解
  for(int k=0; k<n; k++){
    // 枢軸選択
    int max_id = k;
    double max=fabs(a[p[k]][k]);
    for(int i=k+1; i<n; i++){
      if( max < fabs(a[p[i]][k]) ){
        max = fabs(a[p[i]][k]);
        max_id = i;
      }
    }
    int temp = p[k]; p[k] = p[max_id]; p[max_id] = temp;
    // LU分解
    for(int i=k+1; i<n; i++){
      m[p[i]][k] = a[p[i]][k] / a[p[k]][k];
      for(int j=k+1; j<n; j++)
        a[p[i]][j] = a[p[i]][j] - m[p[i]][k]*a[p[k]][j];
    }
  }
  for(int i=1; i<n; i++)
    for(int j=0; j<i; j++)
      l[i][j] = m[p[i]][j];
  for(int i=0; i<n; i++)
    for(int j=i; j<n; j++)
      u[i][j] = a[p[i]][j];
  /*
  for(int i=0; i<n; i++) printf("%d ", p[i]); printf("\n");
  printf("----------------\n");
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      printf("%lf ", l[i][j]);
    printf("\n");
  }
  printf("----------------\n");
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++)
      printf("%lf ", u[i][j]);
    printf("\n");
  }
  printf("----------------\n");
  */
  double y[n]; for(int i=0; i<n; i++){ y[i] = 1;}
  for(int i=0; i<n; i++){
    double my = l_prod_sum(n, l, y, i);
    y[i] = b[p[i]] - my;
  }
  //  for(int i=0; i<n; i++) printf("%lf ", y[i]); printf("\n");
  for(int i=n-1; i>=0; i--){
    double ax = u_prod_sum(n, u, x, i);
    x[i] = (y[i] - ax) / u[i][i];
  }
}
/*
int main(void){
  int n=4;
  double a[n][n]; double x[n], b[n];

//  a[0][0]=2; a[0][1]=5; a[0][2]=7;
//  a[1][0]=4; a[1][1]=13;a[1][2]=20;
//  a[2][0]=8; a[2][1]=29;a[2][2]=50;
//  x[0]=1; b[0]=23;
//  x[1]=1; b[1]=58;
//  x[2]=1; b[2]=132;

  a[0][0]=8; a[0][1]=16;a[0][2]=24; a[0][3]=32;
  a[1][0]=2; a[1][1]=7; a[1][2]=12; a[1][3]=17;
  a[2][0]=6; a[2][1]=17;a[2][2]=32; a[2][3]=59;
  a[3][0]=7; a[3][1]=22;a[3][2]=46; a[3][3]=105;
  x[0]=1; b[0]=160;
  x[1]=1; b[1]=70;
  x[2]=1; b[2]=198;
  x[3]=1; b[3]=291;

  lu_decomposition(n, a, x, b);

  for(int i=0; i<n; i++)
    printf("%lf ", x[i]);
  printf("\n");

  return 0;
}
*/
