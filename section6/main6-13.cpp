#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <assert.h>

using namespace std;

int maxVal(int x, int y)
{
    return x > y ? x : y;
}
int minVal(int x, int y) 
{
    return x < y ? x : y;
}
int add(int x, int y)
{
    return x + y;
}
int processNum(int x, int y, int (*p)(int a, int b))
{
    // p 是回调函数
   cout << p(x, y) << endl;
   return 0;
}
int main()
{

    /*
int (*p)(int) = test;// 函数指针 p 参数是int 返回值是int. 这是一个指针指向一个函数入口地址
e.g.
bool processNum(int i, int j, int(*p)(int a, int b));


int * p(int); // 这是一个函数。返回值是一个指针
e.g.
    char * strcpy(char * dest, const char * src);
*/
    int x = 10, y = 20;
    cout << processNum(x, y, maxVal) << endl;
    cout << processNum(x, y, minVal) << endl;
    cout << processNum(x, y, add) << endl;

    return 0;
}