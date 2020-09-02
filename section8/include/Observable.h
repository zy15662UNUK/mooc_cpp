#include <list>
#include "string"
#include "./Observer.h"
using namespace std;
class Observer;

class Observable
{
private:
    list<Observer *>_obs;
    // 遍历所有的注册的observer然后把参数传递给他们的update方法
    void notify(void *pArg);
    bool _bChange;

public:
    Observable();
    virtual ~Observable();
    // 注册观察者
    void attach(Observer * pOb);
    // 反注册观察者
    void detach(Observer * pOb);
    void detachAll();
    int getObserverCount() const;

    virtual void getSomeNews(string str);

protected: // 仅仅只有继承类可见。外部其他类不可见
    //有变化。需要把传入的信息传进所有的注册的observable里面
    void setChange(string strNews);
};


