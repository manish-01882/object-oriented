#include<iostream>
using namespace std;
int main(){
    int a[5]= {22,33,44,55,66};
    cout << "Initial values of array : \n";
    for(int i=0;i<5;i++){
        cout << a[i]<<",";
    }
    cout << "\n";
    int *p = a;
    cout << "Value of pointer (p):"<< *p << endl;
    cout << "p++ : "<<*(++p)<<endl;
    cout << "p-- : "<<*(--p)<<endl;
    cout << "p+2 : "<<*(p+2)<<endl;
    cout << "p+=4 : "<<*(p+=4)<<endl;
    cout << "p-1: "<<*(p-1)<<endl;
    cout << "p-=1 : "<<*(p-=1)<<endl;
}