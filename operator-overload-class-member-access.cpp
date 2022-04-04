/***************************************************************** 
* Copyright (C) 2017 鸟哥  All rights reserved
* filename: 
* description：重载 运算符 -> (类成员访问).
* author: 鸟哥
* see：https://www.tutorialspoint.com/cplusplus/class_member_access_operator_overloading.htm
* see:https://en.cppreference.com/w/cpp/language/operators
*********************************************************************/

#include <iostream>
#include <string>
using namespace std;
class Tree{
public:
    Tree(){
    }
    void foo(){
        cout<<"Tree::foo()"<<endl;
    }
private:    
};
//1、简单的例子
class Handle{
public:
    Handle(Tree* t):tree(t){

    }
    Tree* operator->(){
        return tree;
    }
private:
    Tree* tree;
};
//2、使用类模板的例子
template<typename T>
class HandleT{
public:
    HandleT(T* o):obj(o){
    }
    T* operator->(){
        return obj;
    }
private:
    T* obj;
};

int main(){
    Tree t;    
    Handle handle{&t};
    HandleT<Tree> handleT{&t};
    handle->foo();//此处相当于调用 handle.operator->()->foo()
    handleT->foo();
    cout<<"------------------------------"<<endl;
    
    cout<<"enter any key to exit";
    cin.get();
}