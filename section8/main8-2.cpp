#include "./include/Singleton.h"
#include "./include/Observer.h"
#include "./include/Observable.h"
#include "iostream"
using namespace std;

class User1:public Observer
{
public:
    virtual void update(void *pArg)
    {
        cout << "User1 update " <<(char *)pArg << endl;
    }
};
class User2 : public Observer
{
public:
    virtual void update(void *pArg)
    {
        cout << "User2 update " << (char *)pArg << endl;
    }
};
class News:public Observable
{
private:
    /* data */
public:
    void getSomeNews(string str)
    {
        setChange("News " + str);
    }
};


int main()
{
    // singleton
    Singleton::getInstance() -> doingSomeThing();

    // observer
    User1 u1;
    User2 u2;
    News n1;
    n1.attach(&u1);
    n1.attach(&u2);
    n1.getSomeNews("T1");
    cout << n1.getObserverCount() << endl;
    n1.detach(&u2);
    n1.getSomeNews("T2");
    cout << n1.getObserverCount() << endl;
    n1.detachAll();
    n1.getSomeNews("T3");
    cout << n1.getObserverCount() << endl;


    return 0;
}
