#include<iostream>
using namespace std;
class A{
    public:
    void fun(){
        cout << "Single inheritance\n";
    }

};
class B: public A{
};
int main(){
    B obj;
    obj.fun();
}