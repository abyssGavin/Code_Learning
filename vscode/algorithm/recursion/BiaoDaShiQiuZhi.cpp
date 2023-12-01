//表达式求值
#include<iostream>
#include<cctype>
using namespace std;

int expression();
int factor();
int term();

int main()
{
    cout << expression() << endl;
    return 0;
}

int expression()
{
    int result = term();
    while(true)
    {
        char ch = cin.peek();
        if(ch == '+' || ch == '-')
        {
            cin.get();
            int value = term();
            if(ch == '+') result += value;
            else result -= value;
        }
        else break;
    }
    return result;
}

int term()
{
    int result = factor();
    while(true)
    {
        char ch = cin.peek();
        if(ch == '*' || ch == '/')
        {
            cin.get();
            int value = factor();
            if(ch == '*') result *= value;
            else result /= value;
        }
        else break;
    }
    return result;
}

int factor()
{
    char ch = cin.peek();
    int result = 0;
    if(ch == '(')
    {
        cin.get();
        result = expression();
        cin.get();
    }
    else
    {
        while(isdigit(ch))
        {
            result = result * 10 + ch - '0';
            cin.get();
            ch = cin.peek();
        }
    }
    return result;
}