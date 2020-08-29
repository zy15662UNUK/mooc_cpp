#include <iostream>

using namespace std;
class Complex
{
private:
    /* data */
public:
    Complex();
    Complex(double r, double i); // 构造函数
    Complex(const Complex & x); // 拷贝构造
    virtual ~Complex(); // 析构函数 销毁时候执行
    double getReal() const; // const 修饰函数real。表示里面变量不可改
    void setReal(double d);
    double getImage() const;
    void setImage(double d);

//  运算符重载
    Complex operator+ (const Complex& x);
    Complex& operator=(const Complex &x);
    // 前置++
    Complex& operator++ ();
    // 后置++
    Complex operator++(int);
    Complex &operator+=(const Complex &x);
    bool operator==(const Complex &x);
    bool operator!=(const Complex &x);
    // protected: // 只有自己和继承者可以用

    // 给ostream用不算成员变量。只能用friend
    // cout
    friend ostream& operator<<(ostream& os, const Complex &x);
    // cin
    friend istream &operator>>(istream &is,  Complex &x);

private:
    double _real;
    double _image;
};

