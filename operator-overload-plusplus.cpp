#include <iostream>
using namespace std;

class Circle{
    private:
        int radius;
    public:
        Circle(int r){
            radius=r;
        }
        //前缀++，即 ++circle
        Circle& operator++(){
            ++radius;
            return *this;
        }
        Circle operator++(int){
            Circle circle(radius);
            ++radius;
            return circle;
        }
};

int main(){
    cin.get();
}