#include<iostream>
using namespace std;
#define INF ((1 << 31) ^ -1)

// #pragma pack(8)

void swap (int &a, int &b) {
    if(a == b) return;
    a ^= b;
    b ^= a;
    a ^= b;
}

struct edge1 {
    char ch;
    double i;
    int a;
};

struct edge2 {
    char ch;
    edge1 e;
    char ch2;
};

void test1() {
    cout << sizeof(edge1) << endl;
}

int main() {
//     char a[4] = {0};
//     a[3] = 0x40, a[2] = 0xB0;
//     float* p = (float*) a;
//     cout << *p;

    // int a = 0x77665544;
    // char* p = (char*) &a;
    // if(*p > 0) cout << "小端";

    // int i = 10;
    // int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // for(i = 0; i < 11; i++) {
    //     cout << "WA!" << a[i];
    //     a[i] = 0;
    // }
    test1();
    cout << ((1 << 31) ^ -1) << endl << 0x7fffffff << endl;
    cout << (1 << 31) << endl << -0x7fffffff - 1 << endl;
    int a = 5, b = 8;
    swap(a, b);
    cout << a << " " << b;
}