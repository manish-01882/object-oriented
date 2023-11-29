#include<iostream> //39
using namespace std;
class A{
public:
void func(){
    cout << "I am in class A" << endl;
}
};
// Base class B
class B{
public:
void func(){ cout << "I am in class B" << endl;}
};
// Derived class C
class C : public A, public B{};
// Driver Code

int main(){
// Created an object of class c
C obj;
// calling function func()
obj.A::func();
return 0;
}