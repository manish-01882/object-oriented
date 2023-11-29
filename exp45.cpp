#include<iostream>
using namespace std;
void find(int x){
    try{
        if(x==0)throw x;
        if(x==1)throw 'x';
        if(x== -1)throw 1.0;
    }
    catch (...){
        cout << "Exception ! \n";
    }
}
int main(){
    find(0);
    find(1);
    find(-1);
}