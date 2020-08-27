#include "test.h"


int test(int a)
{
    return a;
}
int test(double a)
{
    return int(a);
}
int test(int a, double b)
{
    return a + b;
}