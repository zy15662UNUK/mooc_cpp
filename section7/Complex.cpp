#include "./include/Complex.h"


// 实现时候要加前缀.表示是class内部函数
Complex::Complex(double r, double i)
{
    _real = r;
    _image = i;
    cout << "Complex::Complex(double r, double i)" << endl;
}

Complex::Complex()
{
    _real = 0.0;
    _image = 0.0;
    cout << "Complex::Complex()" << endl;
}

Complex::Complex(const Complex & x)
{
    _real = x._real;
    _image = x._image;
    cout << "Complex::Complex(Complex & x)" << endl;
}

Complex::~Complex()
{
    cout << "Complex::~Complex()" << endl;
}

double Complex::getReal() const
{
    return _real;
}

void Complex::setReal(double d)
{
    _real = d;
}

double Complex::getImage() const
{
    return _image;
}

void Complex::setImage(double d)
{
    _image = d;
}

Complex Complex::operator+(const Complex &x)
{
    Complex ans;
    cout << "SSS" << endl;
    ans._real = _real + x._real;
    ans._image = _image + x._image;
    return ans;
}

Complex& Complex::operator=(const Complex &x) // 注意和下面取地址操作区别
{
    // 地址不相等才需要赋值
    if (this != &x) {
        _real = x.getReal();
        _image = x.getImage();
    }
// 按理说这里默认是复制一个新对象，然后因为拷贝构造的原因，应该是触发一个拷贝构造函数。但是不知为何这里没有触发，仿佛没有拷贝
    return *this; // this point to the object.need dereference to get the object
}

// 前置++
Complex& Complex::operator++()
{
    _real ++;
    _image ++;
    return *this;
}
// 后置++
Complex Complex::operator++(int)
{
    Complex tmp(*this);
    _real ++;
    _image ++;
    // for ++ at back return a copy and update itself
    return tmp;

}

// 没有Complex::限制符。因为不是成员变量

ostream &operator<<(ostream &os, const Complex &x)
{
    os << "real val is: " << x.getReal() << " image val is " << x.getImage();
    return os;
}

istream &operator>>(istream &is, Complex &x)
{
    is >> x._real >> x._image;
    return is;
}