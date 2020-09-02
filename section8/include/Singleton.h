// 单例模式
#include "iostream"
using namespace std;
class Singleton
{
public:
    const static Singleton* getInstance();
    static void doingSomeThing();
// 构造函数和析构函数私有化。防止外部访问
private:
    Singleton(/* args */);
    ~Singleton();
    // 全局区.随着程序产生而产生。使用静态变量来帮助解决资源的释放
    static Singleton * This;
};

