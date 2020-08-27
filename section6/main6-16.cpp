#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <assert.h>

using namespace std;

/*
内联函数
把函数逻辑的汇编语言直接复制到调用的位置。减少寻常调用时移动寄存器的时间
内联函数不能有太复杂逻辑。否则不会起作用
*/
inline int maxVal(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    int x = 10, y = 20;
    cout << maxVal(x, y) << endl;
    return 0;
}