#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int dp[10005], num[10005];

int main()
{
    int i, j = 0, n, k = 0;
    int* p;
    for (n = 0; cin >> num[n]; n++);
    for (i = 0; i < n; i++)
    {
        p = upper_bound(dp, dp + j, num[i], greater<int>());
        if (p == dp + j) j++;
        *p = num[i];
    }
    memset(dp, 0, sizeof(dp));
    for (i = 0; i < n; i++)
    {
        p = lower_bound(dp, dp + k, num[i]);
        if (p == dp + k) k++;
        *p = num[i];
    }
    cout << j << endl << k;
    return 0;
}