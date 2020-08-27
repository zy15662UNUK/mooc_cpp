#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    /*
    * 左值可以取到地址。右值是临时变量不能取到地址的
    *
    */ 

    //    一般类型指针
    int i = 0;
    int * p = &i;

    // array of pointers
    int * a[4];
    // a pointer to an array
    int (* b)[4];

    //  const pointer VS pointer to const
    // const 修饰的部分。1. 看左侧最近部分 2. 如果左侧没有看右侧
    char str[] = "helloworld";
    char const *p1 = "helloworld"; //指针指向可变。但是指针指向的存储区域内容不可变 等效于 const char *
    char *const p2 = "helloworld"; // 指针指向不可变
    char const *const p3 = "helloworld"; // 指针指向不可变且指针指向的存储区域内容不可变
    p1 = str;
    // p2 = str;
    // p3 = str;

    /*
    pointer to pointer
    */
   int m = 123;
   int * m1 = &m;
   int * * m2 = &m1;
   cout << m << " " << m1 << " " << m2 << endl;

    /*
    几种原始指针
    */    
//    用指针间接访问之前一定要非常小心确保已经被初始化了并被恰当赋值
   int * t; // 这里a只是随便找了一个地方指着。很有可能是一块非法地址。程序会出错然后终止。最坏情况是无意识修改了一块可以修改的地址
//    * t = 12;
   
    // NULL 指针。表示特定指针没有指向任何东西. 对指针简介引用时候判断指针是否是null
    int * t1 = NULL;
    t1 = &m;
    if (t1 != NULL) {
        cout << t1 << endl;
    }
    t1 = NULL;
    /*
    野指针
    1. 指针变量没有初始化
    2. 已经释放不用的指针没有重置为null。例如delete和free后的
    3. 指针操作超越了变量范围
    */ 

    //    原始指针的基本运算

    /*
    *cp
    *cp + 1 修改cp地址上东西
    *(cp + 1)访问下一个地址
    */ 



   char ch = 'a';
   char * cp = &ch;
   char ** cpp = & cp;

   *cp = 'a';
   char ch2 = *cp;
   ch2 = *cp + 1; // 'a' + 1 = 'b'
   * (cp + 1) = 'b';
}
