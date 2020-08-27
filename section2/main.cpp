#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

// define constantsL 2 ways
#define PI 3.1415 // 不会出现在编译器期，编译出错很难排查
#define MA(x) x*(x-1)
const double pi = 3.15;

/*
整数常量
212 合法 十进制
215u 合法十进制 unsigned
0xFeeL 合法16进制
078 不合法。八进制里面不能有8
032UU 不合法 重复后缀
*/ 

using namespace std;

int main()
{
    // variable type
    printf("hello\n");
    char a[10] = "a";
    short int s = 97;
    int m = 97;
    long int n = 91;
    double k = 97.0;
    long double l = 97.0;
    wchar_t c = L'a'; // 长字符常量
    cout << PI << " " <<  pi << endl;
    int n1 = 1, n2 = 2;
    cout << MA(1 + n1 + n2) << endl;
    
}

