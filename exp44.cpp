#include<iostream>
using namespace std;
void check(int x,int y){
    try{
        if(y==0)
        throw y;
        else
        cout << "result : "<<x/y;
    }
    catch(int){
        cout<<"\nDivision not possible\n";
        throw;
    }
}
int main(){
    try{
        check(10,2);
        check(20,0);
    }
    catch(int){
        cout <<"Exception : divide by zero\n";
    }
}