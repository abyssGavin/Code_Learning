#include <iostream>
using namespace std;

struct edge {
    int a;
    char ch1;
    int b;
    char ch2;
    int c;
}*p = (struct edge*)0x10000000;

int main() {
    cout << sizeof(edge) << endl;
    printf("%p\n", p + 0x1);
    printf("%p\n", (unsigned long)p + 0x1);
    printf("%p\n", (unsigned int*)p + 0x1);
    return 0;
}
