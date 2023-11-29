#include<iostream>
using namespace std;
class A{
    int x,y;
    public:
    A(){}
    A(int a, int b){
        x = a;
        y = b;
    }
    void display();
    A operator - (A a1){
        A a2;
        a2.x = x - a1.x;
        a2.y = y - a1.y;
        return a2;
    }
};
void A :: display(){
    cout << "\nx = "<<x<<"\ny = "<<y;
}
int main(){
    A obj1,obj2,obj3;
    obj1 = A(10,20),obj2 = A(5,6);
    obj3 = obj1 - obj2;
    obj1.display();
    obj2.display();
    obj3.display();
    cout << endl;
}