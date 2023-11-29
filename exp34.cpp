#include<iostream>
using namespace std;
class A{
    public:
    void fun(){
        cout <<"Multilevel Inheritance";
    }
};
class B : public A{
    public:
    void display(){
        cout <<"Derived Class\n";
    }
};
class C : public B{
};
int main(){
    C obj;
    obj.fun();
    cout<< "\n";
    obj.display();
}