/***************************************************************** 
* Copyright (C) 2017 鸟哥  All rights reserved
* filename: 
* description：测试xalloc.
* author: 鸟哥
* see：https://en.cppreference.com/w/cpp/io/ios_base/xalloc
* see:https://en.cppreference.com/w/cpp/io/ios_base/iword
*********************************************************************/

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
    int i1=iostream::xalloc();
    cout<<__LINE__<<":"<<i1<<endl;
    cout<<ios::xalloc()<<endl;
    cout<<ios::xalloc()<<endl;
    cout<<ios::xalloc()<<endl;
    cout.pword(i1)=const_cast<char*>("fffff");
    cout<<static_cast<const char*>(cout.pword(i1))<<endl;

    cout.pword(4)=const_cast<char*>("asasd");
    //cout<<static_cast<const char*>(cout.pword(4))<<endl;
    cout<<(cout.pword(4)==0)<<endl;
    int i4=stringstream::xalloc();
    stringstream io1;
    cout<<i4<<endl;
    cout<<io1.iword(i4)<<endl;
    io1.iword(i4)=35;
    cout<<io1.iword(i4)<<endl;
    cin.get();
}