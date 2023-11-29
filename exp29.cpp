#include<iostream>
using namespace std;
class time1{
    int hour ,min;
    public:
    time1(){
        hour =0;
        min =0;
    }
    time1(int t){
        hour = t/60;
        min = t%60;
    }
    void display(){
        cout <<"time= "<<hour<<" hour and "<<min<<"min\n";
    }
};
int main(){
    int d = 75;
    time1 t;
    t = d;
    t.display();
}