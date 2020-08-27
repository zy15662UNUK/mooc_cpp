#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <assert.h>


#include "./test.h"
using namespace std;

int main()
{
    /*
    * 函数重载。会根据名称和参数类型调用不同函数
    */ 
    int (* p)(int) = test; // 函数指针 p 参数是int 返回值是int
    int res = (*p)(1);
    // int res = test(1);
    cout << res << endl;
    res = test(2.0);
    cout << res << endl;
    res = test(1, 2.0);
    cout << res << endl;

    return 0;
}