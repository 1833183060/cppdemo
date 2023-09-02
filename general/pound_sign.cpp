/***************************************************************** 
* Copyright (C) 2022 鸟哥  All rights reserved
* filename: 
* description：演示 井号
* author: 鸟哥
* see：
*********************************************************************/
// # 和 ## 的用法总结
//by 鸟哥 (qq群 1032082534)
//参考：https://en.cppreference.com/w/cpp/preprocessor/replace
//参考：https://blog.csdn.net/Andy_93/article/details/111727490

#include <iostream>

#define Stringizing1(a) #a
#define Stringizing2(...) puts(#__VA_ARGS__)
#define Concatenation1(pre) pre##s("ccc")
#define Concatenation2(templt, ...) puts(templt, ##__VA_ARGS__)

void puts(){
    std::cout<<"null"<<std::endl;
}
void puts(std::string s){
    std::cout<<s<<std::endl;
}
void puts(int i){
    std::cout<<2*i<<std::endl;
}
void puts(int i,int j){
    std::cout<<i*j<<std::endl;
}
void puts(int i,int j,int k){
    std::cout<<i*j*k<<std::endl;
}
int main()
{
    //# 用法1
    std::cout<<"#用法1："<<std::endl;
    std::cout<<Stringizing1()<<std::endl;       // 展开为
    std::cout<<Stringizing1("")<<std::endl;     // 展开为 ""
    std::cout<<Stringizing1(aa)<<std::endl;     // 展开为 "aa"
    //# 用法2
    std::cout<<std::endl;
    std::cout<<"#用法2："<<std::endl;
    Stringizing2();            // 展开为 puts("")
    Stringizing2("");            // 展开为 puts("\"\"")
    Stringizing2(aa);            // 展开为 puts("aa")
    Stringizing2(1, "x", int); // 展开为 puts("1, \"x\", int")
    //## 用法2
    std::cout<<std::endl;
    std::cout<<"##用法2："<<std::endl;
    Concatenation1(put);       //展开为 puts("ccc")
    
    std::cout<<std::endl;
    std::cout<<"##用法2："<<std::endl;
    Concatenation2(2);       //展开为 puts(2) 
    Concatenation2(2,3);       //展开为 puts(2,3)  
    Concatenation2(2,3,4);       //展开为 puts(2,3,4)  
}