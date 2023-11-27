#include<iostream>
using namespace std;

int upstair(int num)
{
    if(num <= 0) return 0;
    if(num == 1) return 1;
    if(num == 2) return 2;
    return upstair(num - 1) + upstair(num - 2);
}

int main()
{
    int num;
    cin >> num;
    cout << upstair(num);
    return 0;
}