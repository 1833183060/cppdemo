/***************************************************************** 
* Copyright (C) 2022 鸟哥  All rights reserved
* filename: 
* description：可变参数模板
* author: 鸟哥
* see：https://en.cppreference.com/w/cpp/language/parameter_pack
* see: https://en.cppreference.com/w/cpp/language/sizeof...
* see: https://en.cppreference.com/w/cpp/language/template_parameters#Template_template_arguments
*********************************************************************/

#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>
#include <array>
using namespace std;
//以下函数来自 cgal-v5.3\STL_Extension\include\CGAL\array.h
template< typename T, typename... Args >
std::array< T, 1 + sizeof...(Args) >
make_array(const T & t, const Args & ... args)
{
  std::array< T, 1 + sizeof...(Args) > a = { { t, static_cast<T>(args)... } };
  return a;
}
int main(){
    auto arr=make_array(1.1,1.2,1.3,1.4);
    cout<<"arr:"<<endl;
    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //上面的代码等价于：
    array<double,4> arr2{1.1,1.2,1.3,1.4};
    cout<<"arr2:"<<endl;
    for(int i=0;i<arr2.size();++i){
        cout<<arr2[i]<<" ";
    }
    cin.get();
}