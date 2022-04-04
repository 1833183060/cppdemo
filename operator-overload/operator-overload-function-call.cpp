/***************************************************************** 
* Copyright (C) 2017 鸟哥  All rights reserved
* filename: 
* description：重载 运算符 () (函数调用运算符).
* author: 鸟哥
* see：
* see:https://en.cppreference.com/w/cpp/language/operators
*********************************************************************/

#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class CurrencyConverter{//汇率换算
public:
    CurrencyConverter(double r){
        rate=r;
    }
    double operator()(double amount){
        return rate*amount;
    }
private:
    double rate;  //美元对人民币的汇率 
};


int main(){
   
    CurrencyConverter c(6.36);
    double USD=1.2;
    cout<<"$"<<USD<<"="<<c(USD)<<"RMB" <<endl;
    cout<<"------------------------------"<<endl;
    cout<<"enter any key to exit";
    cin.get();
}