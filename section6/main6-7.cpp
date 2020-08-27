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
    union Score
    {
        double ds;
        char level;
    };
    struct Student
    {
        char name[6];
        int age;
        Score s;
    };
    Student s1;
    s1.age = 18;
    s1.s.ds = 95.5;
    s1.s.level = 'A';
    strcpy(s1.name, "lili");
    cout << sizeof(Score) << endl; // union所占大小是里面属性所占大小最大值
    cout << sizeof(Student) << endl;
    
    /*
    * 32位cpu 分配结构体内存时候的规则
    * char 任何地址
    * short 偶数地址
    * int 4的整数倍地址
    * double 8的整数倍地址
    * 可以通过修改编译选项来使得结构体分配内存时候采取紧凑布局。也就是说有多大就用多少内存
    */ 
    
     
    return 0;
}