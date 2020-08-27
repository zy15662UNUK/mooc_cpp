#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <assert.h>

using namespace std;
void swap (int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    // 引用可以认为是指定变量的别名，使用时候可以认为是变量本身
    int x =1 , x2 = 3;
    int & rx = x;
    rx = 2;
    cout << x << endl; // 2
    cout << rx << endl; // 2
    rx = x2;
    cout << x << endl; // 3
    cout << rx << endl; // 3
    int a = 3, b = 4;
    swap(a, b);
    assert(a == 4 && b == 3);
    return 0;
}