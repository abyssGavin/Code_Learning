#include<iostream>
using namespace std;

void test1() {
    cout << "WA!" << endl;
}

int test2(const char* str) {
    cout << str << endl;
    return 0;
}

typedef unsigned int uint;
typedef void(* pf_t)(int);

int ADD(int x, int y) {
    return x + y;
}

void cal(int (*pf)(int, int)) {
    cout << pf(10, 20) << endl;
}

int main() {
    void (*pf1)() = test1;
    (*pf1)();
    char str[] = "abcdef";
    int (*pf2)(const char* str) = test2;
    cout << pf2(str) << endl;
    void (*a)();
    a = (void(*)())test1;
    (*(void(*)())a)();


    // (*(void(*)())0)();
    //将0强制转换成函数指针再调用函数

    void(*signal(int, void(*)(int)))(int); // signal是函数名返回值是函数指针
    pf_t singnal(int, pf_t); // signal是函数名返回值是函数指针
    //这两个是等价的

    cal(ADD);

    int (*pt3[10])(int, int); // 函数指针数组
    pt3[0] = ADD;
    cout << pt3[0](20, 20) << endl;

}