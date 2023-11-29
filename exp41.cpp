#include<iostream>
using namespace std;
int main(){
    int a, b, c;
    cout << "Enter value of a : ";
    cin >> a;
    cout << "Enter value of b : ";
    cin >> b;
    c = a - b;
    try{
        if(c != 0){
            cout << "result : " << a/c << endl;
        }
        else{
            throw(c);
        }
    }
    catch(int i){
        cout << "Exception : division by zero\n";
    }
}