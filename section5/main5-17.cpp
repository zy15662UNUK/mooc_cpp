#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>

using namespace std;

int main()
{
    {// 只在这个区间作用
        auto i = unique_ptr<int>(new int(10));
    }
    auto w = make_unique<int>(10);
    cout << *(w.get()) << endl;
    // auto w2 = w; 只能移动。不能直接赋值
    auto w2 = move(w);
    // move 之后原来指针失去所有权被销毁
    cout << (w == nullptr?-1:*w.get()) << endl;
    cout << (w2 == nullptr ? -1 : *w2.get()) << endl;
    return 0;
}