//by 鸟哥 
//unique_ptr 初始化
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

int main()
{  
    //方式1
    Test* test=new Test();
    unique_ptr<Test> testPtr(test);

    //方式2
    Test* test2=new Test();
    unique_ptr<Test> testPtr2=unique_ptr<Test>(test2);

    //方式3
    Test* test3=new Test();
    unique_ptr<Test> testPtr3=unique_ptr<Test>(test3);

    //方式4    
    unique_ptr<Test> testPtr4=make_unique<Test>();

}


