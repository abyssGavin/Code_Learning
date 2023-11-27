#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> boat(455);
bool check[455];
int value[455];

int fun(int n) {
    if(check[n]) return 0;
    for(const auto v : value) {
        if(v == true) {
            int jud = 1;
            for(const auto &b : boat[n]) {
                if(b == v) {
                    jud = 0;
                    break;
                }
            }
            if(jud) return 0;
        }
    }
    check[n] = true;
    int sum = 0;
    for(auto &i : boat[n]) {
        sum = max(sum, value[n] + fun(i));
    }
    check[n] = false;
    return sum;
}

int main()
{
    int v, n1, n2, i, j, num, maxx = 0;
    cin >> n1 >> n2;
    for (i = 1; i <= n1; i++) cin >> value[i];
    for (i = 1; i <= n2; i++) {
        cin >> num >> j;
        boat[num].push_back(j);
        boat[j].push_back(num);
    }
    for (i = 1; i <= n1; i++) {
        maxx = max(maxx, fun(i));
    }
    cout << maxx;
}