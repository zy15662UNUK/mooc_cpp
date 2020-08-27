#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>

using namespace std;
struct B;
struct  A
{
    shared_ptr<B> pb;
    // 这是在struct被销毁时候执行
    ~A()
    {
        cout << "~A()" << endl;
    }
};
struct B
{
    shared_ptr<A> pa;
    ~B()
    {
        cout << "~B()" << endl;
    }
};
struct BW;
struct AW
{
    shared_ptr<BW> pbw;
    ~AW()
    {
        cout << "~AW()" << endl;
    }
};
struct BW
{
    weak_ptr<AW> paw;
    ~BW()
    {
        cout << "~BW()" << endl;
    }
};

void test1()
{

    cout << "shared and shared pointer" << endl;
    shared_ptr<A> ta(new A());
    shared_ptr<B> tb(new B());
    cout << ta.use_count() << endl; //1
    cout << tb.use_count() << endl; //1
    ta->pb = tb;
    tb->pa = ta;
    cout << ta.use_count() << endl; //2
    cout << tb.use_count() << endl; //2
    // 这里有循环引用。所以即使在fun运行完了之后也不会销毁
}

void test2()
{
    cout << "shared and weak pointer" << endl;
    shared_ptr<AW> ta(new AW());
    shared_ptr<BW> tb(new BW());
    cout << ta.use_count() << endl; //1
    cout << tb.use_count() << endl; //1
    ta->pbw = tb;
    tb->paw = ta;
    cout << ta.use_count() << endl; //1
    cout << tb.use_count() << endl; //1
    // weak pointer不参与计数。所以fun结束后两者都会被销毁
}

int main()
{
    auto wa = shared_ptr<int>(new int(20));
    {
        auto wa2 = wa;
        cout << (wa2 == nullptr ? -1 : *wa2.get()) << endl; //20
        cout << (wa == nullptr ? -1 : *wa.get()) << endl; // 20
        cout << wa2.use_count() << endl; // 2 对象同时被wa和wa2指着
        cout << wa.use_count() << endl; // 2
    }
    cout << wa.use_count() << endl; // 1 wa2此时不存在了

    test1();
    test2();
}