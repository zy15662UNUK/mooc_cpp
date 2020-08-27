#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <assert.h>

using namespace std;

int main()
{
    enum wT{Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday}; // 声明类型.实际上也是整数，默认从0开始递增
    wT weekday;
    weekday = Monday;
    weekday = Tuesday;
    // weekday = 0; 只能定义一开始花括号内的值。不能给int
    cout << weekday << endl;
    // weekday = 0; weekday不能被赋值
    int a = Wednesday;
    cout << a << endl;
    return 0;
}