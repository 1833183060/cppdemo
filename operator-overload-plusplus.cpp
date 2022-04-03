/***************************************************************** 
* Copyright (C) 2017 鸟哥  All rights reserved
* filename: 
* description：重载 ++运算符
* author: 鸟哥
see：https://www.tutorialspoint.com/cplusplus/increment_decrement_operators_overloading.htm
*********************************************************************/

#include <iostream>
using namespace std;

class Circle{
    private:
        int radius;
    public:
        int GetRadius(){
            return radius;
        }
    public:
        Circle(int r){
            radius=r;
        }
        //前缀++，即 ++circle
        Circle& operator++(){
            ++radius;
            return *this;
        }
        Circle operator++(int){
            Circle circle(radius);
            ++radius;
            return circle;
        }
};

int main(){
    Circle circle(2);
    cout<<"circle's radius is:"<<circle.GetRadius()<<endl;
    cout<<"++circle's radius is:"<<(++circle).GetRadius()<<endl;
    cout<<"circle's radius after ++circle  is:"<<circle.GetRadius()<<endl;

    cout<<"circle++'s radius is:"<<circle++.GetRadius()<<endl;
    cout<<"circle's radius after circle++ is:"<<circle.GetRadius()<<endl;
    cout<<"enter any key to exit";
    cin.get();
}