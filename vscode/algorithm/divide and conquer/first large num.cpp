#include<iostream>
#include<random>

int a[1000];

void swap(int x, int y)
{
    if(x != y)
    {
        a[x] ^= a[y];
        a[y] ^= a[x];
        a[x] ^= a[y];
    }
}

void fun(int start, int end, int num)
{
    if(start == end) return;
    int i, j;
    for(i = j = start + 1; j <= end; j++)
        if(a[j] < a[start]) swap(j, i++);
    swap(start, i - 1);
    if(i - 1 == num)
    {
        std::cout << a[num];
        return;
    }
    fun(start, i - 1, num);
    fun(i, end, num);
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 100000);
    int i, num;
    std::cin >> num;
    for(i = 0; i < 1000; i++)
        a[i] = dis(gen);
    fun(0, 1000 - 1, num);
    return 0;
}