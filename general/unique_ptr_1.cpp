//by 鸟哥 
//unique_ptr 判断是否为空
//有疑问请留言或加群 1032082534
#include <iostream>                             
#include <string>                                
#include <vector>                               
#include <iterator>                              
#include <algorithm> 
#include<memory>

//#include<string.h>
using namespace std;
class Test{
public:
    ~Test(){
        cout<<"~Test"<<endl;
    }
};
//方式1
void isNull1(unique_ptr<Test>& ptr){
    cout<<"方式1:"<<endl;
    if(ptr.get()==nullptr){
        cout<<"ptr is null"<<endl;
    }else{
        cout<<"ptr is not null"<<endl;
    }
}

//方式2
void isNull2(unique_ptr<Test>& ptr){
    cout<<"方式2:"<<endl;
    if(!ptr){
        cout<<"ptr is null"<<endl;
    }else{
        cout<<"ptr is not null"<<endl;
    }
}

//方式3
void isNull3(unique_ptr<Test>& ptr){
    cout<<"方式3:"<<endl;
    if(!ptr.operator bool()){
        cout<<"ptr is null"<<endl;
    }else{
        cout<<"ptr is not null"<<endl;
    }
}

//方式4
void isNull4(unique_ptr<Test>& ptr){
    cout<<"方式4:"<<endl;
    if(ptr==nullptr){
        cout<<"ptr is null"<<endl;
    }else{
        cout<<"ptr is not null"<<endl;
    }
}

int main()
{  
    //方式1
    Test* test=new Test();
    unique_ptr<Test> ptr1(test);
    unique_ptr<Test> nullPtr1;
    isNull1(ptr1);
    isNull1(nullPtr1);

    //方式2
    isNull2(ptr1);
    isNull2(nullPtr1);

    //方式3
    isNull3(ptr1);
    isNull3(nullPtr1);

    //方式4
    isNull4(ptr1);
    isNull4(nullPtr1);
}


