// StringAndCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>                             
#include <string>                                
#include <vector>                               
#include <iterator>                              
#include <algorithm> 
#include<stdio.h>

//#include<string.h>
//#include <bitset>
//#include <cstddef>
using namespace std;
void stringAndByte()
{

    //string 转 byte指针：
    std::string str("你好啊");
    std::cout << str << std::endl;
    std::byte* px = (byte*)str.c_str();
    int len = str.length();

    std::cout << len << endl;
    std::cout << sizeof(px) << endl;
    for (int i = 0; i < len; ++i) {
        unsigned int a = (unsigned int)px[i];
        cout << a << " ";
        cout << (unsigned int)px[i] << " ";
    }
    cout << endl;
    char* p = new char[sizeof(px) + 2];
    memcpy(p, px, sizeof(px) + 1);
    for (int i = 0; i < len; ++i) {
        int ii = (int)p[i];
        cout << ii << " ";
        
        unsigned int a = (unsigned int)p[i];
        cout << a << " ";
        cout <<static_cast<unsigned int>(p[i]) << " ";
    }
    //p[sizeof(px)] = 0;
    p[sizeof(px) + 1] = 0;
    string str2(p);
    cout << str2 << endl;

    std::string s(reinterpret_cast<const char*>(p), len);
    cout << s << endl;
    //byte指针转string：
    std::string s2(reinterpret_cast<const char*>(px), len);
    std::cout << s2 << std::endl;
}


int main()
{
    stringAndByte();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
