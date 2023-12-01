#include<string>
#include<string.h>
#include<iostream>
#include<limits> // #incldue<limits.h>
using namespace std;

// 9.5换算成二进制1001.1
// 9.6 >>>>> 1001.10001......这样就会精度丢失
// float 四个字节 - 4byte - 32bite 就算是double也是无法精确保存
// float 符号位 1bite  指数位 8bite  有效数字 23bite
// double      1            11              52
// ！！！！在计算机内部默认保存都为1.-----，所以第一位个位数是不用存的
// ！！！！在指数位默认存的指数为原指数加127(2^7-1)(float)或者1023(2^10-1)(double)

// 所有的小数都能表示成 -1^s * m * 2^e  (二进制存储格式)

int main() {
    if(strlen("abc") - strlen("abcdef") > 0) {
        cout << ">";
    }
    else {
        cout << " <";
    }
    //输出为 ">" 因为strlen返回值是size_t类型，属于是 unsign_int



    cout << INT_MAX << endl;
    cout << ((1 << 31) ^ -1);

    int n = 9;
    float* f = (float*) &n;
    cout << n << endl;
    printf("%f\n%d\n", *f, f);//全是零的原因是指数位为1(0)-127,无限接近于零，所以输出0.000000，指数为0默认当成1
    *f = 9.0;
    printf("%f\n%d", *f, f);



    float ff = 5.5;
    float* fff = &ff;
    // 5.5  >>  101.1  >>  1.011*2^2  >>   s = 0, m = 1.011(!记住小数点前面的1不保存), e = 2
    // 0100 0000 1011 0000 0000 0000 0000 0000 
    // s--- ---- e--- ---- ---- ---- ---- ---m
    // 0       129(2+127)                  ???(0110000...)
    // 0x 40 b0 00 00
    //因为电脑是小端所以在内存中看到的应该是0x 00 00 b0 40
    cout << ff;

    {
        int i = -1;
        int* ii = &i;
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int *parr = arr;
        for(i = 0; i < 11; i++) // Debug：为了帮助检测内存越界错误，Debug模式可能在变量之间添加额外的空间或特殊的填充，这可以让调试工具更容易捕捉到内存越界或损坏。
        {                        //所以12不会越界， 13会越界，他会多空出一点地方，防止数组越界后导致程序崩溃
            arr[i] = 0;
            printf("!WA\n");
        }
        cout << "********" << endl;
    

    
        int a = 0x7f6f5f4f;
        int* pa = &a;
        cout << "****" << endl;
    }






















    system("pause");
    return 0;
}