#include<iostream>
using namespace std;

int fun(int i, int j)
{
    if(j > i) return fun(i, i);
    if(i == 0) return 0;
    if(j == 0) return 1;
    return fun(i, j - 1) + fun(i - j, j);
}

int main()
{
    int i, j;
    cin >> i >> j;
    cout << fun(i, j);
    return 0;
}