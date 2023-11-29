#include<iostream>
using namespace std;
class A{
    public:
    void a1()
    {
        cout <<"class A";
    }
};
class B : public A{
    public:
    void b1(){
        cout << "class B";
    }
} ;
class C : public A{
    public:
    void c1(){
        cout << "class C\n";
    }
};
int main(){
    cout << "Hierarchical Inheritance\n";
    B obj1;
    cout << "parent class A Derived class B\n";
    obj1.a1();
    cout<<"\n";
    obj1.b1();
    C obj2;
    cout << "\nparent class A Derived class C\n";
    obj2.a1();
    cout<<"\n";
    obj2.c1();
}