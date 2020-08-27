#include "./include/Complex.h"
#include "iostream"
using namespace std;
int main()
{
    Complex a(3.0, 2.0);
    Complex b(2.0, 3.0);
    cout << a.getImage() << endl;
    cout << a.getReal() << endl;
    // Complex c = a + b; //这是定义
    Complex c;
    c = a + b; // 这是赋值
    cout << c.getImage() << endl;
    cout << c.getReal() << endl;

    Complex d(c);

    Complex e;
    e = d ++;
    cout << d << endl;
    cout << e << endl;

    e =  ++d;
    cout << d << endl;
    cout << e << endl;


    cin >> e;
    cout << e << endl;
    return 0;
}
