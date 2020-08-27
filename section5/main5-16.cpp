#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>

using namespace std;

int main()
{                         
    {// auto ptr 作用范围仅仅在这个大括号内。出了大括号就被销毁
    // auto ptr对象销毁时候所管理对象也会被销毁
        auto_ptr<int> pl(new int(10));
        cout << *pl << endl;

        auto_ptr<string> langs[5] = {
            auto_ptr<string>(new string("c")),
            auto_ptr<string>(new string("java")),
            auto_ptr<string>(new string("c++")),
            auto_ptr<string>(new string("python")),
            auto_ptr<string>(new string("rust")),
        };

        for (int i = 0; i < 5; i ++) {
            cout << " lang is" << *langs[i] << endl;
        }
        auto_ptr<string> pc;// 所有权转移
        pc = langs[2]; // langs[2]被pc引用之后。本身被delete。所以说下次再访问langs[2]会segment fault
        for (int i = 0; i < 5; i++)
        {
            cout << " lang is" << *langs[i] << endl;
        }
    }
    return 0;
}