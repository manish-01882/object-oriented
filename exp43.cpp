#include<iostream>
using namespace std;
void check(int x){
    try{
        if(x>0)
        throw(x);

        else
        throw 'x';
    }
    catch (int i){
        cout << "given number is integer : " << i;
    }
    catch(char i){
        cout << "given number is character : " << i;
    }
    
}
int main(){
    check(10);
    cout << "\n";
    check(0);
    cout << endl;
}