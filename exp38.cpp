#include<iostream>
using namespace std;
class A{
    public:
    void fun(){
        cout<<"I am in A";
    }
};
class B{
    public:
    void fun(){
        cout<<"I am in B\n";
    }
};
class C : public A, public B{};
int main(){
    C obj;
    obj.A::fun();
    cout << "\n";
    obj.B::fun();
}