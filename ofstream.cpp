//This program creates a fle called "Message.dat"
#include <fstream> // Required for fle I/O
#include<iostream>
using namespace std;
int main()
{
ofstream myfle ("message.dat");
if (!myfle)
{ // check if the fle is opened or not
cout << "\n Cannot open this fle .." ;
return 1;
}
myfle << "\n When you feel angry, keep your mouth shut.\n";
myfle << "Don’t talk and your anger will be ffty percent gone.\n";
myfle << "Drink some cold water and it will be seventy fve\n";
myfle << "percent gone. Get out of the house and take a walk\n";
myfle << "and it will be one hundred percent gone.";
myfle.close(); //close the fle
return 0;
}