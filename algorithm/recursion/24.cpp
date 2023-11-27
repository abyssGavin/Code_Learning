#include<iostream>
#include<cmath>
#include<stdbool.h>
using namespace std;

double m[5];

bool iszero(double a)
{
    return fabs(a) <= 0.1;
}

bool count24(double a[], int n)
{
    if(n == 1)
        if(iszero(fabs(24 - a[0]))) return true;
        else return false;
    double b[5] = {0};
    int i, j, k, m;
    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
        {
            m = 0;
            for(k = 0; k < n; k++)
                if(k != i && k != j)
                    b[m++] = a[k];
            b[m] = a[i] + a[j];
            if(count24(b, m + 1)) return true;
            b[m] = a[i] - a[j];
            if(count24(b, m + 1)) return true;
            b[m] = a[j] - a[i];
            if(count24(b, m + 1)) return true;
            b[m] = a[i] * a[j];
            if(count24(b, m + 1)) return true;
            if(!iszero(a[i]))
            {
                b[m] = a[j] / a[i];
                if(count24(b, m + 1)) return true;
            }
            if(!iszero(a[j]))
            {
                b[m] = a[i] / a[j];
                if(count24(b, m + 1)) return true;
            }
        }
    return false;
}

int main()
{
    for(int i = 0; i < 4; i++)
         cin >> m[i];
    if(count24(m, 4)) cout << "Yes";
    else cout << "No";
    return 0;
}