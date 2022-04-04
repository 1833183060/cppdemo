/***************************************************************** 
* Copyright (C) 2017 鸟哥  All rights reserved
* filename: 
* description：重载 运算符 !(逻辑非)
* author: 鸟哥
see：https://www.tutorialspoint.com/cplusplus/unary_operators_overloading.htm
*********************************************************************/

#include <iostream>
#include <math.h>
using namespace std;
//1、重载函数为成员函数
class Vector{
public:
    Vector(double x_,double y_){
        x=x_;
        y=y_;
    }
    Vector& operator!(){
        x=-x;
        y=-y;
        return *this;
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

//2、重载函数为非成员函数
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
    void SetStart(double s){
        start=s;
    }
    void SetEnd(double e){
        end=e;
    }
private:
    double start;
    double end;
};
//注意：返回值可以为 void
void operator!(Segment& s1){
    double oldStart=s1.GetStart();
    s1.SetStart(-(s1.GetEnd()));
    s1.SetEnd(-(oldStart));
    return ;
}
int main(){
    Vector vec1(1,2);    
    cout<<"vec1:x="<<vec1.GetX()<<",y="<<vec1.GetY()<<endl;
    !vec1;
    cout<<"!vec1:x="<<vec1.GetX()<<",y="<<vec1.GetY()<<endl;
    cout<<"------------------------------"<<endl;
    Segment seg1(1,2);
    
    cout<<"seg1:start="<<seg1.GetStart()<<",end="<<seg1.GetEnd()<<endl;
    !seg1;
    cout<<"!seg1:start="<<seg1.GetStart()<<",end="<<seg1.GetEnd()<<endl;
    cout<<"enter any key to exit";
    cin.get();
}