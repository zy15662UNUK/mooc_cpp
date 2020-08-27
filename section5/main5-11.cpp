#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int a = 0; // GVAR全局初始化区
int *p1;   // BSS全局未初始化区

int main()
{ // text代码区
    int b; // stack 栈区变量
    char s[] = "abc"; // stack 栈区变量
    int *p2;          // stack 栈区变量
    char *p3 = "123456"; // p3 在stack 栈区变量 "123456"在常量区
    static int c = 0;    // GVAR全局初始化区
    p1 = new int(10);    // heap 堆区变量
    p2 = new int(20);    // heap 堆区变量
    char *p4 = new char[7]; // heap 堆区变量
    strcpy(p4,"123456"); // text代码区

    if (p1 == NULL) {
        delete p1;
        p1 = NULL;
    }

    if (p2 == NULL) {
        delete p2;
        p2 = NULL;
    }

    if (p4 == NULL) {
        delete[] p4; // 数组的delete
        p4 = NULL;
    }
    return 0;               // text代码区
}