/***************************************************************** 
* Copyright (C) 2022 鸟哥  All rights reserved
* filename: 
* description：演示 const/non-const overrides
* author: 鸟哥
* see：https://www.cplusplus.com/forum/general/112609/
*********************************************************************/

#include <iostream>

class A
{
    public:
    void foo()
    {
        std::cout << "A::foo() "<<std::endl ;
    }

    void foo() const
    {
        std::cout << "A::foo() const " <<std::endl;
    }

    void foo() volatile
    {
        std::cout << "A::foo() volatile "<<std::endl ;
    }

    void foo() const volatile 
    { 
        std::cout << "A::foo() const volatile"<<std::endl ;
    }
};

int main()
{
    A a ;
    a.foo() ; // A::foo() 
    const A& ca = a ;
    ca.foo() ; // A::foo() const 

    volatile A& va = a ;
    va.foo() ; // A::foo() volatile 

    const volatile A& cva = a ;
    cva.foo() ; // A::foo() const volatile
}