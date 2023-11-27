#include<iostream>
using namespace std;

int fun(int n, int m)
{
    long long sum = 1, i;
    for(i = 0; i < n; i++) {
        sum = sum * (m - i) / (i + 1);
        if(sum > 1e9) return sum;
    } 
    return sum;
}

int main()
{
    freopen("D:\\vscode\\r.txt", "r", stdin);
    long long l, mid, r, i, num, n, m, nn, mm;
    cin >> num;
    l = 1, r = 16;
    while(l < r) {
        mid = (l + r + 1) / 2;
        if(fun(mid / 2, mid) <= num) l = mid;
        else r = mid - 1; 
    }
    m = r / 2;
    for(i = 1; i <= m; i++)
    {
        l = i * 2 - 1, r = num;
        while(l <= r)
        {
            mid = l + (r - l) / 2;
            if((n = fun(i, mid)) == num) {
                nn = i, mm = mid;
                break;
            }
            if(n < num) l = mid + 1;
            else r = mid - 1;
        }
    }
    if(num == 1) cout << 1;
    else cout << (1 + mm) * mm / 2 + nn + 1;
    return 0;
}