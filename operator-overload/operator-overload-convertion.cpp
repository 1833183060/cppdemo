/***************************************************************** 
* Copyright (C) 2021 鸟哥  All rights reserved
* filename: 
* description：重载 类型转换运算符,包括隐式和显式
* author: 鸟哥
* see：https://stackoverflow.com/questions/4421706/what-are-the-basic-rules-and-idioms-for-operator-overloading#4421719
* see:https://en.cppreference.com/w/cpp/language/operators
*********************************************************************/

#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class Rational{//有理数
public:
    Rational(long n,long d):numerator(n),denominator(d){
        
    }
    //隐式类型转换
    operator double() const{
        return (double)numerator/denominator;
    }
    //显式类型转换
    explicit operator string()const{
        return to_string((double)numerator/denominator);
    }
private:
    long numerator;//分子
    long denominator;//分母
};
//求平方
double square(double d){
    return d*d;
}
string printRational(string r){
    return r;
}
int main(){
   
    Rational q(1,3);
    
    cout<<"implicit:(1/3)^2="<<square(q) <<endl;
    cout<<"implicit:(1/3)^2="<<square(static_cast<double>(q)) <<endl;
    //cout<<"explicit:1/3="<<printRational(q);//显示转换，不允许这么写
    cout<<"explicit:1/3="<<printRational(static_cast<string>(q))<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"enter any key to exit";
    cin.get();
}