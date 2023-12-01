// #include<iostream>
// using namespace std;

// bool fun(int a, int b) {
//   for(int c = 1; c != 0; ) {
//     c = a % b;
//     a = b;
//     b = c;
//   }
//   if(a == 1) return 1;
//   return 0;
// }

// int main() {
//   int i, j, num, res = 0;
//   cin >> num;
//   for(i = 1; i < num; i++) {
//     if(fun(num, i)) res++;
//   }
//   cout << res;
// }



#include<iostream>
#include<cassert>
#include<cerrno>
#include<cstring>
using namespace std;

void test1() {
  int a = 5;
  assert(a == 5);
  cout << endl << "***" << endl;
  // assert(a == 0);                   
  // cout << "***" << endl;
  
}

void test2() {
  int a;
  // cin >> a;
  // cout << strerror(errno) << endl;
  FILE* fp = fopen("tesr.txt", "r");
  cout << strerror(errno) << endl;
}

void test3() {
  int i;
  char arr[20];
  cout << "***" << endl;
  for(i = 0; i < 10; i++) {
    arr[i] = i + 48;
  }
  arr[19] = '\0';
  memcpy(arr + 3, arr, 6); //理论上不可行，但是估计是有编译器的优化
  printf("%s\n", arr);
  cout << "***" << endl;
}


void test4() {
  int a = 1;
  char* p = (char*)&a;
  if(*p == 1) cout << "小端";
  else cout << "大端";
}

int main() {
  test1();
  test2();
  test3();
  test4();
}