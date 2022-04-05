/***************************************************************** 
* Copyright (C) 2017 鸟哥  All rights reserved
* filename: 
* description：重载 运算符 , (逗号运算符).
* author: 鸟哥
* see：https://www.geeksforgeeks.org/overloading-the-comma-operator/?ref=rp
* see:https://en.cppreference.com/w/cpp/language/operators
*********************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class MyVector{
    
public:
    MyVector(){}
    void append(int i){
        data.push_back(i);
    }
    //将this的数据合并到other中，并返回other的引用
    //注意：本函数只为演示如何重载逗号运算符，不代表实际应用中的最佳实践。
    MyVector& operator,(MyVector& other)const{
        other.data.insert(other.data.end(),data.begin(),data.end());
        return other;
    }
    void print(){
        for(auto iter=data.begin();iter!=data.end();++iter){
            cout<<*iter<<" ";
        }
        cout<<endl;
    }
private:
    vector<int> data;
};



int main(){
    MyVector v1; 
    v1.append(3);
    v1.append(5);
    MyVector v2;
    v2.append(2);
    v2.append(1);
    MyVector v3;
    v3.append(20);
    v3.append(10);
    MyVector& v4=(v1,v2,v3);//将v1 v2的数据合并到v3中;
    cout<<"v1:";
    v1.print();
    cout<<"v2:";
    v2.print();
    cout<<"v3:";
    v3.print();
    cout<<"v4:";
    v4.print();
    cout<<"------------------------------"<<endl;
    cout<<"enter any key to exit";
    cin.get();
}