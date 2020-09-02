#include "./include/Singleton.h"
Singleton *Singleton::This = new Singleton();
const Singleton *Singleton::getInstance()
{
    if (!This) 
    {
        This = new Singleton();
    }
    return This;
}

Singleton::Singleton(/* args */)
{
}

Singleton::~Singleton()
{
}
void Singleton::doingSomeThing()
{
    cout << "doing something" << endl;
}