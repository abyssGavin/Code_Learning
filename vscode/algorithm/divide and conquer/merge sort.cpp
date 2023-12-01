#include<iostream>
#include<random>

int a[1000000], b[1000000];

void Merge(int start, int end, int mid)
{
    int i = start, j = mid + 1, k = 0;
    while(i <= mid && j <= end)
    {
        if(a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= end) b[k++] = a[j++];
    memcpy(a + start, b, k * sizeof(int));
}

void MergeSort(int start, int end)
{
    if(start == end) return;
    int mid = (start + end) / 2;
    MergeSort(start, mid);
    MergeSort(mid + 1, end);
    Merge(start, end, mid);
}

int main()
{   int i, num;
    std::cin >> num;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1,10000);
    
    for(i = 0; i < 1000000; i++)
        a[i] = dis(gen);
    MergeSort(0, num);
    for(i = 0; i < num; i++)
        std::cout << a[i] << " ";
    return 0;
}