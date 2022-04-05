/***************************************************************** 
* Copyright (C) 2017 鸟哥  All rights reserved
* filename: 
* description：重载 运算符 <<和>> (任意形式的输入输出运算符).
* author: 鸟哥
* see：https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm
* see:https://www.geeksforgeeks.org/operator-overloading-and-operator-in-a-linked-list-class/?ref=rp
* see:https://en.cppreference.com/w/cpp/language/operators
*********************************************************************/

#include <iostream>
#include <ostream>
#include <string>
using namespace std;
class Vector2d;
class Point2d{
    friend void operator<<(Point2d& p,Vector2d&v);
    friend void operator>>(Point2d& p,Vector2d& v);
public:
    Point2d(double x_,double y_):x(x_),y(y_){}
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
//1、使用友元函数
class Vector2d{
public:
    Vector2d(double x_,double y_):x(x_),y(y_){
    }
    double GetX() const{
        return x;
    }
    double GetY() const{
        return y;
    }
    //注意：即使在类的内部，函数声明前有friend的函数也不是类的成员函数
    //1、友元函数定义写在类的外部
    friend void operator<<(Point2d& p,Vector2d& v);
    //2、友元函数定义写在类的内部
    friend void operator>>(Point2d& p,Vector2d& v){
        v.x=p.x;
        v.y=p.y;
        return;
    }
private:
    double x=0;
    double y=0;    
};

void operator<<(Point2d& p,Vector2d& v){
    p.x=v.x;
    p.y=v.y;
}


int main(){
    Vector2d v{1.1,2.2}; 
    
    Point2d p{0,0};
    p<<v;
    cout<<"p=("<<p.GetX()<<","<<p.GetY()<<")"<<endl;
    
    Point2d p2{100,101};
    Vector2d v2{0,0};
    p2>>v2;
    cout<<"v2=("<<v2.GetX()<<","<<v2.GetY()<<")"<<endl;cout<<"------------------------------"<<endl;
    cout<<"enter any key to exit";
    cin.get();
}