#include<iostream>
using namespace std;

void hanno(int num, char src, char mid, char dest)
{
    if(num == 1)
    {
        cout << src << "->" << dest << endl;
        return;
    }
    hanno(num - 1, src, dest, mid);
    cout << src << "->" << dest << endl;
    hanno(num - 1, mid, src, dest);
}

int main()
{
    freopen("D:\\vscode project\\r.txt", "r", stdin);
    int num;
    cin >> num;
    hanno(num, 'A', 'B', 'C');
    return 0;
}