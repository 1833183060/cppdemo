## 编译
### 1、通用环境
```
git clone git@github.com:1833183060/cppdemo.git
cd cppdemo
mkdir build
cd build
cmake ..
cmake --build .
```
### 2、win10+cmake+clang+ninja 环境
```
git clone git@github.com:1833183060/cppdemo.git
cd cppdemo
mkdir build
cd build
cmake .. -G Ninja
cmake --build .
```
注意：运行cmake时不能使用vs的命令行编译环境(即 *common prompt for VS)，否则有可能会出错。
### 3、