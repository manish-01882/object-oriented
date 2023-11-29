#include<iostream>
using namespace std;
class A{
    public:
    void fun(){
        cout<<"I am in A\n";
    }
};
class B : virtual public A{};
class C : virtual public B{};
class D : virtual public C{};
int main(){
    D obj;
    obj.fun();
}