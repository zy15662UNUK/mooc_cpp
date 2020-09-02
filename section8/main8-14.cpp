#include "iostream"
#include "string"
#include <cstring>
using namespace std;
// 泛型编程.不同于面向对象的动态期多态，泛型编程时一种静态期多态。通过编译器生成最直接代码
template <class T>
T max1(T a, T b)
{
    return a > b ? a : b;
}
// 特化
template<>
char * max1(char *a, char *b)
{
    return strcmp(a, b) > 0 ? a:b;
}

// input diff type, but output is a certain type
template<class T1, class T2>
int max1(T1 a, T2 b)
{
    return static_cast<int>(a > b? a:b);
}

// 1 + 2 + 3 +... + 100. 利用泛型编译期推理过程,让编译器在编译过程中完成计算
template<int n>
struct Sum
{
    enum value {N = Sum<n - 1>::N + n};
};
template <>
struct Sum<1>
{
    enum value
    {
       N = 1
    };
};

// 普通编程
// int max(int a, int b)
// {
//     return a > b? a: b;
// }



int main()
{
    int a = 1, b = 2;
    cout << max1(a, b) << endl;
    cout << max1(1.5, 2.5) << endl;
    cout << max1('a', 'b') << endl;
    cout << max1("hello", "world") << endl;

    char * s1 = "hello";
    char * s2 = "world";
    cout << max1(s1, s2) << endl;
    cout << max1(10, 2.66) << endl;

    cout << Sum<100>::N << endl;
    return 0;
}
