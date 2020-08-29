#include "./include/Complex.h"
#include "iostream"
#include <fstream>
#include "limits"
using namespace std;
static const int BUFF_LEN = 2048;
bool copyFile(const string & src, const string & dst)
{
    // open source file and destinaion file
    // open source file with binary read
    ifstream in(src.c_str(), std::ios::in | std::ios::binary);
    // open destination file with binary write
    ofstream out(dst.c_str(), std::ios::out | std::ios::binary | std::ios::trunc); // clear dest if exist

    // if fail to open, return false
    if (!in || !out) {
        return false;
    }
    // read from source write to dest
    // decide if to stop read and write by EOF
    char tmp[BUFF_LEN];
    while (!in.eof())
    {
        in.read(tmp, BUFF_LEN);
        streamsize count = in.gcount(); // get how many byte read from last time
        out.write(tmp, count);
    }
    // close souce and destination file
    in.close();
    out.close();
    return true;

}


int main()
{
    int a;
    int index = 0;
    while (cin >> a)
    {
        cout << "the numbers are " << a << endl; 
        index ++;
        if (index == 5)
        {
            break;
        }
    }
    // 
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // 情空缓冲区最大范围
    char c;
    cin >> c;
    cout << "char is " << c << endl;


    // file operation
    index = 0;
    fstream fout;
    fout.open("textBuffer.txt", ios::app); // ios app 追加方式。不存在则创建
    if(fout.fail())
    {
        cout << "Open file failed" << endl;
    }
    while (cin >> a)
    {
        fout << "the numbers are " << a << endl;
        index++;
        if (index == 5)
        {
            break;
        }
    }
    
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // 情空缓冲区最大范围
    cin >> c;
    fout << "char is " << c << endl;
    fout.close();


    // binary files
    cout << copyFile("Blue Daube.mp3", "Blue Daube2.mp3") << endl;
    return 0;

}