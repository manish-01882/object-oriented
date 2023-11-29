#include<iostream>
using namespace std;
class A{
    public:
    virtual void print(){
        cout << "print base class";
    }
    void show(){
        cout << "Show base class";
    }
};
class B : public A{
    public:
    void print(){
        cout <<"print derived class";
    }
    void show(){
        cout<<"show derived class";
    }

};
int main(){
    A* a;
    B b;
    a = &b;
    a ->print();
    cout << endl;
    a -> show();
    cout << endl;
}