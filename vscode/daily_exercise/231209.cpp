#include<stdio.h>
double fac(int n);

double cmk(int m,int k);

int main()
{
  int m,k;
  scanf("%d %d", &m, &k);
  double cmkk = cmk(m,k);
  printf("%d",cmkk);
  //put your codes here.
  return 0;
}

double fac(int n)
{
  double result = 1.0;
  int i;
  for(i = 1;i <= n;i++)
    result*=i;
  return result;
}

double cmk(int m,int k)
{
  if (k > m)
  {
     return 0.0;
  }
  double numerator = fac(m);
  double denominator = fac(k) * fac(m - k);
  return numerator / denominator;
}