// 逆波兰表达式
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

double exp()
{
    char a[20];
    cin >> a;
    switch(a[0])
    {
        case '+': return exp() + exp();
        case '-': return exp() - exp();
        case '*': return exp() * exp();
        case '/': return exp() / exp();
        default: return atof(a);
        break;
    }
}

int main()
{
    cout << exp();
    return 0;
}