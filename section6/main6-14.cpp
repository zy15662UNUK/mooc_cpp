#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <assert.h>

#include "test6-14.h"
using namespace std;

int main()
{

    int res = test(1);
    cout << "first test " << res << endl;
    res = James::test(1);
    cout << "first test with namespace James " << res << endl;
    res = test(2.0);
    cout << "second test " << res << endl;
    res = test(1, 2.0);
    cout << "third test " << res << endl;

    return 0;
}