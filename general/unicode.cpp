/***************************************************************** 
* Copyright (C) 2022 鸟哥  All rights reserved
* filename: 
* description：演示 unicode
* author: 鸟哥
* see：
*********************************************************************/

#include <clocale>
#include <iostream>
#include <locale.h>
#include <windows.h>
int main()
{
    char square[4];
    square[2]=0x00;
    square[0]=0x4f;
    square[1]=0x60;
    square[3]=0;
    std::setlocale(LC_ALL,"");
    //SetConsoleOutputCP(65001);
    std::cout<<std::string("\u4f60")<<std::endl;
}