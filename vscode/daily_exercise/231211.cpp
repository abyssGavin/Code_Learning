// #include<stdio.h>

// void swap(int* a, int* b) {
//     if(*a == *b) return;
//     *a ^= *b;
//     *b ^= *a;
//     *a ^= *b;
// }

// int main() {
//     int arr[10] = {0}, * p1,* p2,* minn,* begin,* end;
//     p1 = p2 = minn = begin = arr;
//     end = begin + 10;
//     while(p1 != end) scanf("%d", p1++);
//     for(p1 = begin; p1 != end; p1++) {
//         minn = p1;
//         for(p2 = p1 + 1; p2 != end; p2++) {
//             if(*p2 < *minn) minn = p2;
//         }
//         swap(p1, minn);
//     }
//     for(p1 = begin; p1 != end; p1++) {
//         printf("%d ", *p1);
//     }
// }

#include<iostream>
using namespace std;

int main() {
    int arr[2][2];
    cout << &arr + 1 << endl << &arr[0] + 1 << endl << &arr[0][0] + 1 << endl;
    cout << &arr  << endl << &arr[0]  << endl << &arr[0][0] << endl;

}