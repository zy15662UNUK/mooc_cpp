#include "iostream"
#include <stdio.h>
#include <string.h>
using namespace std;
class String
{
private:
    char *m_data; // 用于保存字符串
public:
    String(const char *str = nullptr); // 普通构造函数
    String(const String &other);       // 拷贝构造函数
    String(String &&other);            // 移动构造函数
    ~String(void);                     // 析构函数
    String &operator=(const String &other); // 赋值函数
    String &operator=(String &&rhs) noexcept; // 移动赋值运算符

    friend ostream& operator << (ostream& os, const String &c); // cout 输出
};

