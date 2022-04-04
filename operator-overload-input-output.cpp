/***************************************************************** 
* Copyright (C) 2017 鸟哥  All rights reserved
* filename: 
* description：重载 运算符 <<和>> (输入输出运算符).
* author: 鸟哥
* see：https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm
* see:https://www.geeksforgeeks.org/operator-overloading-and-operator-in-a-linked-list-class/?ref=rp
* see:https://en.cppreference.com/w/cpp/language/operators
*********************************************************************/

#include <iostream>
#include <ostream>
#include <string>
using namespace std;
//1、使用友元函数
class Vector2d{
public:
    Vector2d(){
    }
    //注意：即使在类的内部，函数声明前有friend的函数也不是类的成员函数
    //1、友元函数定义写在类的外部
    friend ostream& operator<<(ostream& os,Vector2d& v);
    //2、友元函数定义写在类的内部
    friend istream& operator>>(istream& is,Vector2d& v){
        cin>>v.x>>v.y;
        return is;
    }
private:
    double x=0;
    double y=0;    
};

ostream& operator<<(ostream& os,Vector2d& v){
    os<<"vector:("<<v.x<<","<<v.y<<")";
    return os;
}
//2、不使用友元函数
class Point2d{
public:
    double GetX() const{
        return x;
    }
    double GetY() const{
        return y;
    }
private:
    double x=0;
    double y=0;
};
ostream& operator<<(ostream& os,const Point2d& p){
    os<<"point:("<<p.GetX()<<","<<p.GetY()<<")";
    return os;
}

int main(){
    Vector2d v;  
    cout<<v<<endl;
    cin>>v;
    cout<<v<<endl;
    
    Point2d p;
    cout<<p<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"enter any key to exit";
    cin.get();
}