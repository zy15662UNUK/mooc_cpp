#include "iostream"
using namespace std;
void func(int* a[])
{
    cout << "func1" << endl;
    cout << a << endl;
    cout << *a[0] << endl;
}
void func2(int ** a)
{
    cout << "func2" << endl;
    cout << a << endl;
    cout << *a[0] << endl;
}
int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int* arr[] = {&a, &b, &c};
    cout << &arr << endl;
    func(arr);
    func2(arr);

    return 0;
}
