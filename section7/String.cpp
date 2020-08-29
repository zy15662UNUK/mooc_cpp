#include "./include/String.h"

String::String(const char *str)       // 普通构造函数
{
    if (str == NULL)
    {
        m_data = new char[1];
        if (m_data != NULL)
        {
            *m_data = '\0';
        }
        else
        {
            exit(-1);
        }
    }
    else
    {
        int len = strlen(str);
        m_data = new char[len + 1];
        if (m_data != NULL) 
        {
            strcpy(m_data, str);
        }
        else {
            exit(-1);
        }
    }
    
}
String::String(const String &other)              // 拷贝构造函数
{
    char *str = other.m_data;
    int len = strlen(str);
    m_data = new char[len + 1];
    if (m_data != NULL)
    {
        strcpy(m_data, str);
    }
    else
    {
        exit(-1);
    }
}
String::String(String &&other)                   // 移动构造函数
{
    if (other.m_data!=NULL)
    {
        m_data = other.m_data;
        other.m_data = NULL;
    }
}
String::~String(void)                            // 析构函数
{
    if (m_data != NULL)
    {
      delete[] m_data;   
    }
}
String &String::operator=(const String &other)   // 赋值函数
{
    if(this == &other)
    {
        return *this;
    }
    // 释放原有内容
    if (m_data != NULL) delete[]m_data;
    // 重新分配资源并赋值
    char *str = other.m_data;
    int len = strlen(str);
    m_data = new char[len + 1];
    if (m_data != NULL)
    {
        strcpy(m_data, str);
    }
    else
    {
        exit(-1);
    }
    return *this;
}
String &String::operator=(String &&rhs) noexcept // 移动赋值运算符
{
    if (this != &rhs)
    {
        delete[] m_data;
        m_data = rhs.m_data;
        rhs.m_data = NULL;
    }
    return *this;
}
ostream &operator<<(ostream &os, const String &c) // cout 输出
{
    os << c.m_data << endl;
    return os;
}