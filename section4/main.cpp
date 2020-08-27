#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4,5 ,6 , 7, 8, 9,10};
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i ++) {
        cout << arr[i] << endl;
    }
    // use pointer to access array
    int * ptr = arr;
    cout << "use pointer to access array " <<  * (ptr + 2) << endl;

    // 2-d array
    int a[2][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        cout << "row number: " << i << endl; 
        for (int j = 0; j < sizeof(a[0]) / sizeof(a[0][0]); j ++) {
            cout << a[i][j] << endl;
        }
    }

    /*
    vector.size()
    vector.capacity()
    vector.push_back()
    vector.pop_back()
    vector.erase()
    vector.insert()
    */
    cout << "vector" << endl;
    vector<int> vec = {1, 2, 3, 4};
    cout << "capacity" << vec.capacity() << endl;
    vec.push_back(5);
    for (auto n : vec) {
        cout << n << endl;
    }
    vec.insert(--vec.end(), 6);
    for (int i = 0; i < vec.size(); i ++)
    {
        cout << "capacity" << vec.capacity() << " " << vec[i] << endl;
    }
    vec.pop_back();
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "1    " << vec.capacity() << " " << vec[i] << endl;
    }
    vec.erase(vec.end() - 1); // vec.end()是指针指在最后一个数地址尾部。-1是移到最后一个数地址开头。然后移走最后一个元素

    for (int i = 0; i < vec.size(); i++)
    {
        cout << "2    " << vec.capacity() << " " << vec[i] << endl;
    }

    // string
    char * pStrHelloWorld = "helloworld"; // 指针指向的每一个字符位置不可以被改变, 因为是指向常量区域
    char helloworld[] = { "helloworld" }; // 每一个字符位置可以改. 但是变量不能被重新赋值

    char *tmp = helloworld;
    tmp[1] ++;
    cout << "tmp " << tmp << endl;
    helloworld[1]--;
    cout << "tmp " << tmp << endl;
    cout << pStrHelloWorld << " " << helloworld << endl;
    cout << "len is " << strlen(helloworld) << " size is " << sizeof(helloworld) << endl;
    cout << "cmp " << strcmp("apple", "alice") << endl;
    char str1[16];
    char str2[] = "alice";
    strcpy(str1, str2);
    strncpy(str1, str2, 2);
    cout << "concat " << strcat(str1, str2) << endl;
}
