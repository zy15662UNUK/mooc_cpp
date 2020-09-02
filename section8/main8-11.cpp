#include "iostream"
#include "string"
using namespace std;

class LegacyRectangle
{
private:
    double _x1, _y1, _x2, _y2;
public:
    LegacyRectangle(double x1, double y1, double x2, double y2)
    {
        _x1 = x1;
        _y1 = y1;
        _x2 = x2;
        _y2 = y2;
    }
    void LegacyDraw() 
    {
        cout << " LegacyRectangle::LegacyDraw() " << _x1 << " " << _y1 << " " <<_x2 << " "<< _y2 << " " << endl;
    }

};

class Retangle
{
private:
public:
    virtual void draw(string str) = 0;
};

// 第一种适配方式：使用多重继承
class RectangleAdapter: public Retangle, public LegacyRectangle
{
private:
    /* data */
public:
    RectangleAdapter(double x, double y, double w, double h):LegacyRectangle(x, y, x + w, y + h)
    {
        cout << "RectangleAdapter(int x, int y, int w, int h)" << endl;
    }

    virtual void draw(string str)
    {
        cout << "RectangleAdapter::draw" << endl;
        LegacyDraw();
    }
};

// 第二种实现方式 组合方式
class RectangleAdapter2:public Retangle
{
private:
    LegacyRectangle _lRect;
public:
    RectangleAdapter2(double x, double y, double w, double h) : _lRect(x, y, x + w, y + h)
    {
        cout << "RectangleAdapter2(int x, int y, int w, int h)" << endl;
    }

    virtual void draw(string str)
    {
        cout << "RectangleAdapter2::draw" << endl;
        _lRect.LegacyDraw();
    }
};



int main()
{
    double x = 20.0, y = 50.0, w = 300.0, h = 200.0;
    RectangleAdapter ra(x, y, w, h);
    // 适配客户的接口。
    Retangle * pR = &ra;
    pR->draw("ssss");

    cout << endl;
    RectangleAdapter2 ra2(x, y, w, h);
    // 适配客户的接口。
    Retangle *pR2 = &ra2;
    pR2->draw("ssss");

    return 0;
}
