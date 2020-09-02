#ifndef OBSEVER_H_1
#define OBSEVER_H_1
class Observer
{
private:
    /* data */
public:
// 单纯为了编译通过加上大括号
    Observer(/* args */) {;};
    virtual ~Observer(){;};
    // 当被观察对象发生变化时候，通知被观察者调用这个方法
    virtual void update(void * pArg) = 0;
};
#endif