#include "./include/String.h"
#include "iostream"
using namespace std;

class Shape 
{
public:
    virtual double area() const {return 0;} // virtual method can be overwritten by the inherited class;
    void display()
    {
        cout << area() << endl;
    }
};

class Square:public Shape
{
public:
    Square(double len):_len(len){}
    double area() const
    {
        return _len * _len;
    }

private:
    double _len;

};
// inherite public method
class Circle:public Shape
{
public:
    Circle(double radius):_radius(radius){}
    double area() const
    {
        return _radius * _radius * 3.14;
    }

private:
    double _radius;

};

class Triangle : public Shape
{
public:
    Triangle(double len, double height) : _len(len),_height(height) {}
    double area() const
    {
        return _height * _len * 0.5;
    }

private:
    double _len;
    double _height;
};
int main()
{
    Square s1(2.0);
    Circle s2(2.0);
    Triangle s3(4.9, 8.0);
    Shape * shapes[3] ={&s1, &s2, &s3};
    for (int i = 0; i < sizeof(shapes)/sizeof(shapes[0]); i ++)
    {
        shapes[i]->display();
    }
    return 0;
}