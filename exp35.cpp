#include<iostream>
using namespace std;
class A{
    public:
    int a;
    A(){a = 7;}
    void sum(){
        cout << "Sum = " << a+a;
    }
};
class B{
    public:
    int b,c;
    B(){b = 9;
    c = 3;
    }
    void sub(){
        cout << "Difference = " << b-c<<endl;;
    }
};
class C : public A , public B{  
};
int main(){
    C obj1;
    obj1.sum();
    cout << "\n";
    C obj2;
    obj2.sub();
}