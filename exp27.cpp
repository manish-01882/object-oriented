#include<iostream>
using namespace std;
class A{
    int x1,x2,y1,y2,sum1,sum2;
    public:
    A(){}
    A(int a, int b, int c,int d){
        x1 = a;
        y1=b;
        x2 = c;
        y2=d;
    }
    A operator+ (A a){
        A w;
        w.sum1 = x1 + a.x2;
        w.sum2 = y1 + a.y2;
        cout << "Sum = "<<w.sum1<<"+i"<<w.sum2;
    }
    void display1(){
        cout << "num1 = "<<x1<<"+i"<<y1<<endl;
    }
    void display2(){
        cout << "num2 = "<<x2<<"+i"<<y2<<endl;
    }
};
int main(){
    A obj1,obj2,obj3;
    obj1 = A(4,5,0,0);
    obj2 = A(0,0,6,7);
    obj1.display1();
    obj2.display2();
    obj3 = obj1 + obj2;
    cout << endl;
}