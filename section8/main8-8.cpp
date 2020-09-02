
#include "iostream"
using namespace std;

void test(){}

class Base
{
private:
    int _i;
public:
    Base():_i(1){}
    virtual void T(){cout << "base:T" << endl;}

};

class Derived:public Base
{
private:
    int _j;
public:
    Derived():_j(0){}
    virtual void T() { cout << "derived:T" << endl; }
};


int main()
{

    // c++ const转换, const_cast 方便编译器查找
    const int a = 10;
    int * pA = const_cast<int *>(&a);
    *pA = 100;
    cout << a << endl;
    cout << *pA << endl;
    cout << &a << " " << pA << endl;

    // c++ reinterpret_cast.很危险，重新解释类型。既不检查指针指向内容也不检查指针本身但要求转换前后所占用内存大小一致
    typedef void (*FunctPtr)();
    FunctPtr funcPtr;
    // funcPtr = &test
    funcPtr = reinterpret_cast<FunctPtr>(&test);

    /*
    static_cast
    用于基本类型转换，有继承关系类对象和类指针之间转换，由程序员来确保转换是安全的
    不会产生动态转换的类型安全检查的开销


    dynamic cast
    只能用于转换含有虚函数的类。必须用在多态体系中，用于类层次间的向上和向下转化。向下转化时候如果是非法的对于指针返回null
    */ 
    // static cast
    int i = 6;
    double d = static_cast<int>(i);
    double d2 = 5.6;
    int i2 = static_cast<int>(d2);

    // static cast and dynamic cast
    Base cb;
    Derived cd;
    Base* pcb;
    Derived* pcd;

    // 子类->父类
    pcb = static_cast<Base*>(&cd);
    pcb = dynamic_cast<Base*>(&cd);
    if (pcb == NULL)
    {
        cout << "unsafe dynamic cast from dereived to base" << endl;
    }

    // 父类->子类
    pcd = static_cast<Derived *>(&cb);
    pcd = dynamic_cast<Derived *>(&cb);
    if (pcb == NULL)
    {
        cout << "unsafe dynamic cast from dereived to base" << endl;
    }
    return 0;
}