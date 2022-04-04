/***************************************************************** 
* Copyright (C) 2017 鸟哥  All rights reserved
* filename: 
* description：重载 运算符 +
* author: 鸟哥
* see：
*********************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
//1、相同类相加
class Vector{
public:
    Vector(double x_,double y_){
        x=x_;
        y=y_;
    }
    Vector operator+(const Vector& target){
        Vector vec(x+target.x,y+target.y);
        return vec;
    }
    double GetX() const{
        return x;
    }
    double GetY() const{
        return y;
    }
private:
    double x;
    double y;
};
//2、不同类相加
class Circle{
public:
    int GetRadius(){
        return radius;
    }
public:
    Circle(int r){
        radius=r;
    }
    Circle& operator+(int r){
        radius+=r;
        return *this;
    }
private:
    int radius;
};
//3、重载函数为非成员函数
class Segment{
public:
    Segment(double s,double e){
        start=s;
        end=e;
    }
    double GetStart() const{
        return start;
    }
    double GetEnd() const{
        return end;
    }
private:
    double start;
    double end;
};
Segment operator+(const Segment& s1,const Segment& s2){
    Segment seg(min(s1.GetStart(),s2.GetStart()),max(s1.GetEnd(),s2.GetEnd()));
    return seg;
}
///////////////
int main(){
    Vector vec1(1,0);
    Vector vec2(0,1);
    Vector vec3=vec1+vec2;
    cout<<"vec1:x="<<vec1.GetX()<<",y="<<vec1.GetY()<<endl;
    cout<<"vec2:x="<<vec2.GetX()<<",y="<<vec2.GetY()<<endl;
    cout<<"vec1+vec2:x="<<vec3.GetX()<<",y="<<vec3.GetY()<<endl;
    Circle circle(2);
    cout<<"circle's radius is:"<<circle.GetRadius()<<endl;
    Circle circle2=circle+2;
    cout<<"(circle+2)'s radius is:"<<circle2.GetRadius()<<endl;

    Segment seg1(1,2);
    Segment seg2(3,4);
    Segment seg3=seg1+seg2;
    cout<<"seg1:start="<<seg1.GetStart()<<",end="<<seg1.GetEnd()<<endl;
    cout<<"seg2:start="<<seg2.GetStart()<<",end="<<seg2.GetEnd()<<endl;
    cout<<"seg3:start="<<seg3.GetStart()<<",end="<<seg3.GetEnd()<<endl;
    cout<<"enter any key to exit";
    cin.get();
}