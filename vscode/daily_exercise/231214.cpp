#include<iostream>
using namespace std;

int main() {
    int arr[4] = {1, 2, 3, 4};
    int (*p)[4] = &arr;
    cout << *(p[0] + 1);
}