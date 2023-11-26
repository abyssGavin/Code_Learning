#include<iostream>
#include<random>

int a[10000];

void swap(int x, int y)
{
    if(x == y) return;
    a[x] ^= a[y];
    a[y] ^= a[x];
    a[x] ^= a[y];
}

void QuickSort(int start, int end)
{
    if(start == end) return;
    int i, j;
    for(i = j = start + 1; j <= end; j++)
        if(a[j] < a[start]) swap(j, i++);
    swap(start, i - 1);
    QuickSort(start, i - 1);
    QuickSort(i, end);
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 10000);
    int i, num;
    std::cin >> num;
    for(i = 0; i < 10000; i++)
        a[i] = dis(gen);
    QuickSort(0, num - 1);
    for(i = 0; i < num; i++)
        std::cout << a[i] << " ";
}