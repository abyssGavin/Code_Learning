#include<iostream>
#include<cmath>
using namespace std;

int a[200];

void nqueen(int k, int num)
{
    int i;
    if(k == num)
    {
        for(k = 0; k < num; k++)
            cout << a[k] << " ";
        cout << endl;
        return;
    }
    for(i = 0; i < num; i++)
    {
        int j;
        for(j = 0; j < k; j++)
            if(a[j] == i || abs(a[j] - i) == abs(j - k))
                break;
        if(j == k)
        {
            a[k] = i;
            nqueen(k + 1, num);
        }
    }
}

int main()
{
    int num;
    cin >> num;
    nqueen(0, num);
    return 0;
}