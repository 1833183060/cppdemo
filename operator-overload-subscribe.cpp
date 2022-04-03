/***************************************************************** 
* Copyright (C) 2017 鸟哥  All rights reserved
* filename: 
* description：重载 运算符 [](下标运算符)
* author: 鸟哥
* see：https://www.tutorialspoint.com/cplusplus/subscripting_operator_overloading.htm
*********************************************************************/

#include <iostream>
#include <string>
using namespace std;
class Water{};
class Tree{
public:
    Tree(){
    }
    double operator[](const string& key){        
        return atof(key.c_str());
    }
    int operator[](int i){
        return i*i;
    }
    string operator[](const Water* w){
        return "water";
    }
private:
    
};



int main(){
    Tree t;    
    
    cout<<"t[\"1.1\"]="<<t["1.1"]<<endl;
    cout<<"t[2]="<<t[2]<<endl;
    Water w;
    cout<<"t[Water*]="<<t[&w]<<endl;
    cout<<"------------------------------"<<endl;
    
    cout<<"enter any key to exit";
    cin.get();
}