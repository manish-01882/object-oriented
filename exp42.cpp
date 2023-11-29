#include<iostream>
using namespace std;
void outside(int d){
    throw(d);
}
int main(){
    int a,b,c;
    cout << "Enter the value of a : ";
    cin >> a;
    cout << "Enter the value of b : ";
    cin >> b;
    c = a - b;
    try{
        if(c != 0){
            cout << "result : "<< a/c <<endl;
        }
        else {
            outside(c);
        }
    }
    catch(int i){
        cout << "Exception : divisible by zero\n";
    }
}