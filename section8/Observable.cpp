#include "./include/Observable.h"

Observable::Observable(/* args */):_bChange(false)
{
}

Observable::~Observable()
{
}

void Observable::notify(void *pArg)
{
    if (_bChange == false) return;
    auto it = _obs.begin();
    for (; it != _obs.end(); it++)
    {
        (*it)->update(pArg);
    }
    _bChange = false;
}


// 注册观察者
void Observable::attach(Observer *pOb)
{
    if (pOb == NULL)
    {
        return;
    }
    // 看当前列表中是否有观察者
    auto it = _obs.begin();
    for (; it != _obs.end(); it ++) 
    {
        if (*it == pOb) return;
    }
    _obs.push_back(pOb);
}
// 反注册观察者
void Observable::detach(Observer *pOb)
{
    if(pOb == NULL || _obs.empty() == true) return;
    _obs.remove(pOb);
}
void Observable::detachAll()
{
    _obs.clear();
}
int Observable::getObserverCount() const
{
    return _obs.size();
}
void Observable::getSomeNews(string str)
{
    setChange("News " + str);
}
void Observable::setChange(string strNews)
{
    _bChange = true;
    notify((void *)strNews.c_str());
}