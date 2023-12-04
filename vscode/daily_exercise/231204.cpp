// #include<iostream>
// #include<algorithm>
// #include<ctime>
// using namespace std;

// int int_cmp(const void* e1, const void* e2) {
//     return (*(int*)e1 - *(int*)e2);
// }

// void swap(char* pa, char* pb, int size) {
//     for(int i = 0; i < size; i++, pa++, pb++) {
//         char ch = *pa;
//         *pa = *pb;
//         *pb = ch;
//     }
// }

// void bubblesort(void* begin, int len, int size, int(* cmp)(const void* e1, const void* e2)) {
//     int i, j;
//     for(int i = len; i > 0; i--) {
//         for(int j = 0; j < i; j++) {
//             if(cmp((char*)begin + j * size, (char*)begin + (j + 1) * size) > 0)
//                 swap((char*)begin + j * size, (char*)begin + (j + 1) * size, size);
//         }
//     }
// }

// int main() {
//     int arr[10];
//     srand(time(0));
//     for(int i = 0; i < 10; i++) arr[i] = rand() % 100;
//     bubblesort(arr, 10, 4, int_cmp);
//     for(int i = 0; i < 10; i++) {
//         cout << arr[i] << endl;
//     }
//     return 0;
// }






// #include<iostream>
// using namespace std;

// void test1(int* arr) {
//     cout << sizeof(arr) << endl;
// }


// void test2(int* &arr) {             //引用传数组，但引用的是普通的指针，大小还是指针的大小
//     cout << sizeof(arr) << endl;
// }

// template<size_t N>              //模板传数组，模板能传数组大小，不知道为什么
// void test3(int (&arr)[N]) {
//     cout << sizeof(arr) << endl;
// }

// void test4(int arr[10]) {       //输出为8，这也证明了这个10是没有作用的，如果要知道大小就用模板传参
//     cout << sizeof(arr) << endl;
// }

// int main() {
//     int arr[10] = {0, 10, 2, 3 ,4, 5, 6, 7, 8, 9};
//     int* p1 = &arr[0];
//     // arr++;  数组指针是常量！！！
//     int* p2 = arr;
//     cout << *p2 << endl;
//     cout << **(&arr + 1) << endl; // 跳过了一个数组，所以不是10， 而是1（1其实是不知道怎么来的，应该是跟编译器有关）
//     cout << sizeof(p2) << endl;
//     cout << sizeof(arr) << endl;
//     cout << sizeof(&arr) << endl;
//     cout << sizeof(*arr) << endl;
//     cout << sizeof(arr + 0) << endl;
//     cout << sizeof(*(arr + 0)) << endl;
//     cout << sizeof(*(&arr + 0)) << endl; // 记住解引用的东西一定是可修改的左值！！！
//     cout << sizeof(*(&arr + 10)) << endl; //保留数组指针的性质
//     cout << sizeof(*(&(p2 = p1 + 1))) << endl;
//     test1(arr);
//     test2(p1);
//     test3(arr);
//     int arr2[5][10];
//     cout << sizeof(arr2) << endl;
//     cout << sizeof(*arr2) << endl;
//     cout << sizeof(&arr2) << endl;
//     cout << sizeof(*(&arr2 + 0)) << endl; // 也是保留了数组指针的性质
//     cout << sizeof(arr2[2]) << endl;
//     test4(arr);


//     int a[5] = {1, 2, 3, 4, 5};
//     int* ptr = (int*)(&a + 1);
//     cout << *(a + 1) << endl << *(ptr - 1) << endl;
//     cout << a << endl << &a << endl;
//     cout << sizeof(a) << endl << sizeof(&a) << endl;
//     cout << *a << endl << *(&a) << endl;

//     int* i;
//     cout << i << endl << &i << endl;

//     int(*a2)[5] = &a;
//     cout << a2 << endl << &a2 << endl;
// }







// #include <iostream>
// using namespace std;

// struct edge {
//     int a;
//     char ch1;
//     int b;
//     char ch2;
//     int c;
// }*p = (struct edge*)0x10000000;

// int main() {
//     cout << sizeof(edge) << endl;
//     printf("%p\n", p + 0x1);
//     printf("%p\n", (unsigned long)p + 0x1); //在vs是可以运行的，在vscode不行
//     printf("%p\n", (unsigned int*)p + 0x1);
//     return 0;
// }








#include<iostream>
using namespace std;

int main() {
    int a[3][2] = {{0, 1}, {2, 3}, {4, 5}};
    int b[3][2] = {(0, 1), (2, 3), (4, 5)};  // 括号表达式！！
    int* p1;
    p1 = a[0];
    int* p2;
    p2 = b[0];
    printf("%d\n%d", p1[0], p2[0]);
}