#include<iostream>
#include<cstddef>
using namespace std;

// struct s1 {
//     char c1;
//     int i;
//     char c2;
// };

// struct s2 {
//     char c1;
//     char c2;
//     int i;
// };

// struct s3 {
//     double i;
//     char j;
//     double k;
// };

// struct s4 {
//     char ch;
//     s3 ss3;   //元素最大为8， 总共24
//     double i;
// };   //总内存为 8(1) + 24 + 8 = 40。最后是加8，而不是24，只看

// //应该一定程度的把成员放在一起

// void test1() {
//     cout << offsetof(s1,c1) << endl << offsetof(s1,i) << endl << offsetof(s1,c2) << endl;
//     s1 ss1 = {'a', 10, 'b'};
//     s1 *ps1 = &ss1;
//     s2 ss2 = {'a', 'b', 10};
//     s2 *ps2 = &ss2;
//     cout << sizeof(s1) << endl << sizeof(s2) << endl << sizeof(s3) << endl << sizeof(s4);
// }

// int main() {
//     test1();
// }



// #pragma pack(4)//修改默认偏移量

// struct s1{
//     int i;
//     double d;
//     char ch;
// };           //本来应该是24， 现在是16

// struct s3 {
//     char ch1;
//     double i;
//     char ch2;
// };

// #pragma pack()

// struct s2{
//     char ch1;
//     int i;
//     double d;
//     int j; 
//     int k;
//     char ch2;
// };

// struct s4{
//     int i;
//     double d;
// };

// int main() {
//     s2 ss2 = {49, 4, 4.5, 5, 6, 50};
//     s2* pss2 = &ss2;
//     cout << sizeof(s1) << endl << sizeof(s2) << endl << sizeof(s3);
// }


void test1() {
    
}

int main() {
    test1();
}