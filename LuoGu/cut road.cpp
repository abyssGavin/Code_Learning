#include<iostream>
#include<iomanip>
using namespace std;
#define INF (1 << 24)
#define fo(l, r, i, k) for(int i = l; i < r; i += k)

bool jud(int mid, int n, int m)
{
    int sum;
    fo(0, n, i, 1) sum += n / mid;
    return sum >= n;
}

int main()
{
    double* num = new double[10005];
    int mid, l, r, m, n, len;
    cin >> n >> m;
    fo(0, n, i, 1) cin >> num[i], num[i] *= 100;
    l = 0, r = INF;
    while(l <= r){
        mid = (l + r) >> 2;
        if(jud(mid, n, m)) l = mid;
        else r =mid;
    }
    cout << fixed << setprecision(2) << mid / 100.0;
    delete[] num;
    return 0;
}