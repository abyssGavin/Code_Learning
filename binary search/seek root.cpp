#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define Eps 1e-6

double f(double x)
{
    return x * x * x - 5 * x * x + 10 * x - 80;
}

int main()
{
    double y, root, x1 = 0, x2 = 100;
    root = (x1 + x2) / 2;
    y = f(root);
    while(fabs(y) > Eps)
    {
        if(y > 0) x2 = root;
        else x1 = root;
        root = (x1 + x2) / 2;
        y = f(root);
    }
cout << fixed << setprecision(16) << root;
    return 0;
}